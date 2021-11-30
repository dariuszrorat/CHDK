/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 3 //model specific
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    char name[32];
} fwt_data_struct;
#define CAM_HAS_COMPLETEFILEWRITE_REPLACEMENT 1

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFC58D9C - 0xFFC58E2C, length=37
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R4, =0x1AD8C \n"
"    SUB     SP, SP, #4 \n"
"    B       loc_FFC58DD0 \n"

"loc_FFC58DAC:\n"
"    TST     R3, #4 \n"
"    BEQ     loc_FFC58DCC \n"
"    LDR     R0, [R4] \n"
"    BL      sub_FFC103A4 /*_ClearEventFlag*/ \n"
"    LDR     R0, [R4] \n"
"    MOV     R1, #8 \n"
"    BL      sub_FFC10208 /*_SetEventFlag*/ \n"
"    B       loc_FFC58DD0 \n"

"loc_FFC58DCC:\n"
"    BL      sub_FFC58CE4_my \n"  // --> Patched. Old value = 0xFFC58CE4.

"loc_FFC58DD0:\n"
"    MOV     R1, #7 \n"
"    LDR     R0, [R4] \n"
"    MOV     R2, #0 \n"
"    BL      sub_FFC101E8 /*_WaitForAnyEventFlag*/ \n"
"    CMP     R0, #0 \n"
"    MOV     R1, SP \n"
"    BEQ     loc_FFC58E00 \n"
"    MOV     R1, #0x2B0 \n"
"    LDR     R0, =0xFFC58C38 /*'dwFWrite.c'*/ \n"
"    ADD     R1, R1, #1 \n"
"    BL      _DebugAssert \n"
"    B       loc_FFC58E18 \n"

"loc_FFC58E00:\n"
"    LDR     R0, [R4] \n"
"    BL      sub_FFC103F4 /*_GetEventFlagValue*/ \n"
"    LDR     R3, [SP] \n"
"    TST     R3, #2 \n"
"    MOV     R1, #5 \n"
"    BEQ     loc_FFC58DAC \n"

"loc_FFC58E18:\n"
"    LDR     R3, =0x1AD90 \n"
"    LDR     R0, [R3] \n"
"    BL      _GiveSemaphore \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #4 \n"
"    LDMFD   SP!, {R4,PC} \n"
);
}

/*************************************************************/
//** sub_FFC58CE4_my @ 0xFFC58CE4 - 0xFFC58D80, length=40
void __attribute__((naked,noinline)) sub_FFC58CE4_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R2, =0x1AD70 \n"
"    LDRH    R3, [R2] \n"
"    SUB     R3, R3, #1 \n"
"    CMP     R3, #3 \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FFC58D30 \n"
"    .long   loc_FFC58D10 \n"
"    .long   loc_FFC58D20 \n"
"    .long   loc_FFC58D20 \n"
"    .long   loc_FFC58D20 \n"

"loc_FFC58D10:\n"
"    LDR     R0, =0x1AD30 \n"
"    BL      sub_FFC58B90_my \n"  // --> Patched. Old value = 0xFFC58B90.
"    MOV     R4, R0 \n"
"    B       loc_FFC58D34 \n"

"loc_FFC58D20:\n"
"    LDR     R0, =0x1AD30 \n"
"    BL      sub_FFC58C44 \n"
"    MOV     R4, R0 \n"
"    B       loc_FFC58D34 \n"

"loc_FFC58D30:\n"
"    MOV     R4, #1 \n"

"loc_FFC58D34:\n"
"    CMP     R4, #0 \n"
"    MOV     R1, #1 \n"
"    LDMEQFD SP!, {R4,R5,PC} \n"
"    LDR     R3, =0x1AD8C \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FFC103A4 /*_ClearEventFlag*/ \n"
"    LDR     R3, =0x1AD98 \n"
"    LDR     R5, [R3] \n"
"    LDR     R1, =0x1AD94 \n"
"    LDR     R12, =0x26F8 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    CMP     R5, #0 \n"
"    STR     R3, [R1] \n"
"    MOV     R0, R4 \n"
"    STR     R2, [R12] \n"
"    LDMEQFD SP!, {R4,R5,PC} \n"
"    MOV     LR, PC \n"
"    MOV     PC, R5 \n"
"    BL      fwt_after_close\n" //+
"    LDMFD   SP!, {R4,R5,PC} \n"
);
}

/*************************************************************/
//** sub_FFC58B90_my @ 0xFFC58B90 - 0xFFC58C28, length=39
void __attribute__((naked,noinline)) sub_FFC58B90_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R4, R0 \n"
"    ADD     R5, R4, #0x1C \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFC58868 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    BL      sub_FFC61C3C \n"
"    LDR     R3, [R4] \n"
"    MOV     R1, #0x600 \n"
"    TST     R3, #0x10000 \n"
"    ADD     R1, R1, #1 \n"
"    MOV     R2, #0x1B4 \n"
"    ORRNE   R1, R1, #0x8000 \n"
"    LDR     R3, [R4, #0x3C] \n"
"    ADD     R2, R2, #2 \n"
//place hook here
//the task's data block is at [r4] at this point, filename starts at [r4+0x1c]
//the block can be captured here for a (new) camera with unknown data block structure
//for ptp remote capture, pass '/null' as filename
//if writing does not need to be prevented, just continue
"    STMFD   SP!, {R1-R12,LR}\n"
"    MOV     R0, R4\n"
"    BL      filewrite_main_hook\n"
"    BL      filewrite_jpeg_complete\n"
"    CMP     R0, #0\n"
"    LDRNE   R0, =loc_mynull\n" // /null as file name (works only on VxWorks)
"    LDMFD   SP!, {R1-R12,LR}\n"
"    MOVEQ   R0, R5\n" //canon file name
//hook end
//"  MOV     R0, R5 \n"  // - file name
"    BL      sub_FFC5896C \n"
"    MOV     R1, R4 \n"
"    MOV     R2, R0 \n"
"    MOV     R4, #0 \n"
"    LDR     R3, =0x1AD74 \n"
"    CMP     R2, R4 \n"
"    LDR     R6, =0x1AD70 \n"
"    MOV     R0, R5 \n"
"    STR     R2, [R3] \n"
"    BGT     loc_FFC58C10 \n"
"    BL      sub_FFC5887C \n"
"    MOV     R0, #0x8000001 \n"
"    ADD     R0, R0, #0x1200000 \n"
"    BL      sub_FFC56518 \n"
"    MOV     R0, #2 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"

"loc_FFC58C10:\n"
"    LDR     R3, =0x1AD78 \n"
"    LDRH    R0, [R6] \n"
"    STR     R4, [R3] \n"
"    BL      sub_FFC58AE0 \n"
"    STRH    R0, [R6] \n"
"    MOV     R0, R4 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
//mod start
"loc_mynull:\n"
".long   0x6c756e2f\n" // "/null"
".long   0x0000006c\n"
//mod end
);
}
