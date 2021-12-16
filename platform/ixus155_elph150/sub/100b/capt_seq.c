/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
static long *nrflag = (long*)(0xa324); // found near 0xffa2316c (0a320 + 4)
//#define PAUSE_FOR_FILE_COUNTER 200  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF88C07C - 0xFF88C354, length=183
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x1CCF0 \n"
"    LDR     R7, =0x3534 \n"
"    MOV     R6, #0 \n"

"loc_FF88C08C:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_006B8458 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF88C0BC \n"
"    LDR     R2, =0x429 \n"
"    LDR     R1, =0xFF88B9F8 /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF88C0BC:\n"
"    LDR     R0, [SP] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #0x23 \n"
"    CMPNE   R0, #0x19 \n"
"    BLNE    sub_FF997D40 \n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x25 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF88C318 \n"
"    B       loc_FF88C17C \n"
"    B       loc_FF88C194 \n"
"    B       loc_FF88C1A0 \n"
"    B       loc_FF88C1B4 \n"
"    B       loc_FF88C1AC \n"
"    B       loc_FF88C1C0 \n"
"    B       loc_FF88C1C8 \n"
"    B       loc_FF88C1D0 \n"
"    B       loc_FF88C1DC \n"
"    B       loc_FF88C208 \n"
"    B       loc_FF88C1E8 \n"
"    B       loc_FF88C1F4 \n"
"    B       loc_FF88C1FC \n"
"    B       loc_FF88C210 \n"
"    B       loc_FF88C218 \n"
"    B       loc_FF88C220 \n"
"    B       loc_FF88C228 \n"
"    B       loc_FF88C230 \n"
"    B       loc_FF88C23C \n"
"    B       loc_FF88C244 \n"
"    B       loc_FF88C24C \n"
"    B       loc_FF88C254 \n"
"    B       loc_FF88C25C \n"
"    B       loc_FF88C264 \n"
"    B       loc_FF88C26C \n"
"    B       loc_FF88C274 \n"
"    B       loc_FF88C280 \n"
"    B       loc_FF88C288 \n"
"    B       loc_FF88C290 \n"
"    B       loc_FF88C298 \n"
"    B       loc_FF88C2A0 \n"
"    B       loc_FF88C2AC \n"
"    B       loc_FF88C2B4 \n"
"    B       loc_FF88C2C0 \n"
"    B       loc_FF88C2F8 \n"
"    B       loc_FF88C304 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C17C:\n"
"    BL      sub_FF88C8A0 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF889644 \n"
// try avoid intermittetant override failues on quick press, not needed?
//"    MOV     R0, #0\n"                          // added
//"    STR     R0, [R5,#0x28]\n"                  // added
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF996950_my \n"  // --> Patched. Old value = 0xFF996950.
"    B       loc_FF88C328 \n"

"loc_FF88C194:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF996844_my \n"  // --> Patched. Old value = 0xFF996844.
"    B       loc_FF88C328 \n"

"loc_FF88C1A0:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF88CBFC \n"
"    B       loc_FF88C328 \n"

"loc_FF88C1AC:\n"
"    BL      sub_FF88C508 \n"
"    B       loc_FF88C1B8 \n"

"loc_FF88C1B4:\n"
"    BL      sub_FF88C87C \n"

"loc_FF88C1B8:\n"
"    STR     R6, [R5, #0x28] \n"
"    B       loc_FF88C328 \n"

"loc_FF88C1C0:\n"
"    BL      sub_FF88C884 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C1C8:\n"
"    BL      sub_FF88CAC0 \n"
"    B       loc_FF88C1E0 \n"

"loc_FF88C1D0:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF9969EC \n"
"    B       loc_FF88C328 \n"

"loc_FF88C1DC:\n"
"    BL      sub_FF88CB54 \n"

"loc_FF88C1E0:\n"
"    BL      sub_FF889644 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C1E8:\n"
"    LDR     R0, [R5, #0x50] \n"
"    BL      sub_FF88D200 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C1F4:\n"
"    BL      sub_FF88D650 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C1FC:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF88D6B8 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C208:\n"
"    BL      sub_FF88C87C \n"
"    B       loc_FF88C328 \n"

"loc_FF88C210:\n"
"    BL      sub_FF995D40 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C218:\n"
"    BL      sub_FF995F7C \n"
"    B       loc_FF88C328 \n"

"loc_FF88C220:\n"
"    BL      sub_FF996038 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C228:\n"
"    BL      sub_FF996110 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C230:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF996378 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C23C:\n"
"    BL      sub_FF9964D8 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C244:\n"
"    BL      sub_FF893144 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C24C:\n"
"    BL      sub_FF893150 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C254:\n"
"    BL      sub_FF996574 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C25C:\n"
"    BL      sub_FF996620 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C264:\n"
"    BL      sub_FF88CD64 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C26C:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF88C278 \n"

"loc_FF88C274:\n"
"    LDR     R0, [R0, #0xC] \n"

"loc_FF88C278:\n"
"    BL      sub_FF88CDF0 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C280:\n"
"    BL      sub_FF9961E0 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C288:\n"
"    BL      sub_FF996220 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C290:\n"
"    BL      sub_FF88FBE8 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C298:\n"
"    BL      sub_FF88FCD8 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C2A0:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF996730 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C2AC:\n"
"    BL      sub_FF9967B8 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C2B4:\n"
"    BL      sub_FF88FE64 \n"
"    BL      sub_FF88FD30 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C2C0:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF997240 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF99736C \n"
"    LDR     R0, =0x1CDF0 \n"
"    LDRH    R0, [R0, #0x90] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x8200 \n"
"    SUBNES  R1, R1, #0x31 \n"
"    BNE     loc_FF88C328 \n"
"    BL      sub_FF88FCD8 \n"
"    BL      sub_FF8901FC \n"
"    B       loc_FF88C328 \n"

"loc_FF88C2F8:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x10 \n"
"    B       loc_FF88C30C \n"

"loc_FF88C304:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0xF \n"

"loc_FF88C30C:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF88A118 \n"
"    B       loc_FF88C328 \n"

"loc_FF88C318:\n"
"    LDR     R2, =0x54D \n"
"    LDR     R1, =0xFF88B9F8 /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FF88C328:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_006B81EC /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R2, =0x11E \n"
"    LDREQ   R1, =0xFF88B9F8 /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R4, #8] \n"
"    B       loc_FF88C08C \n"
);
}

/*************************************************************/
//** sub_FF996950_my @ 0xFF996950 - 0xFF9969E8, length=39
void __attribute__((naked,noinline)) sub_FF996950_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF88B5E0 \n"
"    MOV     R4, R0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF891824 \n"
"    LDR     R6, =0x7488 \n"
"    TST     R0, #1 \n"
"    MOV     R5, #1 \n"
"    BNE     loc_FF9969E4 \n"
"    BL      sub_FF891880 \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF9969E4 \n"
"    BL      sub_FF88C88C \n"
"    BL      sub_FF88D9FC \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF88DA58 \n"
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
"    BL      sub_FF99752C \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC0C40 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC0FC0_my \n"  // --> Patched. Old value = 0xFFAC0FC0.
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"

"loc_FF9969E4:\n"
"    STR     R5, [R6] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF996844_my @ 0xFF996844 - 0xFF996920, length=56
void __attribute__((naked,noinline)) sub_FF996844_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R6, =0x1CCF0 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R6, #0x28] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF996890 \n"
"    LDR     R0, =0x7488 \n"
"    MOV     R2, R5 \n"
"    LDR     R0, [R0] \n"
"    MOV     R1, #1 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R4, #0x1D \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF88A118 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF997AC8 \n"
"    B       sub_FF996944 \n"

"loc_FF996890:\n"
"    BL      sub_FF88D9FC \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF88DA58 \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF891824 \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF9968D8 \n"
"    BL      sub_FF891880 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF9968E0 \n"

"loc_FF9968D8:\n"
"    BL      sub_FF889EF8 \n"
"    MOV     R4, #1 \n"

"loc_FF9968E0:\n"
"    TST     R4, #1 \n"
"    BNE     sub_FF996928 \n"
"    BL      sub_FF99752C \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFAC0320 \n"
"    TST     R0, #1 \n"
"    MOV     R4, R0 \n"
"    BNE     sub_FF996928 \n"
"    BL      sub_FF88C88C \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFAC0C40 \n"
"    MOV     R0, #2 \n"
"    BL      sub_FF8932C4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFAC0FC0_my \n"  // --> Patched. Old value = 0xFFAC0FC0.
"    LDR     PC, =0xFF996924 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFAC0FC0_my @ 0xFFAC0FC0 - 0xFFAC1230, length=157
void __attribute__((naked,noinline)) sub_FFAC0FC0_my() {
asm volatile (
"    STMFD   SP!, {R2-R8,LR} \n"
"    MOV     R4, R0 \n"
"    BL      sub_FFAC0BA8 \n"
"    BL      sub_FF996FF8 \n"
"    LDR     R7, =0x1CCF0 \n"
"    LDR     R0, [R7, #0x184] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FFAC0FFC \n"
"    ADD     R0, R7, #0x100 \n"
"    LDRH    R0, [R0, #0x8E] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #3 \n"
"    BLLS    sub_FF919774 \n"

"loc_FFAC0FFC:\n"
"    LDR     R0, =0x12F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #4 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, #0x18C \n"
"    LDRNE   R1, =0xFFAC1244 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRNE   R0, =0xFFAC0830 \n"
"    LDREQ   R0, =0xFFAC0F88 \n"
"    MOVNE   R1, R4 \n"
"    MOVEQ   R1, #0 \n"
"    BL      sub_FF8CB2EC \n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    MOV     R0, R4 \n"
"    BL      sub_FFAC0CD0 \n"
"    LDR     R1, =0xCB04 \n"
"    MOV     R2, #4 \n"
"    MOV     R0, #0x8A \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x19B \n"
"    LDRNE   R1, =0xFFAC1244 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    BL      sub_FF88EE64 \n"
"    BL      sub_FF97AB80 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC133C \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R8, =0xCB04 \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRH    R0, [R4, #0x18] \n"
"    LDRNE   R2, =0xFFAC0A94 \n"
"    LDREQ   R2, =0xFFAC0A10 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAC10B8 \n"
"    CMP     R0, #1 \n"
"    BEQ     loc_FFAC10DC \n"
"    CMP     R0, #4 \n"
"    BNE     loc_FFAC1150 \n"

"loc_FFAC10B8:\n"
"    STR     R6, [SP] \n"
"    MOV     R3, R2 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC06B4 \n"
"    MOV     R5, R0 \n"
"    BL      sub_FF8C80CC \n"
"    B       loc_FFAC1164 \n"

"loc_FFAC10DC:\n"
"    STR     R6, [SP] \n"
"    MOV     R3, R2 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC0734 \n"
"    MOV     R5, R0 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x45 \n"
"    BL      sub_FF8321D8 \n"
"    TST     R5, #1 \n"
"    BNE     loc_FFAC1164 \n"
"    LDR     R0, =0xFFAC0F88 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8CB2EC \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC133C \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R8] \n"
"    BL      sub_FFAC0B2C \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R3, R6 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC07B4 \n"
"    MOV     R5, R0 \n"
"    BL      sub_FFAC063C \n"
"    B       loc_FFAC1164 \n"

"loc_FFAC1150:\n"
"    LDR     R2, =0x1D5 \n"
"    LDR     R1, =0xFFAC1244 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    MOV     R5, #0x1D \n"

"loc_FFAC1164:\n"
"    BL      sub_FF97AB98 \n"
"    LDR     R8, =0xFFAC0F88 \n"
"    TST     R5, #1 \n"
"    BNE     loc_FFAC11E4 \n"
"    LDR     R0, [R7, #0xF8] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFAC119C \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF9982D4 \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x1EF \n"
"    LDRNE   R1, =0xFFAC1244 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    BL      capt_seq_hook_raw_here \n"         // added

"loc_FFAC119C:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC0DB8 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC0D70 \n"
"    CMP     R6, R8 \n"
"    BEQ     loc_FFAC11E4 \n"
"    BL      sub_FF99752C \n"
"    MOV     R3, #0x1FC \n"
"    STR     R3, [SP] \n"
"    LDR     R2, =0x3A98 \n"
"    LDR     R3, =0xFFAC1244 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF891AF4 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R2, #0x1FC \n"
"    LDRNE   R1, =0xFFAC1244 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"

"loc_FFAC11E4:\n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF88A118 \n"
"    LDR     R0, [R7, #0x28] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAC1218 \n"
"    SUBS    R1, R6, R8 \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF997A60 \n"
"    B       loc_FFAC122C \n"

"loc_FFAC1218:\n"
"    SUBS    R1, R6, R8 \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF9979F4 \n"

"loc_FFAC122C:\n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R2-R8,PC} \n"
"    .ltorg\n"         // added
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8D918C - 0xFF8D9810, length=418
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x43B0 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x59A80 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF8D91AC:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_006B8458 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8D91F8 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF8D935C \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF8D92E0 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8D912C \n"

"loc_FF8D91F8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF8D9224 \n"
"    BL      sub_FF8DA7D8 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_006B81EC /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF8D9224:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF8D9240 \n"
"    LDR     R2, [R0, #0xA8]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8D9808 \n"

"loc_FF8D9240:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF8D9290 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8D4568 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF88427C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_006B8120 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x170B \n"
"    BNE     loc_FF8D934C \n"

"loc_FF8D927C:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0xAC] \n"
"    LDR     R1, [R1, #0xA8] \n"
"    BLX     R1 \n"
"    B       loc_FF8D9808 \n"

"loc_FF8D9290:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF8D92D8 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8D912C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8D4578 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF88448C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_006B8120 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8D927C \n"
"    LDR     R2, =0x1715 \n"
"    B       loc_FF8D934C \n"

"loc_FF8D92D8:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF8D92F0 \n"

"loc_FF8D92E0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8D912C \n"
"    B       loc_FF8D927C \n"

"loc_FF8D92F0:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF8D9308 \n"
"    BL      sub_FF8C30F0 \n"
"    BL      sub_FF8C3F54 \n"
"    BL      sub_FF8C3A34 \n"
"    B       loc_FF8D927C \n"

"loc_FF8D9308:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF8D935C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF8D4598 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF8DA83C \n"
"    BL      sub_FF8C2D84 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_006B8034 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8D927C \n"
"    LDR     R2, =0x174D \n"

"loc_FF8D934C:\n"
"    LDR     R1, =0xFF8D4D1C /*'ExpDrv.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8D927C \n"

"loc_FF8D935C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF8D93C4 \n"
"    LDR     R1, [R0, #0x94] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8D7590 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R3, [R0, #0xA8] \n"
"    LDR     R2, [R0, #0xAC] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8DAB18 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R2, [R0, #0xB4] \n"
"    LDR     R3, [R0, #0xB0] \n"
"    B       loc_FF8D96CC \n"

"loc_FF8D93C4:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF8D946C \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8D7800 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF8D9418 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R12, [R0, #0xA8] \n"
"    LDR     R3, [R0, #0xAC] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF8D9450 \n"

"loc_FF8D9418:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R12, [R0, #0xA8] \n"
"    LDR     R3, [R0, #0xAC] \n"
"    CMPNE   R9, #6 \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BNE     loc_FF8D9464 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8D8E44 \n"

"loc_FF8D9450:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF8D90C4 \n"
"    B       loc_FF8D96D4 \n"

"loc_FF8D9464:\n"
"    BLX     R12 \n"
"    B       loc_FF8D96D4 \n"

"loc_FF8D946C:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF8D94B8 \n"
"    LDR     R1, [R0, #0x94] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8D64AC \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R3, [R0, #0xA8] \n"
"    LDR     R2, [R0, #0xAC] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8D68FC \n"
"    B       loc_FF8D96D4 \n"

"loc_FF8D94B8:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8D96BC \n"
"    B       loc_FF8D9574 \n"
"    B       loc_FF8D9574 \n"
"    B       loc_FF8D957C \n"
"    B       loc_FF8D9584 \n"
"    B       loc_FF8D9584 \n"
"    B       loc_FF8D9584 \n"
"    B       loc_FF8D9574 \n"
"    B       loc_FF8D957C \n"
"    B       loc_FF8D9584 \n"
"    B       loc_FF8D9584 \n"
"    B       loc_FF8D959C \n"
"    B       loc_FF8D959C \n"
"    B       loc_FF8D96A8 \n"
"    B       loc_FF8D96B0 \n"
"    B       loc_FF8D96B0 \n"
"    B       loc_FF8D96B0 \n"
"    B       loc_FF8D96B0 \n"
"    B       loc_FF8D96B8 \n"
"    B       loc_FF8D96BC \n"
"    B       loc_FF8D96BC \n"
"    B       loc_FF8D96BC \n"
"    B       loc_FF8D96BC \n"
"    B       loc_FF8D96BC \n"
"    B       loc_FF8D96BC \n"
"    B       loc_FF8D958C \n"
"    B       loc_FF8D9594 \n"
"    B       loc_FF8D9594 \n"
"    B       loc_FF8D9594 \n"
"    B       loc_FF8D95A8 \n"
"    B       loc_FF8D95A8 \n"
"    B       loc_FF8D95B0 \n"
"    B       loc_FF8D95E8 \n"
"    B       loc_FF8D9620 \n"
"    B       loc_FF8D9658 \n"
"    B       loc_FF8D9690 \n"
"    B       loc_FF8D9690 \n"
"    B       loc_FF8D96BC \n"
"    B       loc_FF8D96BC \n"
"    B       loc_FF8D9698 \n"
"    B       loc_FF8D96A0 \n"

"loc_FF8D9574:\n"
"    BL      sub_FF8D4B9C \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D957C:\n"
"    BL      sub_FF8D4E6C \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D9584:\n"
"    BL      sub_FF8D50AC \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D958C:\n"
"    BL      sub_FF8D53F4 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D9594:\n"
"    BL      sub_FF8D5624 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D959C:\n"
"    BL      sub_FF8D5A14_my \n"  // --> Patched. Old value = 0xFF8D5A14.
"    MOV     R8, #0 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D95A8:\n"
"    BL      sub_FF8D5BF0 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D95B0:\n"
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
"    BL      sub_FF8D6134 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D95E8:\n"
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
"    BL      sub_FF8DA888 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D9620:\n"
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
"    BL      sub_FF8DA9C4 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D9658:\n"
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
"    BL      sub_FF8DAA70 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D9690:\n"
"    BL      sub_FF8D6248 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D9698:\n"
"    BL      sub_FF8D6A14 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D96A0:\n"
"    BL      sub_FF8D6DBC \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D96A8:\n"
"    BL      sub_FF8D702C \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D96B0:\n"
"    BL      sub_FF8D71F8 \n"
"    B       loc_FF8D96BC \n"

"loc_FF8D96B8:\n"
"    BL      sub_FF8D7370 \n"

"loc_FF8D96BC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R2, [R0, #0xAC] \n"
"    LDR     R3, [R0, #0xA8] \n"

"loc_FF8D96CC:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF8D96D4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF8D970C \n"
"    BGT     loc_FF8D96FC \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF8D9740 \n"
"    B       loc_FF8D970C \n"

"loc_FF8D96FC:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF8D9740 \n"

"loc_FF8D970C:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF8D9740 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF8DAD3C /*_get_current_exp*/ \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF8D9740:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF8D9790 \n"
"    LDR     R1, [R0, #0x94] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x59A80 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006BCD9C \n"
"    LDR     R0, =0x59A8C \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006BCD9C \n"
"    LDR     R0, =0x59A98 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_006BCD9C \n"
"    B       loc_FF8D9808 \n"

"loc_FF8D9790:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8D97D4 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8D4968 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8D9804 \n"

"loc_FF8D97D4:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF8D4968 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF8D9804:\n"
"    BL      sub_FF8D4AE4 \n"

"loc_FF8D9808:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8DA7D8 \n"
"    B       loc_FF8D91AC \n"
);
}

/*************************************************************/
//** sub_FF8D5A14_my @ 0xFF8D5A14 - 0xFF8D5AD8, length=50
void __attribute__((naked,noinline)) sub_FF8D5A14_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x43B0 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R3, #1 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF8D4600 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8D47C8 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8D4820 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF8D4878 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8D48D0 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x59A98 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF8D5AAC \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF8D5AAC \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF8D4558 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF884304 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF8D5AB4 \n"

"loc_FF8D5AAC:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF8D5AB4:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF8D5AD0 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF8D45DC \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF8DA844 \n"

"loc_FF8D5AD0:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8C2DFC_my \n"  // --> Patched. Old value = 0xFF8C2DFC.
"    LDR     PC, =0xFF8D5ADC \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8C2DFC_my @ 0xFF8C2DFC - 0xFF8C2E70, length=30
void __attribute__((naked,noinline)) sub_FF8C2DFC_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x4004 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R2, #0x168 \n"
"    LDRNE   R1, =0xFF8C2BAC /*'Shutter.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R2, =0x16E \n"
"    LDREQ   R1, =0xFF8C2BAC /*'Shutter.c'*/ \n"
"    MOVEQ   R0, #0 \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    MOV     R4, R0 \n"
//"  BL      _sub_FF918EAC \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FF91BF18 \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    LDR     R2, =0x173 \n"
"    LDR     R1, =0xFF8C2BAC /*'Shutter.c'*/ \n"
"    MOV     R0, #0 \n"
"    B       _DebugAssert \n"
);
}