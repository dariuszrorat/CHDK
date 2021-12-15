/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

// debug
//#define FILEWRITE_DEBUG_LOG 1
extern void _LogCameraEvent(int id,const char *fmt,...);

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7 // filewritetask is prepared for this many chunks


// comments below from elph180, firmware code appears very similar, offsets verified
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for cameras with CAM_FILEWRITETASK_SEEK/CAM_FILEWRITETASK_MULTIPASS
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1; // message number
    int file_offset;
    int maybe_full_size; // maybe, on g7x wasn't always full size
    int unkn2, unkn3;
    int unkn4;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    int maybe_seek_flag;      // 0x2083 jpeg, 0x100 create dir, 0x200 CacheFlush
    int unkn5, unkn6;
    char name[32];      // offset from start 0x5c, from Open case
} fwt_data_struct;
/*
observed message sequences
JPEG
12 maybe_full_size = 0x004437ac (=actual size), seek_flag = 0x2083
 0 chunk 0-0x004437ac
 1 chunk 0-0
 7 close

new directory
11 seek_flag = 0x100
before m 12 for shot, after raw hook in capt_seq

after shot
10 A/ seek_flag 0x200
*/

#include "../../../generic/filewrite.c"

#ifdef FILEWRITE_DEBUG_LOG
void log_fwt_msg(fwt_data_struct *fwd)
{
    int m=fwd->unkn1;
    _LogCameraEvent(0x60,"fw m:%d o:0x%08x fs:0x%08x sf:0x%x",m,fwd->file_offset,fwd->maybe_full_size,fwd->maybe_seek_flag);
    _LogCameraEvent(0x60,"fw %s",fwd->name);
    if(m >= 0 && m <=6) {
        _LogCameraEvent(0x60,"fw chunk adr:0x%08x l:0x%08x",fwd->pdc[m].address,fwd->pdc[m].length);
    }
    _LogCameraEvent(0x60,"fw u %08x %08x %08x %08x %08x %08x",fwd->unkn2,fwd->unkn3,fwd->unkn4,fwd->unkn5,fwd->unkn6);
}

void log_fwt_start(void)
{
    _LogCameraEvent(0x60,"fw start");
}
#endif


/*************************************************************/
//** filewritetask @ 0xFFAD9824 - 0xFFAD9964, length=81
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
#ifdef FILEWRITE_DEBUG_LOG
"bl log_fwt_start\n"
#endif
"    LDR     R5, =0xAC30 \n"

"loc_FFAD982C:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R5, #0x14] \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF838728 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x405 \n"
"    LDRNE   R1, =0xFFAD9998 /*'dwFWrite.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
#ifdef FILEWRITE_DEBUG_LOG
"ldr     r0, [sp,#8]\n"
"bl log_fwt_msg\n"
#endif
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FFAD982C \n"
"    B       loc_FFAD9958 \n"
"    B       loc_FFAD9958 \n"
"    B       loc_FFAD9958 \n"
"    B       loc_FFAD9958 \n"
"    B       loc_FFAD9958 \n"
"    B       loc_FFAD9958 \n"
"    B       loc_FFAD9958 \n"
"    B       loc_FFAD9960 \n"
"    B       loc_FFAD9898 \n"
"    B       loc_FFAD9920 \n"
"    B       loc_FFAD9950 \n"
"    B       loc_FFAD9910 \n"
"    B       loc_FFAD9918 \n"

"loc_FFAD9898:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP] \n"

"loc_FFAD98A0:\n"
"    LDR     R0, [R5, #0x14] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF8389BC /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAD98CC \n"
"    LDR     R0, [R5, #0x14] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF838728 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFAD98A0 \n"

"loc_FFAD98CC:\n"
"    LDR     R0, [R5, #8] \n"
"    MOV     R4, R5 \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFAD9904 \n"
"    BL      _Close \n"
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #8] \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x48 \n"
"    BL      sub_FF8BB258 \n"
"    LDR     R0, =0xFCCF0 \n"
"    BL      sub_FF831430 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF82F310 \n"

"loc_FFAD9904:\n"
"    LDR     R0, [R4, #0x10] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFAD982C \n"

"loc_FFAD9910:\n"
"    BL      sub_FFAD9BB8 \n"
"    B       loc_FFAD982C \n"

"loc_FFAD9918:\n"
"    BL      sub_FFAD9434_my \n"  // --> Patched. Old value = 0xFFAD9434. msg 12 - open, main hook
"    B       loc_FFAD982C \n"

"loc_FFAD9920:\n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #8] \n"
"    MOV     R2, #0 \n"
"    BL      _lseek \n"
"    CMN     R0, #1 \n"
"    LDREQ   R0, =0x9200013 \n"
"    MOVEQ   R1, R4 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    MOVEQ   R0, #7 \n"
"    BLEQ    sub_FFAD936C \n"
"    B       loc_FFAD982C \n"

"loc_FFAD9950:\n"
"    BL      sub_FFAD9C58 \n"
"    B       loc_FFAD982C \n"

"loc_FFAD9958:\n"
"    BL      sub_FFAD9CF4_my \n"  // --> Patched. Old value = 0xFFAD9CF4. msg 0-6 - write chunk
"    B       loc_FFAD982C \n"

"loc_FFAD9960:\n"
"    BL      sub_FFAD9610_my \n"  // --> Patched. Old value = 0xFFAD9610. msg 7 - close
"    B       loc_FFAD982C \n"
);
}

/*************************************************************/
//** sub_FFAD9434_my @ 0xFFAD9434 - 0xFFAD960C, length=119
void __attribute__((naked,noinline)) sub_FFAD9434_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"
//hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
//"  MOV   R0, R4\n"      //data block start, commented out as R0 is already holding what we need
"    BL filewrite_main_hook\n"
"    MOV     R0, R4\n"      //restore register(s)
"    LDR     R0, [R0, #0x50] \n"
"    LDR     R7, =0xAC30 \n"
"    TST     R0, #5 \n"
"    SUB     SP, SP, #0x44 \n"
"    BEQ     loc_FFAD9478 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    CMP     R0, #0 \n"
"    BLXNE   R0 \n"
"    ADD     R0, R4, #0x5C \n"
"    BL      sub_FF831430 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF82F1D0 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x47 \n"
"    BL      sub_FF8BB258 \n"

"loc_FFAD9478:\n"
"    LDR     R0, [R4, #0x50] \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FFAD95E0 \n"
"    LDR     R0, [R4, #0x10] \n"
"    BL      sub_FF82E260 \n"
"    LDR     R0, [R4, #0x50] \n"
"    LDR     R5, =0x301 \n"
"    TST     R0, #0x10 \n"
"    MOVNE   R5, #9 \n"
"    BNE     loc_FFAD94A8 \n"
"    TST     R0, #0x40 \n"
"    MOVNE   R5, #1 \n"

"loc_FFAD94A8:\n"
"    TST     R0, #0x20 \n"
"    BNE     loc_FFAD94BC \n"
"    LDR     R0, [R4, #0x58] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FFAD94C0 \n"

"loc_FFAD94BC:\n"
"    ORR     R5, R5, #0x8000 \n"

"loc_FFAD94C0:\n"
"    LDR     R9, =0x1B6 \n"
"    ADD     R8, R4, #0x5C \n"
"    LDR     R6, [R4, #0x10] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R8 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    CMN     R0, #1 \n"
"    BNE     loc_FFAD9544 \n"
"    MOV     R0, R8 \n"
"    BL      sub_FF827B74 \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R8 \n"
"    MOV     R0, SP \n"
"    BL      sub_006BA914 \n"
"    MOV     R0, #0 \n"
"    LDR     R1, =0x41FF \n"
"    STRB    R0, [SP, #0xF] \n"
"    STR     R1, [SP, #0x20] \n"
"    MOV     R1, #0x10 \n"
"    STR     R1, [SP, #0x24] \n"
"    STR     R0, [SP, #0x28] \n"
"    STR     R0, [SP, #0x2C] \n"
"    ADD     R1, SP, #0x20 \n"
"    MOV     R0, SP \n"
"    STR     R6, [SP, #0x30] \n"
"    STR     R6, [SP, #0x34] \n"
"    STR     R6, [SP, #0x38] \n"
"    BL      sub_FF82EB4C \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R8 \n"
"    BL      _Open \n"

"loc_FFAD9544:\n"
"    CMN     R0, #1 \n"
"    MOV     R5, R0 \n"
"    STR     R0, [R7, #8] \n"
"    BNE     loc_FFAD95A0 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x48 \n"
"    BL      sub_FF8BB258 \n"
"    ADD     R0, R4, #0x5C \n"
"    BL      sub_FF831430 \n"
"    LDR     R1, [R7, #0x20] \n"
"    BL      sub_FF82F310 \n"
"    LDR     R0, [R7, #0x18] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAD9608 \n"
"    LDR     R5, =0x9200001 \n"
"    MOV     R0, R4 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FFAD9308 \n"
"    LDR     R1, [R7, #0x18] \n"
"    MOV     R0, R5 \n"
"    ADD     SP, SP, #0x44 \n"
"    LDMFD   SP!, {R4-R9,LR} \n"
"    BX      R1 \n"

"loc_FFAD95A0:\n"
"    LDR     R0, =0xFCCF0 \n"
"    MOV     R2, #0x20 \n"
"    ADD     R1, R4, #0x5C \n"
"    BL      sub_006BAAFC \n"
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_C\n" // jump over the next block
"    LDR     R0, [R4, #0x50] \n"
"    TST     R0, #0x80 \n"
"    BEQ     loc_FFAD95E0 \n"
"    LDR     R1, [R4, #0xC] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF827844 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0x9200017 \n"
"    MOVEQ   R1, R4 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    MOVEQ   R0, #7 \n"
"    BEQ     loc_FFAD9604 \n"

"loc_FFAD95E0:\n"
"loc_C:\n"
"    LDR     R0, [R4, #0x50] \n"
"    TST     R0, #0x40 \n"
"    LDREQ   R0, [R4, #4] \n"
"    CMPEQ   R0, #0 \n"
"    MOVNE   R1, R4 \n"
"    MOVNE   R0, #9 \n"
"    BLNE    sub_FFAD936C \n"
"    MOV     R1, R4 \n"
"    MOV     R0, #0 \n"

"loc_FFAD9604:\n"
"    BL      sub_FFAD936C \n"

"loc_FFAD9608:\n"
"    ADD     SP, SP, #0x44 \n"
"    LDMFD   SP!, {R4-R9,PC} \n"
);
}

/*************************************************************/
//** sub_FFAD9CF4_my @ 0xFFAD9CF4 - 0xFFAD9DD8, length=58
void __attribute__((naked,noinline)) sub_FFAD9CF4_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FFAD9D20 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x18]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FFAD9D3C \n"
"    B       loc_FFAD9D30 \n"

"loc_FFAD9D20:\n"
"    MOV     R2, #0x348 \n"
"    LDR     R1, =0xFFAD9998 /*'dwFWrite.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FFAD9D30:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       loc_FFAD9DD4 \n"

"loc_FFAD9D3C:\n"
"    LDR     R9, =0xAC30 \n"
"    MOV     R4, R7 \n"

"loc_FFAD9D44:\n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R6, R4 \n"
"    MOVHI   R6, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R6, R0 \n"
"    MOVHI   R6, R0 \n"
"    LDR     R0, [R9, #8] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R5, #4] \n"
"    CMP     R6, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FFAD9DA4 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x14] \n"
"    B       loc_FFAD9D30 \n"

"loc_FFAD9DA4:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    LDRCS   R2, =0x372 \n"
"    LDRCS   R1, =0xFFAD9998 /*'dwFWrite.c'*/ \n"
"    ADD     R8, R8, R0 \n"
"    MOVCS   R0, #0 \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FFAD9D44 \n"
"    LDR     R0, [R5] \n"
"    MOV     R1, R5 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFAD9DD4:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFAD936C \n"
);
}

/*************************************************************/
//** sub_FFAD9610_my @ 0xFFAD9610 - 0xFFAD96B0, length=41
void __attribute__((naked,noinline)) sub_FFAD9610_my() {
asm volatile (
"    STMFD   SP!, {R4-R7,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0, #0x50] \n"
"    LDR     R5, =0xAC30 \n"
"    TST     R0, #0xA \n"
"    SUB     SP, SP, #0x44 \n"
"    BEQ     sub_FFAD97F0 \n"
"    TST     R0, #2 \n"
"    MOV     R6, #0 \n"
"    BEQ     sub_FFAD96C4 \n"
"    TST     R0, #0x80 \n"
"    LDRNE   R0, [R4, #8] \n"
"    LDRNE   R1, [R4, #0xC] \n"
"    CMPNE   R0, R1 \n"
"    BEQ     loc_FFAD968C \n"
"    MOV     R1, R0 \n"
"    LDR     R0, [R5, #8] \n"
"    BL      sub_FF827844 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0x9200017 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    BEQ     loc_FFAD968C \n"
"    LDR     R0, [R4, #8] \n"
"    ADD     R1, SP, #0x20 \n"
"    STR     R0, [R4, #4] \n"
"    ADD     R0, R4, #0x5C \n"
"    BL      sub_FF82EA94 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #4] \n"
"    STREQ   R6, [SP, #0x2C] \n"
"    STREQ   R0, [SP, #0x28] \n"

"loc_FFAD968C:\n"
"    LDR     R0, [R5, #8] \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFAD96C4 \n"
"    LDR     R1, [R4, #0x58] \n"
"    LDR     R7, =0x9200003 \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FFAD96B0 \n"
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
"    BL      sub_FF827464 \n"
"    B       sub_FFAD96B4 \n"

"loc_FFAD96B0:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFAD96B4 \n"  // Continue in firmware
);
}
