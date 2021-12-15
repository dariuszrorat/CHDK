#include "../generic/main.c"

long get_vbatt_min() {
    return 3500;
}

long get_vbatt_max() {
    return 4100;
}

static const int fl_tbl[] = {7700, 9000, 10500, 12500, 15600, 18800, 23100};   // EXIF value for each zoom step 
#define NUM_FL (int)(sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 48052   // 37/7.7 * 10000

const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp) {
    return (CF_EFL*get_focal_length(zp))/10000;
}

int get_focal_length(int zp) {
    if(zp<0) return fl_tbl[0];
    else if(zp>NUM_FL-1) return fl_tbl[NUM_FL-1];
    else return fl_tbl[zp];
}

int get_zoom_x(int zp) {
    if(zp<1) return 10;
    else if(zp>NUM_FL-1) return fl_tbl[NUM_FL-1]*10/fl_tbl[0];
    else return fl_tbl[zp]*10/fl_tbl[0];
}

#if 0
int rec_switch_state(void) {
    //mode  = (physw_status[2] & 0x4000)?MODE_REC:MODE_PLAY;
    return (physw_status[2] & 0x4000);
}
#endif
