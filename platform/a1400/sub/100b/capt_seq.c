/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

//From a1400 100b, by comparison to ixus140
static long *nrflag = (long*)(0xBFD4+0x4); // ffa94fb8, 4th arg to  sub_ff9f42a8
#define PAUSE_FOR_FILE_COUNTER 200  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF87D2A4 - 0xFF87D534, length=165
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x38A8C \n"
"    LDR     R7, =0x30AC \n"
"    MOV     R6, #0 \n"

"loc_FF87D2B4:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_003F7418 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF87D2E0 \n"
"    LDR     R1, =0x475 \n"
"    LDR     R0, =0xFF87CD7C /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF87D2E0:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x22 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF87D4FC \n"
"    B       loc_FF87D37C \n"
"    B       loc_FF87D394 \n"
"    B       loc_FF87D3A0 \n"
"    B       loc_FF87D3B4 \n"
"    B       loc_FF87D3AC \n"
"    B       loc_FF87D3C0 \n"
"    B       loc_FF87D3C8 \n"
"    B       loc_FF87D3D0 \n"
"    B       loc_FF87D3DC \n"
"    B       loc_FF87D408 \n"
"    B       loc_FF87D3E8 \n"
"    B       loc_FF87D3F4 \n"
"    B       loc_FF87D3FC \n"
"    B       loc_FF87D410 \n"
"    B       loc_FF87D418 \n"
"    B       loc_FF87D420 \n"
"    B       loc_FF87D428 \n"
"    B       loc_FF87D430 \n"
"    B       loc_FF87D43C \n"
"    B       loc_FF87D444 \n"
"    B       loc_FF87D44C \n"
"    B       loc_FF87D454 \n"
"    B       loc_FF87D45C \n"
"    B       loc_FF87D464 \n"
"    B       loc_FF87D46C \n"
"    B       loc_FF87D474 \n"
"    B       loc_FF87D47C \n"
"    B       loc_FF87D484 \n"
"    B       loc_FF87D490 \n"
"    B       loc_FF87D498 \n"
"    B       loc_FF87D4A4 \n"
"    B       loc_FF87D4DC \n"
"    B       loc_FF87D4E8 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D37C:\n"
// "    BL      shooting_expo_iso_override\n"      // To do: Check if this is needed.
"    BL      sub_FF87DAD8 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF87AF98 \n"
//To do: Check if this is needed.
//"    MOV     R0, #0\n"                          // added
//"    STR     R0, [R5,#0x28]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF975D00_my \n"  // --> Patched. Old value = 0xFF975D00.
"    B       loc_FF87D508 \n"

"loc_FF87D394:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF975B7C_my \n"  // --> Patched. Old value = 0xFF975B7C.
"    B       loc_FF87D508 \n"

"loc_FF87D3A0:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF87DE00 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D3AC:\n"
"    BL      sub_FF87D730 \n"
"    B       loc_FF87D3B8 \n"

"loc_FF87D3B4:\n"
"    BL      sub_FF87DAB4 \n"

"loc_FF87D3B8:\n"
"    STR     R6, [R5, #0x28] \n"
"    B       loc_FF87D508 \n"

"loc_FF87D3C0:\n"
"    BL      sub_FF87DABC \n"
"    B       loc_FF87D508 \n"

"loc_FF87D3C8:\n"
"    BL      sub_FF87DCD8 \n"
"    B       loc_FF87D3E0 \n"

"loc_FF87D3D0:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF975D90 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D3DC:\n"
"    BL      sub_FF87DD6C \n"

"loc_FF87D3E0:\n"
"    BL      sub_FF87AF98 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D3E8:\n"
"    LDR     R0, [R5, #0x58] \n"
"    BL      sub_FF87E310 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D3F4:\n"
"    BL      sub_FF87E71C \n"
"    B       loc_FF87D508 \n"

"loc_FF87D3FC:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF87E780 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D408:\n"
"    BL      sub_FF87DAB4 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D410:\n"
"    BL      sub_FF975094 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D418:\n"
"    BL      sub_FF9752CC \n"
"    B       loc_FF87D508 \n"

"loc_FF87D420:\n"
"    BL      sub_FF975388 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D428:\n"
"    BL      sub_FF97545C \n"
"    B       loc_FF87D508 \n"

"loc_FF87D430:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF9756BC \n"
"    B       loc_FF87D508 \n"

"loc_FF87D43C:\n"
"    BL      sub_FF975820 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D444:\n"
"    BL      sub_FF9758B4 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D44C:\n"
"    BL      sub_FF97595C \n"
"    B       loc_FF87D508 \n"

"loc_FF87D454:\n"
"    BL      sub_FF87DF68 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D45C:\n"
"    BL      sub_FF87DF94 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D464:\n"
"    BL      sub_FF97552C \n"
"    B       loc_FF87D508 \n"

"loc_FF87D46C:\n"
"    BL      sub_FF97556C \n"
"    B       loc_FF87D508 \n"

"loc_FF87D474:\n"
"    BL      sub_FF880B88 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D47C:\n"
"    BL      sub_FF880C74 \n"
"    B       loc_FF87D508 \n"

"loc_FF87D484:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF975A6C \n"
"    B       loc_FF87D508 \n"

"loc_FF87D490:\n"
"    BL      sub_FF975ADC \n"
"    B       loc_FF87D508 \n"

"loc_FF87D498:\n"
"    BL      sub_FF880E00 \n"
"    BL      sub_FF880CCC \n"
"    B       loc_FF87D508 \n"

"loc_FF87D4A4:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF976504 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF97662C \n"
"    LDR     R0, =0x38B8C \n"
"    LDRH    R0, [R0, #0x8C] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x8000 \n"
"    SUBNES  R1, R1, #0x230 \n"
"    BNE     loc_FF87D508 \n"
"    BL      sub_FF880C74 \n"
"    BL      sub_FF88114C \n"
"    B       loc_FF87D508 \n"

"loc_FF87D4DC:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0xD \n"
"    B       loc_FF87D4F0 \n"

"loc_FF87D4E8:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0xC \n"

"loc_FF87D4F0:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF87B80C \n"
"    B       loc_FF87D508 \n"

"loc_FF87D4FC:\n"
"    LDR     R1, =0x5DA \n"
"    LDR     R0, =0xFF87CD7C /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF87D508:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_003FAD9C /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x116 \n"
"    LDREQ   R0, =0xFF87CD7C /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R4, #8] \n"
"    B       loc_FF87D2B4 \n"
);
}

/*************************************************************/
//** sub_FF975D00_my @ 0xFF975D00 - 0xFF975D8C, length=36
void __attribute__((naked,noinline)) sub_FF975D00_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF87C990 \n"
"    MOV     R4, R0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF882730 \n"
"    LDR     R6, =0x6E3C \n"
"    TST     R0, #1 \n"
"    MOV     R5, #1 \n"
"    BNE     loc_FF975D88 \n"
"    BL      sub_FF87DAC4 \n"
"    BL      sub_FF87EA94 \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF87EAEC \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #8 \n"
"    MOV     R0, #0x3F \n"
"    BL      _SetPropertyCase \n"
"    BL      sub_FF9767EC \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFA94EA0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFA951C0_my \n"  // --> Patched. Old value = 0xFFA951C0.
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"

"loc_FF975D88:\n"
"    STR     R5, [R6] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF975B7C_my @ 0xFF975B7C - 0xFF975CFC, length=97
void __attribute__((naked,noinline)) sub_FF975B7C_my() {
asm volatile (
"    STMFD   SP!, {R2-R6,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, =0x6E3C \n"
"    LDR     R6, =0x38A8C \n"
"    LDR     R0, [R0] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R4, #0x1D \n"
"    BNE     loc_FF975CE0 \n"
"    LDR     R0, [R6, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF975CE0 \n"
"    BL      sub_FF87EA94 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF87EAEC \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF882730 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF975BF0 \n"
"    BL      sub_FF87B678 \n"
"    MOV     R4, #1 \n"

"loc_FF975BF0:\n"
"    TST     R4, #1 \n"
"    BNE     loc_FF975CE0 \n"
"    BL      sub_FF9767EC \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFA946A0 \n"
"    TST     R0, #1 \n"
"    MOV     R4, R0 \n"
"    BNE     loc_FF975CE0 \n"
"    BL      sub_FF87DAC4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFA94EA0 \n"
"    LDR     R0, [R6, #0xA0] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF975CC0 \n"
// To do: Check this, there are other paths:
// FF977D38 -> FFA97130
"    LDR     R0, =0x38B8C \n"
"    LDRH    R0, [R0, #0x8A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R5, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF975C64 \n"
"    BL      sub_FF9767EC \n"
"    MOV     R3, #0xDB \n"
"    STR     R3, [SP] \n"
"    LDR     R2, =0x3A98 \n"
"    LDR     R3, =0xFF975E24 /*'SsCaptureCtrl.c'*/ \n"
"    MOV     R1, #0x1000 \n"
"    BL      sub_FF882998 \n"

"loc_FF975C64:\n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #4 \n"
"    MOV     R0, #0x180 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0xDF \n"
"    LDRNE   R0, =0xFF975E24 /*'SsCaptureCtrl.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF975CA0 \n"
"    BL      sub_FF9767EC \n"
"    MOV     R1, #0x1000 \n"
"    BL      sub_003FAD9C /*_SetEventFlag*/ \n"
"    B       loc_FF975CC0 \n"

"loc_FF975CA0:\n"
"    BL      sub_FF9767EC \n"
"    MOV     R1, #0x1000 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    LDR     R2, =0xFF975B68 \n"
"    LDR     R0, [SP, #4] \n"
"    MOV     R3, #0x1000 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF831BD8 /*_SetTimerAfter*/ \n"

"loc_FF975CC0:\n"
"    LDR     R0, [R6, #0xAC] \n"
"    CMP     R0, #0 \n"
"    MOV     R0, R5 \n"
"    BEQ     loc_FF975CD8 \n"
"    BL      sub_FFA95570 \n"
"    B       loc_FF975CDC \n"

"loc_FF975CD8:\n"
"    BL      sub_FFA951C0_my \n"  // --> Patched. Old value = 0xFFA951C0.

"loc_FF975CDC:\n"
"    BL      capt_seq_hook_raw_here \n"         // added
"    MOV     R4, R0 \n"

"loc_FF975CE0:\n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF87B80C \n"
"    TST     R4, #1 \n"
"    MOVEQ   R0, #0 \n"
"    STREQ   R0, [R6, #0x28] \n"
"    LDMFD   SP!, {R2-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FFA951C0_my @ 0xFFA951C0 - 0xFFA95240, length=33
void __attribute__((naked,noinline)) sub_FFA951C0_my() {
asm volatile (
"    STMFD   SP!, {R2-R8,LR} \n"
"    MOV     R4, R0 \n"
"    BL      sub_FFA94E1C \n"
"    BL      sub_FF9762E0 \n"
"    LDR     R8, =0x38A8C \n"
"    LDR     R0, [R8, #0x180] \n"
"    ADD     R5, R8, #0x100 \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FFA951FC \n"
"    LDRH    R0, [R5, #0x8A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #4 \n"
"    BLLS    sub_FF8FA084 \n"

"loc_FFA951FC:\n"
"    LDR     R0, =0x12F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #4 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0x170 \n"
"    LDRNE   R0, =0xFFA95424 /*'SsStandardCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRNE   R0, =0xFFA94B54 \n"
"    LDREQ   R0, =0xFFA95188 \n"
"    MOVNE   R1, R4 \n"
"    MOVEQ   R1, #0 \n"
"    BL      sub_FF8AC910 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFA94F28_my \n"  // --> Patched. Old value = 0xFFA94F28.
"    LDR     PC, =0xFFA95244 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFA94F28_my @ 0xFFA94F28 - 0xFFA94FC0, length=39
void __attribute__((naked,noinline)) sub_FFA94F28_my() {
asm volatile (
"    STMFD   SP!, {R1-R7,LR} \n"
"    LDR     R5, =0x38C5C \n"
"    LDR     R6, =0x38A8C \n"
"    MOV     R4, R0 \n"
"    LDR     R3, [R5] \n"
"    LDRSH   R2, [R5, #0xC] \n"
"    LDRSH   R1, [R5, #0xE] \n"
"    LDR     R0, [R6, #0x88] \n"
"    BL      sub_FF933C78 \n"
"    MOV     R2, #2 \n"
"    ADD     R1, SP, #8 \n"
"    MOV     R0, #0xFA \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x2E5 \n"
"    LDRNE   R0, =0xFFA94DF4 /*'SsCaptureCommon.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDRSH   R0, [R5, #0xC] \n"
"    LDRSH   R1, [SP, #8] \n"
"    BL      sub_FF8F75C8 \n"
"    LDR     R0, [R6, #0xE4] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x38B8C \n"
"    LDRNEH  R0, [R0, #0x8A] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FFA94FC0 \n"
"    BL      _GetCCDTemperature \n"
"    LDR     R3, =0xBFD4 \n"
"    STRH    R0, [R4, #0xA0] \n"
"    SUB     R2, R3, #4 \n"
"    STRD    R2, [SP] \n"
"    MOV     R1, R0 \n"
"    LDRSH   R2, [R5, #0xC] \n"
"    LDRH    R0, [R6, #0x5E] \n"
"    ADD     R3, R3, #4 \n"
"    BL      sub_FF9F42A8 \n"

"loc_FFA94FC0:\n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    LDRH    R0, [R4, #0xA0] \n"
"    LDR     PC, =0xFFA94FC4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8B98F4 - 0xFF8B9F84, length=421
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x3F90 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x57E60 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF8B9914:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_003F7418 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8B9960 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF8B9AC0 \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF8B9A48 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8B98A4 \n"

"loc_FF8B9960:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF8B998C \n"
"    BL      sub_FF8BAE28 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_003FAD9C /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF8B998C:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF8B99A8 \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8B9F7C \n"

"loc_FF8B99A8:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF8B99F8 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8B4F68 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF96B694 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_003FACDC /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1664 \n"
"    BNE     loc_FF8B9AB4 \n"

"loc_FF8B99E4:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF8B9F7C \n"

"loc_FF8B99F8:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF8B9A40 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8B98A4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8B4F78 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF96B834 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_003FACDC /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8B99E4 \n"
"    LDR     R1, =0x166E \n"
"    B       loc_FF8B9AB4 \n"

"loc_FF8B9A40:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF8B9A58 \n"

"loc_FF8B9A48:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8B98A4 \n"
"    B       loc_FF8B99E4 \n"

"loc_FF8B9A58:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF8B9A70 \n"
"    BL      sub_FF8A4388 \n"
"    BL      sub_FF8A5144 \n"
"    BL      sub_FF8A4C58 \n"
"    B       loc_FF8B99E4 \n"

"loc_FF8B9A70:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF8B9AC0 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF8B4F98 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF8A3DD8 \n"
"    BL      sub_FF8A4068 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_003FABF8 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8B99E4 \n"
"    LDR     R1, =0x1696 \n"

"loc_FF8B9AB4:\n"
"    LDR     R0, =0xFF8B56FC /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8B99E4 \n"

"loc_FF8B9AC0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF8B9B28 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8B7CB4 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8BB248 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_FF8B9E40 \n"

"loc_FF8B9B28:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF8B9BE0 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8B7F18 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF8B9B7C \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF8B9BB4 \n"

"loc_FF8B9B7C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_FF8B9BC8 \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8B9518 \n"

"loc_FF8B9BB4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF8B9844 \n"
"    B       loc_FF8B9E48 \n"

"loc_FF8B9BC8:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF8B9E48 \n"

"loc_FF8B9BE0:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF8B9C2C \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8B6C88 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8B70CC \n"
"    B       loc_FF8B9E48 \n"

"loc_FF8B9C2C:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8B9E30 \n"
"    B       loc_FF8B9CE8 \n"
"    B       loc_FF8B9CE8 \n"
"    B       loc_FF8B9CF0 \n"
"    B       loc_FF8B9CF8 \n"
"    B       loc_FF8B9CF8 \n"
"    B       loc_FF8B9CF8 \n"
"    B       loc_FF8B9CE8 \n"
"    B       loc_FF8B9CF0 \n"
"    B       loc_FF8B9CF8 \n"
"    B       loc_FF8B9CF8 \n"
"    B       loc_FF8B9D10 \n"
"    B       loc_FF8B9D10 \n"
"    B       loc_FF8B9E1C \n"
"    B       loc_FF8B9E24 \n"
"    B       loc_FF8B9E24 \n"
"    B       loc_FF8B9E24 \n"
"    B       loc_FF8B9E24 \n"
"    B       loc_FF8B9E2C \n"
"    B       loc_FF8B9E30 \n"
"    B       loc_FF8B9E30 \n"
"    B       loc_FF8B9E30 \n"
"    B       loc_FF8B9E30 \n"
"    B       loc_FF8B9E30 \n"
"    B       loc_FF8B9E30 \n"
"    B       loc_FF8B9D00 \n"
"    B       loc_FF8B9D08 \n"
"    B       loc_FF8B9D08 \n"
"    B       loc_FF8B9D08 \n"
"    B       loc_FF8B9D1C \n"
"    B       loc_FF8B9D1C \n"
"    B       loc_FF8B9D24 \n"
"    B       loc_FF8B9D5C \n"
"    B       loc_FF8B9D94 \n"
"    B       loc_FF8B9DCC \n"
"    B       loc_FF8B9E04 \n"
"    B       loc_FF8B9E04 \n"
"    B       loc_FF8B9E30 \n"
"    B       loc_FF8B9E30 \n"
"    B       loc_FF8B9E0C \n"
"    B       loc_FF8B9E14 \n"

"loc_FF8B9CE8:\n"
"    BL      sub_FF8B557C \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9CF0:\n"
"    BL      sub_FF8B5838 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9CF8:\n"
"    BL      sub_FF8B5A64 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9D00:\n"
"    BL      sub_FF8B5D90 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9D08:\n"
"    BL      sub_FF8B5FAC \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9D10:\n"
"    BL      sub_FF8B636C_my \n"  // --> Patched. Old value = 0xFF8B636C.
"    MOV     R8, #0 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9D1C:\n"
"    BL      sub_FF8B64B0 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9D24:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8BAECC \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9D5C:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8BB044 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9D94:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8BB0FC \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9DCC:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8BB1A4 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9E04:\n"
"    BL      sub_FF8B6A38 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9E0C:\n"
"    BL      sub_FF8B71D0 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9E14:\n"
"    BL      sub_FF8B74B8 \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9E1C:\n"
"    BL      sub_FF8B777C \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9E24:\n"
"    BL      sub_FF8B793C \n"
"    B       loc_FF8B9E30 \n"

"loc_FF8B9E2C:\n"
"    BL      sub_FF8B7AA8 \n"

"loc_FF8B9E30:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_FF8B9E40:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF8B9E48:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF8B9E80 \n"
"    BGT     loc_FF8B9E70 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF8B9EB4 \n"
"    B       loc_FF8B9E80 \n"

"loc_FF8B9E70:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF8B9EB4 \n"

"loc_FF8B9E80:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF8B9EB4 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF8BB45C \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF8B9EB4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF8B9F04 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x57E60 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_003FC550 \n"
"    LDR     R0, =0x57E6C \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_003FC550 \n"
"    LDR     R0, =0x57E78 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_003FC550 \n"
"    B       loc_FF8B9F7C \n"

"loc_FF8B9F04:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8B9F48 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8B535C \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8B9F78 \n"

"loc_FF8B9F48:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF8B535C \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF8B9F78:\n"
"    BL      sub_FF8B54C8 \n"

"loc_FF8B9F7C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8BAE28 \n"
"    B       loc_FF8B9914 \n"
);
}

/*************************************************************/
//** sub_FF8B636C_my @ 0xFF8B636C - 0xFF8B6430, length=50
void __attribute__((naked,noinline)) sub_FF8B636C_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x3F90 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R3, #1 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF8B5000 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8B51BC \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8B5214 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF8B526C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8B52C4 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x57E78 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF8B6404 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF8B6404 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF8B4F58 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF96B718 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF8B640C \n"

"loc_FF8B6404:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF8B640C:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF8B6428 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF8B4FDC \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF8BAE88 \n"

"loc_FF8B6428:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8A40D4_my \n"  // --> Patched. Old value = 0xFF8A40D4.
"    LDR     PC, =0xFF8B6434 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8A40D4_my @ 0xFF8A40D4 - 0xFF8A4114, length=17
void __attribute__((naked,noinline)) sub_FF8A40D4_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x3BD4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R1, #0x154 \n"
"    LDRNE   R0, =0xFF8A3F0C /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x15A \n"
"    LDREQ   R0, =0xFF8A3F0C /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF8A4118 \n"  // Continue in firmware
);
}
