#include "camera_info.h"
#include "stdlib.h"
#include "conf.h"
#include "math.h"
#include "modes.h"
#include "viewport.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_osd.h"
#include "shooting.h"
#include "histogram.h"

//-------------------------------------------------------------------

#define HISTOGRAM_IDLE_STAGE        6

// Indexes into the various arrays for calculating the histogram channels
#define HISTO_R                     0       // Red channel
#define HISTO_G                     1       // Green channel
#define HISTO_B                     2       // Blue channel
#define HISTO_RGB                   3       // Combined Red, Green and Blue
#define HISTO_Y                     4       // Luminance (Y) from viewport

#define WAVE_L                     0       // Default Luminance (Y) from viewport
#define WAVE_R                     1       // Red channel
#define WAVE_G                     2       // Green channel
#define WAVE_B                     3       // Blue channel
#define WAVE_Y                     4       // Y channel
#define WAVE_U                     5       // U channel
#define WAVE_V                     6       // V channel
#define WAVE_S                     7       // Sat
#define WAVE_YS                    8       // Combined YS
#define WAVE_RGB                   9       // Combined RGB
#define WAVE_YUV                  10       // Combined YUV

#define PARADE_MODE_HORIZONTAL     0
#define PARADE_MODE_VERTICAL       1

#define PARADE_RGB                 1
#define PARADE_YUV                 2
#define PARADE_YS                  3


// Define type of transform to be done to scale the histogram to fit the available height
#define HISTO_MODE_LINEAR           0
#define HISTO_MODE_LOG              1

// Display modes
#define OSD_HISTO_LAYOUT_A           0       // A - RGB
#define OSD_HISTO_LAYOUT_Y           1
#define OSD_HISTO_LAYOUT_A_Y         2
#define OSD_HISTO_LAYOUT_R_G_B       3
#define OSD_HISTO_LAYOUT_Y_U_V       4
#define OSD_HISTO_LAYOUT_A_yrgb      5
#define OSD_HISTO_LAYOUT_Y_argb      6
#define OSD_HISTO_LAYOUT_BLEND       7
#define OSD_HISTO_LAYOUT_BLEND_Y     8
#define OSD_HISTO_LAYOUT_WAVE_Y      9
#define OSD_HISTO_LAYOUT_WAVE_YS    10
#define OSD_HISTO_LAYOUT_WAVE_RGB   11
#define OSD_HISTO_LAYOUT_WAVE_YUV   12
#define OSD_HISTO_LAYOUT_WAVE_VEC   13
#define OSD_HISTO_LAYOUT_PARD_YS    14
#define OSD_HISTO_LAYOUT_PARD_RGB   15
#define OSD_HISTO_LAYOUT_PARD_YUV   16


// Define how many viewport blocks to step in each loop iteration. Each block is 6 bytes (UYVYYY) or 4 image pixels
#define	HISTO_STEP_SIZE	6

static unsigned char histogram[5][HISTO_WIDTH];             // RGBYG
static unsigned short *histogram_proc[5] = { 0,0,0,0,0 };   // RGBYG (unsigned short is large enough provided HISTO_STEP_SIZE >= 3)
unsigned int histo_max[5], histo_max_center[5];             // RGBYG
static float histo_max_center_invw[5];                      // RGBYG
static short histogram_allocated = 0;

static unsigned char **waveform_proc;
static unsigned char **waveform;
static short waveform_allocated = 0;

static long histo_magnification;
static long under_exposed;
static long over_exposed;

static long histogram_stage=0;
static int waveform_stage=1;

//-------------------------------------------------------------------
// Histogram calculation functions

// Clip value to byte range (for YUV -> RGB conversion)
static int clip(int v)
{
    if (v<0) v=0;
    else if (v>255) v=255;
    return v;
}

static int clip50(int v)
{
    if (v<0) v=0;
    else if (v>50) v=50;
    return v;
}

int minrgb(int R, int G, int B)
{
  int min = 255;
  if (R < G) min = R;
  else min = G;
  if (B < min) min = B;
  return min;
}

int maxrgb(int R, int G, int B)
{
  int max = 0;
  if (R > G) max = R;
  else max = G;
  if (B > max) max = B;
  return max;
}

double saturation(int R, int G, int B)
{
    int max = maxrgb(R, G, B);
    int min = minrgb(R, G, B);
    if (max == 0) return 0.0;
    return (double) (max - min) / (double) max;
}

// Transform functions
static float identity(float x)
{
    return x;
}
static float logarithmic(float x)
{
    return log(x);
}

static void histogram_alloc()
{
    // Allocate arrays to store counts during processing
    // Each possible value is counted so the array sizes are set to 256, then these are summed to
    // convert down to desired width of 128.
    // This is faster than scaling each value as it is counted
    if (histogram_proc[0] == 0)
    {
        histogram_proc[0] = malloc(5 * 256 * sizeof(unsigned short));
        histogram_proc[1] = histogram_proc[0] + 256;
        histogram_proc[2] = histogram_proc[1] + 256;
        histogram_proc[3] = histogram_proc[2] + 256;
        histogram_proc[4] = histogram_proc[3] + 256;
        histogram_allocated = 1;
    }
}

static void histogram_free()
{
    histogram_proc[4] = 0;
    histogram_proc[3] = 0;
    histogram_proc[2] = 0;
    histogram_proc[1] = 0;
    free(histogram_proc[0]);
    histogram_proc[0] = 0;
    histogram_allocated = 0;
}

static void waveform_alloc()
{
    unsigned short c;
    // Allocate buffer to screen width / 3
    waveform_proc = malloc(120 * sizeof(unsigned char *));
    waveform = malloc(120 * sizeof(unsigned char *));
    for (c = 0; c < 120; c++)
    {
        waveform_proc[c] = malloc(3 * 48 * sizeof(unsigned char));
        memset(waveform_proc[c], 0, 3 * 48);
        waveform[c] = malloc(3 * 48 * sizeof(unsigned char));
        memset(waveform[c], 0, 3 * 48);
    }
    waveform_allocated = 1;
}

static void waveform_free()
{
    unsigned short c;
    for (c = 0; c < 120; c++)
    {
        free(waveform_proc[c]);
        waveform_proc[c] = NULL;
        free(waveform[c]);
        waveform[c] = NULL;
    }
    free(waveform_proc);
    waveform_proc = NULL;
    free(waveform);
    waveform = NULL;
    waveform_allocated = 0;
}

static void waveform_clear()
{
    unsigned short c;
    for (c = 0; c < 120; c++)
    {
        memset(waveform_proc[c], 0, 3 * 48);
    }
}

static void waveform_copy()
{
    unsigned short c;
    for (c = 0; c < 120; c++)
    {
        memcpy(waveform[c], waveform_proc[c], 3 * 48 * sizeof(unsigned char));
    }
}

static void do_waveform_process()
{
    static unsigned char *img_buf;
    static int viewport_size, viewport_width, viewport_height,
           viewport_row_offset, wiewport_byte_width;
    register int v, x, y, px, py;
    int step_v, step_x, step_y;
    register int Y, U, V, R, G, B, S;

    //initialize variables
    viewport_width = camera_screen.width;
    viewport_height = vid_get_viewport_height();
    int exposition_thresh = conf.histo_ignore_boundary;
    histo_magnification = 0;
    step_v = 3;
    step_x = 3;
    step_y = 5;
    int ymax = waveform_stage * viewport_height / 4;
    int vstage = step_y * step_v * viewport_width * 12;

    //condition allocate memory
    if (histogram_allocated == 1)
        histogram_free();
    if (waveform_allocated == 0)
        waveform_alloc();

    img_buf=vid_get_viewport_active_buffer();
    if (!img_buf) return;

    if (waveform_stage == 1)
    {
        under_exposed = 0;
        over_exposed = 0;
        waveform_clear();
    }

    for (y=(waveform_stage-1)*60, v=(waveform_stage-1)*vstage, py=(waveform_stage-1)*12; y<ymax; y+=step_y, py++)
    {
        for (x=0, px=0; x<viewport_width; x+=step_x, px++)
        {
            Y = img_buf[v+1];
            U = ((v % (2 * step_v * step_x)) == 0)
                ? (signed char) img_buf[v+0] : (signed char) img_buf[v-3];
            V = ((v % (2 * step_v * step_x)) == 0)
                ? (signed char) img_buf[v+2] : (signed char) img_buf[v-1];

            switch (conf.histo_layout)
            {
            case OSD_HISTO_LAYOUT_WAVE_Y:
                waveform_proc[px][py+0*48] = (unsigned char) clip50(Y / 5);
                if (under_exposed == 0)
                    under_exposed = (Y < exposition_thresh);
                if (over_exposed == 0)
                    over_exposed = (Y > (255 - exposition_thresh));
                break;
            case OSD_HISTO_LAYOUT_WAVE_RGB:
            case OSD_HISTO_LAYOUT_PARD_RGB:
                R = clip(((Y<<12)          + V*5743 + 2048)>>12);  // R
                G = clip(((Y<<12) - U*1411 - V*2925 + 2048)>>12);  // G
                B = clip(((Y<<12) + U*7258          + 2048)>>12);  // B
                waveform_proc[px][py+0*48] = (unsigned char) clip50(R / 5);
                waveform_proc[px][py+1*48] = (unsigned char) clip50(G / 5);
                waveform_proc[px][py+2*48] = (unsigned char) clip50(B / 5);
                break;
            case OSD_HISTO_LAYOUT_WAVE_YS:
                R = clip(((Y<<12)          + V*5743 + 2048)>>12);  // R
                G = clip(((Y<<12) - U*1411 - V*2925 + 2048)>>12);  // G
                B = clip(((Y<<12) + U*7258          + 2048)>>12);  // B
                S = clip((int) 255 * saturation(R, G, B));
                waveform_proc[px][py+0*48] = (unsigned char) clip50(Y / 5);
                waveform_proc[px][py+1*48] = (unsigned char) clip50(S / 5);
                if (under_exposed == 0)
                    under_exposed = (Y < exposition_thresh);
                if (over_exposed == 0)
                    over_exposed = (Y > (255 - exposition_thresh));
                break;
            case OSD_HISTO_LAYOUT_WAVE_YUV:
            case OSD_HISTO_LAYOUT_PARD_YUV:
                waveform_proc[px][py+0*48] = (unsigned char) clip50(Y / 5);
                waveform_proc[px][py+1*48] = (unsigned char) clip50((U+128) / 5);
                waveform_proc[px][py+2*48] = (unsigned char) clip50((V+128) / 5);
                if ((under_exposed == 0) && ((conf3.parade_mode == PARADE_MODE_VERTICAL) || (conf.histo_layout == OSD_HISTO_LAYOUT_WAVE_YUV)))
                    under_exposed = (Y < exposition_thresh);
                if ((over_exposed == 0) && ((conf3.parade_mode == PARADE_MODE_VERTICAL) || (conf.histo_layout == OSD_HISTO_LAYOUT_WAVE_YUV)))
                    over_exposed = (Y > (255 - exposition_thresh));
                break;
            case OSD_HISTO_LAYOUT_PARD_YS:
                R = clip(((Y<<12)          + V*5743 + 2048)>>12);  // R
                G = clip(((Y<<12) - U*1411 - V*2925 + 2048)>>12);  // G
                B = clip(((Y<<12) + U*7258          + 2048)>>12);  // B
                S = clip((int) 255 * saturation(R, G, B));
                waveform_proc[px][py+0*48] = (unsigned char) clip50(Y / 5);
                waveform_proc[px][py+1*48] = (unsigned char) clip50(S / 5);
                if ((under_exposed == 0) && ((conf3.parade_mode == PARADE_MODE_VERTICAL)))
                    under_exposed = (Y < exposition_thresh);
                if ((over_exposed == 0) && ((conf3.parade_mode == PARADE_MODE_VERTICAL)))
                    over_exposed = (Y > (255 - exposition_thresh));
                break;
            case OSD_HISTO_LAYOUT_WAVE_VEC:
                waveform_proc[px][py+0*48] = (unsigned char) clip50(Y / 5);
                waveform_proc[px][py+1*48] = (unsigned char) (U / 2);
                waveform_proc[px][py+2*48] = (unsigned char) (V / 2);
                if (under_exposed == 0)
                    under_exposed = (Y < exposition_thresh);
                if (over_exposed == 0)
                    over_exposed = (Y > (255 - exposition_thresh));
                break;
            }

            v += step_v * step_x;
        }

        v += (step_y - 1) * step_v * viewport_width;
    }

    waveform_stage++;
    if (waveform_stage > 4)
    {
        waveform_copy();
        waveform_stage = 1;
    }
}

static void do_histogram_process()
{
    if (waveform_allocated == 1)
    {
        waveform_free();
    }

    static unsigned char *img;
    static int viewport_size, viewport_width, viewport_row_offset;

    register int x, i, hi;
    int y, v, u, c;
    float (*histogram_transform)(float);
    unsigned int histo_fill[5];
    int histo_main;

    long exposition_thresh = camera_screen.size / 500;

    // Select transform function
    switch (conf.histo_mode)
    {
    case HISTO_MODE_LOG:
        histogram_transform = logarithmic;
        break;
    case HISTO_MODE_LINEAR:
    default:
        histogram_transform = identity;
        break;
    }

    // Select which calculated histogram channel determines magnification / scaling
    if (conf.histo_layout == OSD_HISTO_LAYOUT_Y || conf.histo_layout == OSD_HISTO_LAYOUT_Y_argb
            || conf.histo_layout == OSD_HISTO_LAYOUT_Y_U_V)
        histo_main = HISTO_Y;
    else
        histo_main = HISTO_RGB;

    histogram_alloc();

    // This function is called in the main spytask loop roughly every 20msec
    // To avoid hogging all the CPU it performs it's work in stages controlled by histogram-stage
    // Stage  Function
    //   0      Initialize global variables used in next stages
    //   1,2,3  Count number of values for a third of the viewport image at each stage
    //   4      Calculate max values, over and under exposure setting
    //   5      Calculate the histogram display values
    switch (histogram_stage)
    {
    case 0:
        img=vid_get_viewport_active_buffer();
        if (!img) return;

        img += vid_get_viewport_image_offset();		// offset into viewport for when image size != viewport size (e.g. 16:9 image on 4:3 LCD)
        viewport_size = vid_get_viewport_height() * vid_get_viewport_byte_width() * vid_get_viewport_yscale();
        viewport_width = vid_get_viewport_width();
        viewport_row_offset = vid_get_viewport_row_offset();
        for (c=0; c<5; ++c)
        {
            memset(histogram_proc[c],0,256*sizeof(unsigned short));
            histo_max[c] = histo_max_center[c] = 0;
        }

        histogram_stage=1;
        break;

    case 1:
    case 2:
    case 3:
        x = 0;  // count how many blocks we have done on the current row (to skip unused buffer space at end of each row)
        for (i=(histogram_stage-1)*6; i<viewport_size; i+=HISTO_STEP_SIZE*6)
        {
            y = img[i+1];
            u = *(signed char*)(&img[i]);
            //if (u&0x00000080) u|=0xFFFFFF00;  // Compiler should handle the unsigned -> signed conversion
            v = *(signed char*)(&img[i+2]);
            //if (v&0x00000080) v|=0xFFFFFF00;  // Compiler should handle the unsigned -> signed conversion

            if (conf.histo_layout != OSD_HISTO_LAYOUT_Y_U_V)
            {
                ++histogram_proc[HISTO_Y][y];                       // Y
                hi = clip(((y<<12)          + v*5743 + 2048)>>12);  // R
                ++histogram_proc[HISTO_R][hi];
                hi = clip(((y<<12) - u*1411 - v*2925 + 2048)>>12);  // G
                ++histogram_proc[HISTO_G][hi];
                hi = clip(((y<<12) + u*7258          + 2048)>>12);  // B
                ++histogram_proc[HISTO_B][hi];
            }
            else
            {
                ++histogram_proc[HISTO_Y][y];                       // Y
                hi = y;  // Y
                ++histogram_proc[HISTO_R][hi];
                hi = u + 128;  // U
                ++histogram_proc[HISTO_G][hi];
                hi = v + 128;  // V
                ++histogram_proc[HISTO_B][hi];
            }

            // Handle case where viewport memory buffer is wider than the actual buffer.
            x += HISTO_STEP_SIZE * 2;	// viewport width is measured in blocks of three bytes each even though the data is stored in six byte chunks !
            if (x == viewport_width)
            {
                i += viewport_row_offset;
                x = 0;
            }
        }

        ++histogram_stage;
        break;

    case 4:
        for (i=0, c=0; i<HISTO_WIDTH; ++i, c+=2)   // G
        {
            // Merge each pair of values into a single value (for width = 128)
            // Warning: this is optimised for HISTO_WIDTH = 128, don't change the width unless you re-write this code as well.
            histogram_proc[HISTO_Y][i] = histogram_proc[HISTO_Y][c] + histogram_proc[HISTO_Y][c+1];
            histogram_proc[HISTO_R][i] = histogram_proc[HISTO_R][c] + histogram_proc[HISTO_R][c+1];
            histogram_proc[HISTO_G][i] = histogram_proc[HISTO_G][c] + histogram_proc[HISTO_G][c+1];
            histogram_proc[HISTO_B][i] = histogram_proc[HISTO_B][c] + histogram_proc[HISTO_B][c+1];
            // Calc combined RGB totals
            if (conf.histo_layout != OSD_HISTO_LAYOUT_Y_U_V)
                histogram_proc[HISTO_RGB][i] = histogram_proc[HISTO_R][i] + histogram_proc[HISTO_G][i] + histogram_proc[HISTO_B][i];
            else
                histogram_proc[HISTO_RGB][i] = histogram_proc[HISTO_Y][i];
        }

        // calculate maximums
        for (c=0; c<5; ++c)
        {
            for (i=0; i<HISTO_WIDTH; ++i)
            {
                if (histo_max[c]<histogram_proc[c][i])
                    histo_max[c]=histogram_proc[c][i];
                if (histo_max_center[c]<histogram_proc[c][i] && i>=conf.histo_ignore_boundary && i<HISTO_WIDTH-conf.histo_ignore_boundary)
                    histo_max_center[c]=histogram_proc[c][i];
            }

            if (histo_max_center[c] > 0)
            {
                histo_max_center_invw[c] = ((float)HISTO_HEIGHT)/histogram_transform((float)histo_max_center[c]);
            }
            else if (histo_max[c] > 0)
            {
                histo_max_center_invw[c] = ((float)HISTO_HEIGHT)/histogram_transform((float)histo_max[c]);
            }
            else
            {
                histo_max_center_invw[c] = 0.0f;
            }
        }

        if (histo_max[HISTO_RGB] > 0)   // over- / under- expos
        {
            under_exposed = (histogram_proc[HISTO_RGB][0]*8
                             +histogram_proc[HISTO_RGB][1]*4
                             +histogram_proc[HISTO_RGB][2]) > exposition_thresh;

            over_exposed  = (histogram_proc[HISTO_RGB][HISTO_WIDTH-3]
                             +histogram_proc[HISTO_RGB][HISTO_WIDTH-2]*4
                             +histogram_proc[HISTO_RGB][HISTO_WIDTH-1]*8) > exposition_thresh;
        }
        else
        {
            over_exposed = 0;
            under_exposed = 1;
        }

        histogram_stage=5;
        break;

    case 5:
        for (c=0; c<5; ++c)
        {
            histo_fill[c]=0;
            for (i=0; i<HISTO_WIDTH; ++i)
            {
                histogram[c][i] = (histogram_transform((float)histogram_proc[c][i]))*histo_max_center_invw[c];
                if (histogram[c][i] > HISTO_HEIGHT)
                    histogram[c][i] = HISTO_HEIGHT;
                histo_fill[c]+=histogram[c][i];
            }
        }

        histo_magnification = 0;
        if (conf.histo_auto_ajust)
        {
            if (histo_fill[histo_main] < (HISTO_HEIGHT*HISTO_WIDTH)/5)   // try to ajust if average level is less than 20%
            {
                histo_magnification = (20*HISTO_HEIGHT*HISTO_WIDTH) / histo_fill[histo_main];
                for (c=0; c<5; ++c)
                {
                    for (i=0; i<HISTO_WIDTH; i++)
                    {
                        histogram[c][i] = histogram[c][i] * histo_magnification / 100;
                        if (histogram[c][i] > HISTO_HEIGHT)
                            histogram[c][i] = HISTO_HEIGHT;
                    }
                }
            }
        }

        histogram_stage=0;
        break;
    }

}

void histogram_process()
{
    if (conf.histo_layout >= OSD_HISTO_LAYOUT_WAVE_Y)
    {
        do_waveform_process();
    }
    else
    {
        do_histogram_process();
    }

}

//-------------------------------------------------------------------
// Histogram display functions

static void gui_osd_draw_single_histo(int hist, coord x, coord y, int small)
{
    twoColors hc = user_color(conf.histo_color);
    twoColors hc2 = user_color(conf.histo_color2);

    register unsigned int i, v, threshold;
    register color cl, cl_over, cl_bg = BG_COLOR(hc);
    coord w=HISTO_WIDTH, h=HISTO_HEIGHT;
    int rgb = (conf.histo_layout != OSD_HISTO_LAYOUT_Y_U_V) ? 1 : 0;

    switch (hist)
    {
    case HISTO_R:
        cl=rgb ? COLOR_RED : COLOR_CYAN;
        break;
    case HISTO_G:
        cl=rgb ? COLOR_GREEN : COLOR_MAGENTA;
        break;
    case HISTO_B:
        cl=rgb ? COLOR_BLUE : COLOR_YELLOW;
        break;
    case HISTO_RGB:
    case HISTO_Y:
    default:
        cl=FG_COLOR(hc);
        break;
    }

    if (small)
    {
        h>>=1;
        w>>=1;
        for (i=0; i<w; ++i)
        {
            threshold = (histogram[hist][i<<1]+histogram[hist][(i<<1)+1])>>2;

            for (v=1; v<h-1; ++v)
                draw_pixel(x+1+i, y+h-v, (v<=threshold)?cl:cl_bg);
            cl_over = (threshold==h && conf.show_overexp)?BG_COLOR(hc2):cl;
            for (; v<h; ++v)
                draw_pixel(x+1+i, y+h-v, (v<=threshold)?cl_over:cl_bg);
        }
    }
    else
    {
        for (i=0; i<w; ++i)
        {
            threshold = histogram[hist][i];

            for (v=1; v<h-3; ++v)
                draw_pixel(x+1+i, y+h-v, (v<=threshold)?cl:cl_bg);
            cl_over = (threshold==h && conf.show_overexp)?BG_COLOR(hc2):cl;
            for (; v<h; ++v)
                draw_pixel(x+1+i, y+h-v, (v<=threshold)?cl_over:cl_bg);
        }
    }

    draw_rectangle(x, y, x+1+w, y+h, hc2, RECT_BORDER1);
    //Vertical Lines
    if (conf.histo_show_ev_grid) for (i=1; i<=4; i++) draw_line(x+(1+w)*i/5, y, x+(1+w)*i/5, y+h, FG_COLOR(hc2));
}

//-------------------------------------------------------------------
static void gui_osd_draw_blended_histo(coord x, coord y)
{
    twoColors hc = user_color(conf.histo_color);
    twoColors hc2 = user_color(conf.histo_color2);

    register unsigned int i, v, red, grn, blu, sel;
    color cls[] =
    {
        BG_COLOR(hc),
        COLOR_BLUE,
        COLOR_GREEN,
        COLOR_CYAN,
        COLOR_RED,
        COLOR_MAGENTA,
        COLOR_YELLOW,
        COLOR_WHITE
    };

    for (i=0; i<HISTO_WIDTH; ++i)
    {
        red = histogram[HISTO_R][i];
        grn = histogram[HISTO_G][i];
        blu = histogram[HISTO_B][i];

        for (v=1; v<HISTO_HEIGHT; ++v)
        {
            sel = 0;

            if (v < red) sel = 4;
            if (v < grn) sel |= 2;
            if (v < blu) sel |= 1;

            draw_pixel(x+1+i, y+HISTO_HEIGHT-v, cls[sel]);
        }
    }

    draw_rectangle(x, y, x+1+HISTO_WIDTH, y+HISTO_HEIGHT, hc2, RECT_BORDER1);
    //Vertical lines
    if (conf.histo_show_ev_grid) for (i=1; i<=4; i++) draw_line(x+(1+HISTO_WIDTH)*i/5, y, x+(1+HISTO_WIDTH)*i/5, y+HISTO_HEIGHT, FG_COLOR(hc2));

}

//-------------------------------------------------------------------

static void gui_osd_draw_single_wave(int wave, coord x, coord y, int is_osd_edit)
{
    twoColors hc = user_color(conf.histo_color);
    twoColors hc2 = user_color(conf.histo_color2);
    color cl;
    register unsigned short i, v, lum;
    short offset;

    switch (wave)
    {
    case WAVE_R:
        cl=COLOR_RED;
        offset=0;
        break;
    case WAVE_G:
        cl=COLOR_GREEN;
        offset=48;
        break;
    case WAVE_B:
        cl=COLOR_BLUE;
        offset=96;
        break;
    case WAVE_Y:
        cl=COLOR_CYAN;
        offset=0;
        break;
    case WAVE_U:
        cl=COLOR_MAGENTA;
        offset=48;
        break;
    case WAVE_V:
        cl=COLOR_YELLOW;
        offset=96;
        break;
    case WAVE_S:
        cl=COLOR_MAGENTA;
        offset=48;
        break;
    case WAVE_L:
    default:
        cl=FG_COLOR(hc);
        offset=0;
        break;
    }

    draw_rectangle(x+1, y+1, x+HISTO_WIDTH, y+HISTO_HEIGHT-1, hc, DRAW_FILLED);

    if (!is_osd_edit)
    {
        for (i=0; i<HISTO_WIDTH-8; i++)
        {
            for (v=0; v<HISTO_HEIGHT-2; v++)
            {
                lum = waveform[i][v+offset];
                draw_pixel(x+1+4+i, y+HISTO_HEIGHT-lum, cl);
            }
        }
    }
    draw_rectangle(x, y, x+1+HISTO_WIDTH, y+HISTO_HEIGHT, hc2, RECT_BORDER1);
}

static void gui_osd_draw_horizontal_parade(int parade, coord x, coord y, int is_osd_edit)
{
    twoColors hc = user_color(conf.histo_color);
    twoColors hc2 = user_color(conf.histo_color2);
    color cl;
    register unsigned short i, v, value;
    short offset;

    draw_rectangle(x+1, y+1, x+HISTO_WIDTH*2, y+HISTO_HEIGHT-1, hc, DRAW_FILLED);

    if (!is_osd_edit)
    {
        for (i=0; i<2*HISTO_WIDTH-16; i++)
        {
            for (v=0; v<HISTO_HEIGHT-2; v++)
            {
                if (i < 80)
                {
                    value = waveform[(i-0)*3/2][v+0];
                    cl = parade == PARADE_RGB ? COLOR_RED : COLOR_CYAN;
                }
                else if (i < 160)
                {
                    value = waveform[(i-80)*3/2][v+48];
                    cl = parade == PARADE_RGB ? COLOR_GREEN : COLOR_MAGENTA;
                }
                else
                {
                    value = waveform[(i-160)*3/2][v+96];
                    cl = parade == PARADE_RGB ? COLOR_BLUE : COLOR_YELLOW;
                }
                draw_pixel(x+1+8+i, y+HISTO_HEIGHT-value, cl);
            }
        }
    }
    draw_rectangle(x, y, x+1+HISTO_WIDTH*2, y+HISTO_HEIGHT, hc2, RECT_BORDER1);
}

//-------------------------------------------------------------------

static void gui_osd_draw_blended_wave(int wave, coord x, coord y, int is_osd_edit)
{
    twoColors hc = user_color(conf.histo_color);
    twoColors hc2 = user_color(conf.histo_color2);
    register unsigned short i, v, R, G, B, Y, U, V, S;
    color cls[] =
    {
        COLOR_BLACK,
        COLOR_BLUE,
        COLOR_GREEN,
        COLOR_CYAN,
        COLOR_RED,
        COLOR_MAGENTA,
        COLOR_YELLOW,
        COLOR_WHITE
    };

    draw_rectangle(x+1, y+1, x+HISTO_WIDTH, y+HISTO_HEIGHT-1, hc, DRAW_FILLED);

    if (!is_osd_edit)
    {
        switch (wave)
        {
        case WAVE_RGB:
        {
            for (i=0; i<HISTO_WIDTH-8; i++)
            {
                for (v=0; v<HISTO_HEIGHT-2; v++)
                {
                    R = waveform[i][v+0];
                    G = waveform[i][v+48];
                    B = waveform[i][v+96];

                    draw_pixel(x+1+4+i, y+HISTO_HEIGHT-R, cls[4]);
                    draw_pixel(x+1+4+i, y+HISTO_HEIGHT-G, cls[2]);
                    draw_pixel(x+1+4+i, y+HISTO_HEIGHT-B, cls[1]);

                    //additive color mix
                    if ((R == G) && (G == B)) // WHITE
                        draw_pixel(x+1+4+i, y+HISTO_HEIGHT-R, cls[7]);
                    if ((R == G) && (G != B)) // YELLOW
                        draw_pixel(x+1+4+i, y+HISTO_HEIGHT-R, cls[6]);
                    if ((B != G) && (B == R)) // MAGENTA
                        draw_pixel(x+1+4+i, y+HISTO_HEIGHT-B, cls[5]);
                    if ((B == G) && (B != R)) // CYAN
                        draw_pixel(x+1+4+i, y+HISTO_HEIGHT-B, cls[3]);
                }
            }
        }
        break;
        case WAVE_YUV:
        {
            for (i=0; i<HISTO_WIDTH-8; i++)
            {
                for (v=0; v<HISTO_HEIGHT-2; v++)
                {
                    Y = waveform[i][v+0];
                    U = waveform[i][v+48];
                    V = waveform[i][v+96];

                    draw_pixel(x+1+4+i, y+HISTO_HEIGHT-Y, cls[3]);
                    draw_pixel(x+1+4+i, y+HISTO_HEIGHT-U, cls[5]);
                    draw_pixel(x+1+4+i, y+HISTO_HEIGHT-V, cls[6]);

                    //subtractive color mix
                    if ((Y == U) && (U == V)) // BLACK
                        draw_pixel(x+1+4+i, y+HISTO_HEIGHT-Y, cls[0]);
                    if ((Y == U) && (U != V)) // BLUE
                        draw_pixel(x+1+4+i, y+HISTO_HEIGHT-Y, cls[1]);
                    if ((V != U) && (V == Y)) // GREEN
                        draw_pixel(x+1+4+i, y+HISTO_HEIGHT-V, cls[2]);
                    if ((V == U) && (V != Y)) // RED
                        draw_pixel(x+1+4+i, y+HISTO_HEIGHT-V, cls[4]);

                }
            }
        }
        break;
        case WAVE_YS:
        {
            for (i=0; i<HISTO_WIDTH-8; i++)
            {
                for (v=0; v<HISTO_HEIGHT-2; v++)
                {
                    Y = waveform[i][v+0];
                    S = waveform[i][v+48];

                    draw_pixel(x+1+4+i, y+HISTO_HEIGHT-Y, cls[3]);
                    draw_pixel(x+1+4+i, y+HISTO_HEIGHT-S, cls[5]);

                    //subtractive color mix
                    if (Y == S)
                        draw_pixel(x+1+4+i, y+HISTO_HEIGHT-Y, cls[1]);
                }
            }
        }
        break;
        }
    }
    draw_rectangle(x, y, x+1+HISTO_WIDTH, y+HISTO_HEIGHT, hc2, RECT_BORDER1);
}

//-------------------------------------------------------------------

static void gui_osd_draw_vectorscope(coord x, coord y, int is_osd_edit)
{
    twoColors hc = user_color(conf.histo_color);
    twoColors hc2 = user_color(conf.histo_color2);
    color cl = FG_COLOR(hc);
    register unsigned short i, v;
    register int Y, U, V;
    int center_x = HISTO_WIDTH / 2;
    int center_y = HISTO_WIDTH / 2;

    draw_rectangle(x+1, y+1, x+HISTO_WIDTH, y+HISTO_WIDTH-1, hc, DRAW_FILLED);

    if (!is_osd_edit)
    {
        for (i=0; i<HISTO_WIDTH-8; i++)
        {
            for (v=0; v<HISTO_HEIGHT-2; v++)
            {
                U = (signed char) waveform[i][v+48];
                V = (signed char) waveform[i][v+96];
                draw_pixel(x+center_x+U, y+center_y-V, cl);
            }
        }
    }
    draw_rectangle(x, y, x+1+HISTO_WIDTH, y+HISTO_WIDTH, hc2, RECT_BORDER1);
}

//-------------------------------------------------------------------
void gui_osd_draw_histo(int is_osd_edit)
{
    if (is_osd_edit ||
            ((camera_info.state.mode_play || !camera_info.state.mode_video) &&
             (
                 ((conf.show_histo==SHOW_HISTO_HALF) && camera_info.state.is_shutter_half_press) ||
                 ((conf.show_histo==SHOW_HISTO_REC) && camera_info.state.mode_rec && (recreview_hold==0)) ||
                 ((conf.show_histo==SHOW_HISTO_ALWAYS) && (recreview_hold==0))
             )
            )
       )
    {
        twoColors hc = user_color(conf.histo_color);
        twoColors hc2 = user_color(conf.histo_color2);

        switch (conf.histo_layout)
        {
        case OSD_HISTO_LAYOUT_Y:
            gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y, 0);
            break;
        case OSD_HISTO_LAYOUT_A_Y:
            gui_osd_draw_single_histo(HISTO_RGB, conf.histo_pos.x, conf.histo_pos.y, 0);
            gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 0);
            break;
        case OSD_HISTO_LAYOUT_R_G_B:
        case OSD_HISTO_LAYOUT_Y_U_V:
            gui_osd_draw_single_histo(HISTO_R, conf.histo_pos.x, conf.histo_pos.y, 0);
            gui_osd_draw_single_histo(HISTO_G, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 0);
            gui_osd_draw_single_histo(HISTO_B, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT*2, 0);
            break;
        case OSD_HISTO_LAYOUT_A_yrgb:
            gui_osd_draw_single_histo(HISTO_RGB, conf.histo_pos.x, conf.histo_pos.y, 0);
            gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 1);
            gui_osd_draw_single_histo(HISTO_R, conf.histo_pos.x+HISTO_WIDTH/2+1, conf.histo_pos.y+HISTO_HEIGHT, 1);
            gui_osd_draw_single_histo(HISTO_G, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT+HISTO_HEIGHT/2, 1);
            gui_osd_draw_single_histo(HISTO_B, conf.histo_pos.x+HISTO_WIDTH/2+1, conf.histo_pos.y+HISTO_HEIGHT+HISTO_HEIGHT/2, 1);
            break;
        case OSD_HISTO_LAYOUT_Y_argb:
            gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y, 0);
            gui_osd_draw_single_histo(HISTO_RGB, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 1);
            gui_osd_draw_single_histo(HISTO_R, conf.histo_pos.x+HISTO_WIDTH/2+1, conf.histo_pos.y+HISTO_HEIGHT, 1);
            gui_osd_draw_single_histo(HISTO_G, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT+HISTO_HEIGHT/2, 1);
            gui_osd_draw_single_histo(HISTO_B, conf.histo_pos.x+HISTO_WIDTH/2+1, conf.histo_pos.y+HISTO_HEIGHT+HISTO_HEIGHT/2, 1);
            break;
        case OSD_HISTO_LAYOUT_BLEND:
            gui_osd_draw_blended_histo(conf.histo_pos.x, conf.histo_pos.y);
            break;
        case OSD_HISTO_LAYOUT_BLEND_Y:
            gui_osd_draw_blended_histo(conf.histo_pos.x, conf.histo_pos.y);
            gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 0);
            break;
        case OSD_HISTO_LAYOUT_WAVE_Y:
            gui_osd_draw_single_wave(WAVE_L, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
            break;
        case OSD_HISTO_LAYOUT_WAVE_YS:
            gui_osd_draw_blended_wave(WAVE_YS, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
            break;
        case OSD_HISTO_LAYOUT_WAVE_RGB:
            gui_osd_draw_blended_wave(WAVE_RGB, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
            break;
        case OSD_HISTO_LAYOUT_WAVE_YUV:
            gui_osd_draw_blended_wave(WAVE_YUV, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
            break;
        case OSD_HISTO_LAYOUT_WAVE_VEC:
            gui_osd_draw_single_wave(WAVE_L, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
            gui_osd_draw_vectorscope(conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, is_osd_edit);
            break;
        case OSD_HISTO_LAYOUT_PARD_YS:
            if (conf3.parade_mode == PARADE_MODE_HORIZONTAL)
            {
                gui_osd_draw_horizontal_parade(PARADE_YS, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
            }
            else
            {
                gui_osd_draw_single_wave(WAVE_Y, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
                gui_osd_draw_single_wave(WAVE_S, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, is_osd_edit);
            }
            break;
        case OSD_HISTO_LAYOUT_PARD_RGB:
            if (conf3.parade_mode == PARADE_MODE_HORIZONTAL)
            {
                gui_osd_draw_horizontal_parade(PARADE_RGB, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
            }
            else
            {
                gui_osd_draw_single_wave(WAVE_R, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
                gui_osd_draw_single_wave(WAVE_G, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, is_osd_edit);
                gui_osd_draw_single_wave(WAVE_B, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT*2, is_osd_edit);
            }
            break;
        case OSD_HISTO_LAYOUT_PARD_YUV:
            if (conf3.parade_mode == PARADE_MODE_HORIZONTAL)
            {
                gui_osd_draw_horizontal_parade(PARADE_YUV, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
            }
            else
            {
                gui_osd_draw_single_wave(WAVE_Y, conf.histo_pos.x, conf.histo_pos.y, is_osd_edit);
                gui_osd_draw_single_wave(WAVE_U, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, is_osd_edit);
                gui_osd_draw_single_wave(WAVE_V, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT*2, is_osd_edit);
            }
            break;
        case OSD_HISTO_LAYOUT_A:
        default:
            gui_osd_draw_single_histo(HISTO_RGB, conf.histo_pos.x, conf.histo_pos.y, 0);
            break;
        }

        if (conf.histo_layout != OSD_HISTO_LAYOUT_R_G_B)
        {
            if (under_exposed && conf.show_overexp)
            {
                draw_ellipse(conf.histo_pos.x+5, conf.histo_pos.y+5, 3, 3, BG_COLOR(hc2), DRAW_FILLED);
            }
            if (over_exposed && conf.show_overexp)
            {
                draw_ellipse(conf.histo_pos.x+HISTO_WIDTH-5, conf.histo_pos.y+5, 3, 3, BG_COLOR(hc2), DRAW_FILLED);
            }
        }
        if ((conf.show_overexp ) && camera_info.state.is_shutter_half_press && (under_exposed || over_exposed))
            draw_string(conf.histo_pos.x+HISTO_WIDTH-FONT_WIDTH*3, conf.histo_pos.y-FONT_HEIGHT, "EXP", hc);
        if (conf.histo_auto_ajust)
        {
            if (histo_magnification)
            {
                char osd_buf[64];
                sprintf(osd_buf, " %d.%02dx ", histo_magnification/100, histo_magnification%100);
                draw_string(conf.histo_pos.x, conf.histo_pos.y-FONT_HEIGHT, osd_buf, hc);
            }
            else if (is_osd_edit)
            {
                draw_string(conf.histo_pos.x, conf.histo_pos.y-FONT_HEIGHT, " 9.99x ", hc);
            }
            else
            {
                draw_rectangle(conf.histo_pos.x, conf.histo_pos.y-FONT_HEIGHT, conf.histo_pos.x+8*FONT_WIDTH, conf.histo_pos.y-1, MAKE_COLOR(COLOR_TRANSPARENT, COLOR_TRANSPARENT), RECT_BORDER0|DRAW_FILLED);
            }
        }
    }
}


// =========  MODULE INIT =================

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
    return 0;
}

int _module_can_unload()
{
    return conf.show_histo == 0;
}

/******************** Module Information structure ******************/

libhisto_sym _libhisto =
{
    {
        0, _module_unloader, _module_can_unload, 0, 0
    },

    histogram_process,
    gui_osd_draw_histo
};

ModuleInfo _module_info =
{
    MODULEINFO_V1_MAGICNUM,
    sizeof(ModuleInfo),
    HISTO_VERSION,				// Module version

    ANY_CHDK_BRANCH, 0, OPT_ARCHITECTURE,			// Requirements of CHDK version
    ANY_PLATFORM_ALLOWED,		// Specify platform dependency

    (int32_t)"Histogram Overlay (dll)",
    MTYPE_EXTENSION,

    &_libhisto.base,

    CONF_VERSION,               // CONF version
    CAM_SCREEN_VERSION,         // CAM SCREEN version
    ANY_VERSION,                // CAM SENSOR version
    CAM_INFO_VERSION,           // CAM INFO version
};

/*************** END OF AUXILARY PART *******************/