/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S
#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** dvlp_seq_task @ 0xFF076CD4 - 0xFF076DA8, length=54
void __attribute__((naked,noinline)) dvlp_seq_task() {
asm volatile (
"    STMFD   SP!, {R2-R6,LR} \n"
"    LDR     R6, =0x2F68 \n"

"loc_FF076CDC:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R6, #8] \n"
"    LDR     R1, [R6, #0x10] \n"
"    BL      sub_FF02AF24 /*_PostMessageQueue*/ \n"
"    LDR     R0, [R6, #4] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02ADD8 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x18A \n"
"    BNE     loc_FF076D24 \n"
"    LDR     R0, [R6, #8] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF02AEA0 /*_TryReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    MOVEQ   R5, #0 \n"
"    BEQ     loc_FF076D34 \n"
"    MOV     R1, #0x190 \n"

"loc_FF076D24:\n"
"    LDR     R0, =0xFF076E8C /*'SsDvlpSeq.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R2-R6,PC} \n"

"loc_FF076D34:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R0, [R1] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF076D58 \n"
"    CMP     R0, #1 \n"
"    BEQ     loc_FF076D64 \n"
"    CMP     R0, #2 \n"
"    BLEQ    sub_FF076808 \n"
"    B       loc_FF076D78 \n"

"loc_FF076D58:\n"
"    BL      capt_seq_hook_raw_here\n"      // +++  (9/8/2015 - moved here to fix RAW filename)
"    LDR     R0, [R1, #8] \n"
"    BL      sub_FF186A1C \n"
"    B       loc_FF076D78 \n"

"loc_FF076D64:\n"
"    LDR     R0, [R1, #8] \n"
"    BL      sub_FF186D94 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R0, [R0, #8] \n"
"    BL      sub_FF185DA4 \n"

"loc_FF076D78:\n"
"    LDR     R4, [SP, #4] \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, #0x76 \n"
"    LDREQ   R0, =0xFF076E8C /*'SsDvlpSeq.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R5, [R4, #4] \n"
"    LDR     R0, [R6, #4] \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02AEA0 /*_TryReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF076D34 \n"
"    B       loc_FF076CDC \n"
);
}

/*************************************************************/
//** capt_seq_task @ 0xFF074F1C - 0xFF0751E0, length=178
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    LDR     R5, =0x3E1F4 \n"
"    LDR     R7, =0x2F1C \n"
"    MOV     R6, #0 \n"

"loc_FF074F2C:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_FF02ADD8 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF074F58 \n"
"    LDR     R1, =0x47A \n"
"    LDR     R0, =0xFF074A44 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R9,PC} \n"

"loc_FF074F58:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x23 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF0751A8 \n"
"    B       loc_FF074FF8 \n"
"    B       loc_FF075010 \n"
"    B       loc_FF075048 \n"
"    B       loc_FF07505C \n"
"    B       loc_FF075054 \n"
"    B       loc_FF075068 \n"
"    B       loc_FF075070 \n"
"    B       loc_FF075078 \n"
"    B       loc_FF075094 \n"
"    B       loc_FF0750D4 \n"
"    B       loc_FF0750A0 \n"
"    B       loc_FF0750AC \n"
"    B       loc_FF0750B4 \n"
"    B       loc_FF0750BC \n"
"    B       loc_FF0750C4 \n"
"    B       loc_FF0750CC \n"
"    B       loc_FF0750DC \n"
"    B       loc_FF0750E4 \n"
"    B       loc_FF0750EC \n"
"    B       loc_FF0750F4 \n"
"    B       loc_FF0750FC \n"
"    B       loc_FF075108 \n"
"    B       loc_FF075110 \n"
"    B       loc_FF075118 \n"
"    B       loc_FF075120 \n"
"    B       loc_FF075128 \n"
"    B       loc_FF075134 \n"
"    B       loc_FF07513C \n"
"    B       loc_FF075144 \n"
"    B       loc_FF07514C \n"
"    B       loc_FF075154 \n"
"    B       loc_FF07515C \n"
"    B       loc_FF075164 \n"
"    B       loc_FF075170 \n"
"    B       loc_FF0751B4 \n"

"loc_FF074FF8:\n"
"    BL      shooting_expo_iso_override\n"      // added
"    BL      sub_FF0756E8 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF072758 \n"
"    MOV     R0, #0\n"                          // added
"    STR     R0, [R5,#0x28]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
//"  LDR     R0, [R5, #0x28] \n"  // above patch makes these three lines redundant
//"  CMP     R0, #0 \n"
//"  BLNE    _sub_FF184F18 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075010:\n"
"    LDR     R8, [R0, #0xC] \n"
"    MOV     R0, R8 \n"
"    BL      sub_FF184DA8_my \n"  // --> Patched. Old value = 0xFF184DA8.
"    MOV     R4, R0 \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF0730E8 \n"
"    TST     R4, #1 \n"
"    BNE     loc_FF075040 \n"
"    MOV     R0, R8 \n"
"    BL      sub_FF1847F0 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075040:\n"
"    BL      sub_FF1847C0 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075048:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF0759C8 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075054:\n"
"    BL      sub_FF075368 \n"
"    B       loc_FF075060 \n"

"loc_FF07505C:\n"
"    BL      sub_FF0756C8 \n"

"loc_FF075060:\n"
"    STR     R6, [R5, #0x28] \n"
"    B       loc_FF0751B4 \n"

"loc_FF075068:\n"
"    BL      sub_FF0756D0 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075070:\n"
"    BL      sub_FF0758BC \n"
"    B       loc_FF075098 \n"

"loc_FF075078:\n"
"    LDR     R4, [R0, #0xC] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF184F6C \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #9 \n"
"    BL      sub_FF0730E8 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075094:\n"
"    BL      sub_FF075930 \n"

"loc_FF075098:\n"
"    BL      sub_FF072758 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750A0:\n"
"    LDR     R0, [R5, #0x58] \n"
"    BL      sub_FF0760B0 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750AC:\n"
"    BL      sub_FF076384 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750B4:\n"
"    BL      sub_FF0763E8 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750BC:\n"
"    BL      sub_FF0765E4 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750C4:\n"
"    BL      sub_FF076A34 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750CC:\n"
"    BL      sub_FF076AE4 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750D4:\n"
"    BL      sub_FF0756C8 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750DC:\n"
"    BL      sub_FF183B04 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750E4:\n"
"    BL      sub_FF183D18 \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750EC:\n"
"    BL      sub_FF183DBC \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750F4:\n"
"    BL      sub_FF183E8C \n"
"    B       loc_FF0751B4 \n"

"loc_FF0750FC:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF18409C \n"
"    B       loc_FF0751B4 \n"

"loc_FF075108:\n"
"    BL      sub_FF184204 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075110:\n"
"    BL      sub_FF18429C \n"
"    B       loc_FF0751B4 \n"

"loc_FF075118:\n"
"    BL      sub_FF18437C \n"
"    B       loc_FF0751B4 \n"

"loc_FF075120:\n"
"    BL      sub_FF075B38 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075128:\n"
"    BL      sub_FF075BCC \n"
"    BL      sub_FF028484 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075134:\n"
"    BL      sub_FF183F58 \n"
"    B       loc_FF0751B4 \n"

"loc_FF07513C:\n"
"    BL      sub_FF183F98 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075144:\n"
"    BL      sub_FF078EF0 \n"
"    B       loc_FF0751B4 \n"

"loc_FF07514C:\n"
"    BL      sub_FF078F6C \n"
"    B       loc_FF0751B4 \n"

"loc_FF075154:\n"
"    BL      sub_FF1844B4 \n"
"    B       loc_FF0751B4 \n"

"loc_FF07515C:\n"
"    BL      sub_FF184518 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075164:\n"
"    BL      sub_FF078FC8 \n"
"    BL      sub_FF078F88 \n"
"    B       loc_FF0751B4 \n"

"loc_FF075170:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF185744 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF18586C \n"
"    LDRH    R0, [R5, #0x98] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x8200 \n"
"    SUBNES  R1, R1, #0x2A \n"
"    BNE     loc_FF0751B4 \n"
"    BL      sub_FF078F6C \n"
"    BL      sub_FF079584 \n"
"    BL      sub_FF0793EC \n"
"    B       loc_FF0751B4 \n"

"loc_FF0751A8:\n"
"    LDR     R1, =0x5DB \n"
"    LDR     R0, =0xFF074A44 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF0751B4:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_FF07FAC8 /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0xFF074A44 /*'SsShootTask.c'*/ \n"
"    MOVEQ   R1, #0x118 \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R4, #8] \n"
"    B       loc_FF074F2C \n"
);
}

/*************************************************************/
//** sub_FF184DA8_my @ 0xFF184DA8 - 0xFF184F14, length=92
void __attribute__((naked,noinline)) sub_FF184DA8_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x3E1F4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #0x28] \n"
"    MOV     R6, #0 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF184E2C \n"
"    LDR     R0, [R5, #0xBC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF184E14 \n"
"    LDRH    R0, [R5, #0x96] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF184DF8 \n"
"    BL      sub_FF022D20 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF184E2C \n"
"    BL      sub_FF07AB88 \n"
"    B       loc_FF184E24 \n"

"loc_FF184DF8:\n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF07AB20 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF184E2C \n"
"    BL      sub_FF1855D8 \n"
"    BL      sub_FF072DFC \n"
"    B       loc_FF184E24 \n"

"loc_FF184E14:\n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF07AB20 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF184E2C \n"

"loc_FF184E24:\n"
"    MOV     R0, #1 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF184E2C:\n"
"    BL      sub_FF0756D8 \n"
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF184F00 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF184678 \n"
"    TST     R0, #1 \n"
"    LDMNEFD SP!, {R3-R7,PC} \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF184AB0 \n"
"    BL      sub_FF18551C \n"
"    LDR     R0, [R5, #0xBC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF184E78 \n"
"    LDRH    R0, [R5, #0x96] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF184E80 \n"

"loc_FF184E78:\n"
"    MOV     R0, #2 \n"
"    BL      sub_FF07C4B4 \n"
"    BL      wait_until_remote_button_is_released\n"    // added
"    BL      capt_seq_hook_set_nr\n"                    // added

"loc_FF184E80:\n"
"    LDRH    R0, [R5] \n"
"    SUB     R1, R0, #0x8200 \n"
"    SUBS    R1, R1, #0x11 \n"
"    LDREQ   R0, [R4, #0x14] \n"
"    BLEQ    sub_FF0704BC \n"
"    LDRH    R0, [R5] \n"
"    SUB     R1, R0, #0x8200 \n"
"    SUBS    R1, R1, #0x2D \n"
"    BNE     loc_FF184EF0 \n"
"    MOV     R5, #1 \n"
"    MOV     R2, #2 \n"
"    MOV     R1, SP \n"
"    ADD     R0, R2, #0x15C \n"
"    STR     R5, [SP] \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0xBC \n"
"    LDRNE   R0, =0xFF185018 /*'SsCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDRH    R0, [SP] \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF184EE8 \n"
"    MOV     R0, R4 \n"
"    STR     R5, [R4, #0xE4] \n"
"    BL      sub_FF30E174 \n"
"    B       loc_FF184EF8 \n"

"loc_FF184EE8:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [R4, #0xE4] \n"

"loc_FF184EF0:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FF30DE24 \n"

"loc_FF184EF8:\n"
"    MOV     R6, R0 \n"
"    B       loc_FF184F10 \n"

"loc_FF184F00:\n"
"    LDR     R0, =0x74C0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R6, #0x1D \n"

"loc_FF184F10:\n"
"    MOV     R0, R6 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF0BDD18 - 0xFF0BE37C, length=410
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x24 \n"
"    LDR     R6, =0x4348 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x59ADC \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x14 \n"
"    STR     R0, [SP, #0x10] \n"

"loc_FF0BDD38:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x20 \n"
"    BL      sub_FF02ADD8 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0x10] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF0BDD84 \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF0BDEE4 \n"
"    CMP     R0, #0x29 \n"
"    BEQ     loc_FF0BDE6C \n"
"    ADD     R1, SP, #0x10 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0BDCC8 \n"

"loc_FF0BDD84:\n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF0BDDB0 \n"
"    BL      sub_FF0BF144 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF07FAC8 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x24 \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF0BDDB0:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF0BDDCC \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF0BE374 \n"

"loc_FF0BDDCC:\n"
"    CMP     R1, #0x27 \n"
"    BNE     loc_FF0BDE1C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF07FAFC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0B8FAC \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF17581C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF07FA08 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1756 \n"
"    BNE     loc_FF0BDED8 \n"

"loc_FF0BDE08:\n"
"    LDR     R1, [SP, #0x20] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF0BE374 \n"

"loc_FF0BDE1C:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF0BDE64 \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF0BDCC8 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF07FAFC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0B8FBC \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF176224 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF07FA08 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0BDE08 \n"
"    LDR     R1, =0x1760 \n"
"    B       loc_FF0BDED8 \n"

"loc_FF0BDE64:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF0BDE7C \n"

"loc_FF0BDE6C:\n"
"    LDR     R0, [SP, #0x20] \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF0BDCC8 \n"
"    B       loc_FF0BDE08 \n"

"loc_FF0BDE7C:\n"
"    CMP     R1, #0x2C \n"
"    BNE     loc_FF0BDE94 \n"
"    BL      sub_FF0AA8EC \n"
"    BL      sub_FF0AB55C \n"
"    BL      sub_FF0AB0D4 \n"
"    B       loc_FF0BDE08 \n"

"loc_FF0BDE94:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF0BDEE4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF07FAFC /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF0B8FDC \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF0AA360 \n"
"    BL      sub_FF0AA5F0 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF07F924 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0BDE08 \n"
"    LDR     R1, =0x1788 \n"

"loc_FF0BDED8:\n"
"    LDR     R0, =0xFF0B976C /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF0BDE08 \n"

"loc_FF0BDEE4:\n"
"    LDR     R0, [SP, #0x20] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF0BDF4C \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0BC020 \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x20] \n"
"    BL      sub_FF0BF558 \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_FF0BE260 \n"

"loc_FF0BDF4C:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF0BE004 \n"
"    ADD     R3, SP, #0x10 \n"
"    ADD     R2, SP, #4 \n"
"    ADD     R1, SP, #0x14 \n"
"    BL      sub_FF0BC288 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF0BDFA0 \n"
"    LDR     R0, [SP, #0x20] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    ADD     R0, SP, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF0BDFD8 \n"

"loc_FF0BDFA0:\n"
"    LDR     R0, [SP, #0x20] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_FF0BDFEC \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    ADD     R0, SP, #4 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x20] \n"
"    ADD     R2, SP, #4 \n"
"    ADD     R1, SP, #0x14 \n"
"    BL      sub_FF0BDA14 \n"

"loc_FF0BDFD8:\n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R2, [SP, #0x10] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF0BDC68 \n"
"    B       loc_FF0BE268 \n"

"loc_FF0BDFEC:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF0BE268 \n"

"loc_FF0BE004:\n"
"    CMP     R1, #0x23 \n"
"    CMPNE   R1, #0x24 \n"
"    BNE     loc_FF0BE050 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0BAE10 \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x20] \n"
"    BL      sub_FF0BB2FC \n"
"    B       loc_FF0BE268 \n"

"loc_FF0BE050:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x27 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF0BE250 \n"
"    B       loc_FF0BE108 \n"
"    B       loc_FF0BE108 \n"
"    B       loc_FF0BE110 \n"
"    B       loc_FF0BE118 \n"
"    B       loc_FF0BE118 \n"
"    B       loc_FF0BE118 \n"
"    B       loc_FF0BE108 \n"
"    B       loc_FF0BE110 \n"
"    B       loc_FF0BE118 \n"
"    B       loc_FF0BE118 \n"
"    B       loc_FF0BE130 \n"
"    B       loc_FF0BE130 \n"
"    B       loc_FF0BE23C \n"
"    B       loc_FF0BE244 \n"
"    B       loc_FF0BE244 \n"
"    B       loc_FF0BE244 \n"
"    B       loc_FF0BE244 \n"
"    B       loc_FF0BE24C \n"
"    B       loc_FF0BE250 \n"
"    B       loc_FF0BE250 \n"
"    B       loc_FF0BE250 \n"
"    B       loc_FF0BE250 \n"
"    B       loc_FF0BE250 \n"
"    B       loc_FF0BE250 \n"
"    B       loc_FF0BE120 \n"
"    B       loc_FF0BE128 \n"
"    B       loc_FF0BE128 \n"
"    B       loc_FF0BE13C \n"
"    B       loc_FF0BE13C \n"
"    B       loc_FF0BE144 \n"
"    B       loc_FF0BE17C \n"
"    B       loc_FF0BE1B4 \n"
"    B       loc_FF0BE1EC \n"
"    B       loc_FF0BE224 \n"
"    B       loc_FF0BE224 \n"
"    B       loc_FF0BE250 \n"
"    B       loc_FF0BE250 \n"
"    B       loc_FF0BE22C \n"
"    B       loc_FF0BE234 \n"

"loc_FF0BE108:\n"
"    BL      sub_FF0B95A0 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE110:\n"
"    BL      sub_FF0B9898 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE118:\n"
"    BL      sub_FF0B9B00 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE120:\n"
"    BL      sub_FF0B9DB4 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE128:\n"
"    BL      sub_FF0B9FCC \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE130:\n"
"    BL      sub_FF0BA488_my \n"  // --> Patched. Old value = 0xFF0BA488.
"    MOV     R8, #0 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE13C:\n"
"    BL      sub_FF0BA66C \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE144:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x18] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    BL      sub_FF0BF1D8 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE17C:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x18] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    BL      sub_FF0BF358 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE1B4:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x18] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    BL      sub_FF0BF40C \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE1EC:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x18] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    BL      sub_FF0BF4B4 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE224:\n"
"    BL      sub_FF0BABE8 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE22C:\n"
"    BL      sub_FF0BB400 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE234:\n"
"    BL      sub_FF0BB90C \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE23C:\n"
"    BL      sub_FF0BBAEC \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE244:\n"
"    BL      sub_FF0BBCA8 \n"
"    B       loc_FF0BE250 \n"

"loc_FF0BE24C:\n"
"    BL      sub_FF0BBE18 \n"

"loc_FF0BE250:\n"
"    LDR     R0, [SP, #0x20] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_FF0BE260:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF0BE268:\n"
"    LDR     R1, [SP, #0x20] \n"
"    LDR     R0, [R1] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF0BE2A0 \n"
"    BGT     loc_FF0BE290 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF0BE2B0 \n"
"    B       loc_FF0BE2A0 \n"

"loc_FF0BE290:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF0BE2B0 \n"

"loc_FF0BE2A0:\n"
"    LDRH    R0, [R4] \n"
"    STRH    R0, [SP, #0x14] \n"
"    LDRH    R0, [R4, #8] \n"
"    STRH    R0, [SP, #0x1C] \n"

"loc_FF0BE2B0:\n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF0BE2FC \n"
"    LDR     R0, [R1, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R0, R0, R0, LSL#1 \n"
"    ADD     R0, R1, R0, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x59ADC \n"
"    ADD     R1, SP, #0x14 \n"
"    BL      sub_FF3CA088 \n"
"    LDR     R0, =0x59AE8 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x14 \n"
"    BL      sub_FF3CA088 \n"
"    LDR     R0, =0x59AF4 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_FF3CA088 \n"
"    B       loc_FF0BE374 \n"

"loc_FF0BE2FC:\n"
"    LDR     R0, [R1] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF0BE340 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0B9374 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF0BE370 \n"

"loc_FF0BE340:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF0B9374 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF0BE370:\n"
"    BL      sub_FF0B94EC \n"

"loc_FF0BE374:\n"
"    LDR     R0, [SP, #0x20] \n"
"    BL      sub_FF0BF144 \n"
"    B       loc_FF0BDD38 \n"
);
}

/*************************************************************/
//** sub_FF0BA488_my @ 0xFF0BA488 - 0xFF0BA550, length=51
void __attribute__((naked,noinline)) sub_FF0BA488_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x4348 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_FF07FAFC /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF0B903C \n"
"    MOV     R5, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF0B918C \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF0B91E4 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF0B923C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0B9294 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #0xE] \n"
"    BL      sub_FF0BF174 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x59AF4 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R5, #0 \n"
"    MOVEQ   R6, R5 \n"
"    BEQ     loc_FF0BA524 \n"
"    CMP     R5, #1 \n"
"    BNE     loc_FF0BA524 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF0B8F9C \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF175B40 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF0BA52C \n"

"loc_FF0BA524:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF0BA52C:\n"
"    CMP     R6, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF0BA548 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF0B9020 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF0BF194 \n"

"loc_FF0BA548:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF0AA65C_my \n"  // --> Patched. Old value = 0xFF0AA65C.
"    LDR     PC, =0xFF0BA554 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF0AA65C_my @ 0xFF0AA65C - 0xFF0AA69C, length=17
void __attribute__((naked,noinline)) sub_FF0AA65C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x3FF0 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0x146 \n"
"    LDRNE   R0, =0xFF0AA494 /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    MOVEQ   R1, #0x14C \n"
"    LDREQ   R0, =0xFF0AA494 /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF0AA6A0 \n"  // Continue in firmware
);
}
