#include "stdlib.h"
#include "camera_info.h"
#include "math.h"
#include "conf.h"
#include "viewport.h"
#include "shooting.h"
#include "modes.h"
#include "lens.h"
#include "fileutil.h"


//-------------------------------------------------------------------
// AUTO ISO

//////////////////////////////////////////////////////////////////////////////////////////////
// @tsv
// Module below calculate live histogram in same way as OSD histogram
// Difference from shot_histogram family is that live_histogram give answer before shot
// Regular histogram_process cannot be used, because raw non-summarized 0.255 values required
// This module is used in AutoISO2 mechanizm.
//////////////////////////////////////////////////////////////////////////////////////////////

// Define how many viewport blocks to step in each loop iteration. Each block is 6 bytes (UYVYYY) or 4 image pixels
#define	HISTO_STEP_SIZE	6
#define OVEREXPOSURE_EV_AUTO 7

static unsigned short live_histogram_proc[256]; // Buffer for histogram

int clip192(int x)
{
    if (x<0) x=0;
    else if (x>192) x=192;
    return x;
}

int calculate_ev_auto(int range, int threshold, int yover, int ev_bias)
{
    if ((threshold < 3) || (yover == 0))
    {
        return 0;
    }

    int i, j;
    int levels[4][2];
    levels[0][0] = 0;
    levels[0][1] = 0;

    int partial_threshold = threshold / 3;
    int partial_ev = yover % 4;

    for (i = 1; i < 4; i++)
    {
        levels[i][0] = i * partial_threshold;
        levels[i][1] = i + partial_ev;
    }

    if (range > levels[3][0])
    {
        return clip192((levels[3][1] << 5) + ev_bias);
    }

    for (j = 2; j >= 0; j--)
    {
        if ((range <= levels[j+1][0]) && (range > levels[j][0]))
        {
            return clip192((levels[j][1] << 5) + ev_bias);
        }
    }

    return 0;
}

/*
build histogram of viewport Y values (downsampled by HISTO_STEP_SIZE)
NOTE also used by lua get_live_histo
*/
int live_histogram_read_y(unsigned short *h)
{
    int total;

    int vp_width = vid_get_viewport_width();
    int vp_height = vid_get_viewport_height();
    int vp_offset = vid_get_viewport_row_offset();

    total = (vp_width * vp_height) / (HISTO_STEP_SIZE * 2);
    memset(h, 0, sizeof(unsigned short)*256);

    unsigned char *img = vid_get_viewport_active_buffer();
    if (!img) return total;

    img += vid_get_viewport_image_offset() + 1;

    int y;
    for (y=0; y<vp_height; y++, img += vp_offset)
    {
        int x;
        for (x=0; x<vp_width; x += HISTO_STEP_SIZE*2, img+=HISTO_STEP_SIZE*6)
        {
            ++h[*img];
        }
    }

    return total;
}

static int live_histogram_get_range(int total,int from, int to)
{
    if (from < 0) from = 0;
    if (to > 255) to = 255;

    int rv = 0;
    for(; from<=to; from++)
        rv += live_histogram_proc[from];

    return (rv * 100) / total;
}

//-------------------------------------------------------------------

static const int shutter1_values[] = { 0, 2, 4, 6, 8, 15, 30, 60, 125, 250, 500, 1000, 2000 };
static const int shutter2_values[] = { 0, 1, 2, 4, 6, 8, 12, 15, 20, 25, 30, 40, 50, 60, 80, 100, 125, 160, 200, 250, 500, 1000, 2000 };
static const int iso_values[] = {80, 100, 125, 160, 200, 250, 320, 400, 500, 640, 800};

static void shooting_calc_autoiso_coef( int min_shutter )
{
    if (shutter2_values[conf.autoiso2_shutter_enum] >= min_shutter)
    {
        conf.autoiso2_coef = 0.0;
    }
    else
    {
        conf.autoiso2_coef = (float)(conf.autoiso2_max_iso_auto_real - conf.autoiso_max_iso_auto_real) /
                             (float)( shutter2_values[conf.autoiso2_shutter_enum] - min_shutter);
    }
}

static void shooting_recalc_conf_autoiso_values()
{
    // convert market to real iso
    conf.autoiso_max_iso_hi_real    = shooting_iso_market_to_real(iso_values[conf.autoiso_max_iso_hi]) ;
    conf.autoiso_max_iso_auto_real  = shooting_iso_market_to_real(iso_values[conf.autoiso_max_iso_auto]) ;
    conf.autoiso_min_iso_real	    = shooting_iso_market_to_real(iso_values[conf.autoiso_min_iso]) ;
    conf.autoiso2_max_iso_auto_real = shooting_iso_market_to_real(iso_values[conf.autoiso2_max_iso_auto]) ;

    // There are two exceptional situation:
    // 1. shutter_numerator2 should be < shutter_numerator1, otherwise exceptional situation
    // 2. autoiso2 <= autoiso1
    if ( !shutter2_values[conf.autoiso2_shutter_enum] )
        conf.autoiso2_max_iso_auto_real = conf.autoiso_max_iso_auto_real;

    // C2=( iso2_max_auto_real - iso_max_auto_real) / ( tv_num[autoiso2_shutter] - tv_numerator[autoiso_shutter])
    shooting_calc_autoiso_coef( shutter1_values[conf.autoiso_shutter_enum] );
}

void shooting_set_autoiso(int iso_mode)
{
    short max_iso;

    if (iso_mode<=0)
        shooting_recalc_conf_autoiso_values();

    switch (iso_mode)
    {
    case -1: // ISO HI
        //max_iso = conf.autoiso_max_iso_hi*10;
        max_iso = conf.autoiso_max_iso_hi_real;
        break;
    case 0: // ISO AUTO
        //max_iso = conf.autoiso_max_iso_auto*10;
        max_iso = conf.autoiso_max_iso_auto_real;
        break;
    default:
        return;
    }

    vars.auto_ev_ae_value = 0;

    // TODO also long shutter ?
    if (!(camera_info.state.mode_shooting==MODE_AUTO || camera_info.state.mode_shooting==MODE_P || camera_info.state.mode_shooting==MODE_AV))
        return; //Only operate inside of AUTO, P and Av

    int ev_overexp = 0;
    // No shoot_histogram exist here because no future shot exist yet :)
    int total = live_histogram_read_y(live_histogram_proc);
    int range = live_histogram_get_range(total,255-conf.autoiso2_over,255);

    if (conf.overexp_ev_enum)
    {

        if (conf.overexp_ev_enum != OVEREXPOSURE_EV_AUTO)
        {
            // step 32 is 1/3ev for tv96
            if (range >= conf.overexp_threshold)
            {
                ev_overexp = conf.overexp_ev_enum << 5;
                vars.auto_ev_ae_value = ev_overexp >> 5;
            }
        }
        else
        {
            int ev_bias = shooting_get_ev_correction1();
            ev_overexp = calculate_ev_auto(range, conf.overexp_threshold, conf.autoiso2_over, ev_bias);
            vars.auto_ev_ae_value = ev_overexp >> 5;
        }
    }

    vars.overexp_percent = range;

    float current_shutter = shooting_get_shutter_speed_from_tv96(shooting_get_tv96());

    short current_iso = shooting_get_iso_real();

    short min_shutter = shutter1_values[conf.autoiso_shutter_enum];
    if (min_shutter == 0)
    {
        short IS_factor = (shooting_get_is_mode()<=1)?conf.autoiso_is_factor:1;
        min_shutter = get_focal_length(lens_get_zoom_point())*conf.autoiso_user_factor / (IS_factor*1000);
        //min_shutter is NOT 1/Xs but optimized for the calculation.
        if (shutter2_values[conf.autoiso2_shutter_enum])
            shooting_calc_autoiso_coef( min_shutter );
    }

    short target_iso = current_iso * min_shutter * current_shutter;
    short min_iso = conf.autoiso_min_iso_real;

    if (target_iso > max_iso)
    {
        ev_overexp=0;
        vars.auto_ev_ae_value = 0;

        // AutoISO2 if
        // 	it is turned on (C2!=0.0)
        //	and it has valid iso2/shutter2 ( C2<0)
        //       and non-IsoHI mode
        if ( !iso_mode && conf.autoiso2_coef < 0.0 )
        {
            target_iso = (max_iso - min_shutter*conf.autoiso2_coef) / ( 1.0 - conf.autoiso2_coef  / (current_shutter * current_iso) );
            if ( target_iso > conf.autoiso2_max_iso_auto_real )
                target_iso = conf.autoiso2_max_iso_auto_real;
        }
        else
        {
            target_iso = max_iso;
        }
    }
    else if (target_iso < min_iso)
    {
        target_iso = min_iso;
    }

    float target_shutter = current_shutter *  current_iso / target_iso;

    if (target_shutter > 0)
        shooting_set_tv96_direct(shooting_get_tv96_from_shutter_speed(target_shutter) + ev_overexp, SET_NOW);

    shooting_set_iso_real(target_iso, SET_NOW);
}

//-------------------------------------------------------------------
