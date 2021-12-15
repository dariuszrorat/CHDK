/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

void change_video_tables(__attribute__ ((unused))int a, __attribute__ ((unused))int b) {}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

/*************************************************************/
//** movie_record_task @ 0xF8235E00 - 0xF8235FC4, length=114
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R8, =sub_F8235A30_my \n"  // --> Patched. Old value = 0xF8235A30.
"    LDR     R4, =0x9C78 \n"
"    LDR     R9, =0x65B \n"
"    LDR     R10, =0x2710 \n"
"    MVN     R7, #0 \n"
"    MOV     R5, #1 \n"
"    MOV     R6, #0 \n"

"loc_F8235E20:\n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_0068F164 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x30] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0x10] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_F8235FA8 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xF \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_F8235FA8 \n"
"    B       loc_F8235EF0 \n"
"    B       loc_F8235F14 \n"
"    B       loc_F8235F24 \n"
"    B       loc_F8235F2C \n"
"    B       loc_F8235F34 \n"
"    B       loc_F8235F3C \n"
"    B       loc_F8235EF8 \n"
"    B       loc_F8235F68 \n"
"    B       loc_F8235F94 \n"
"    B       loc_F8235F9C \n"
"    B       loc_F8235F04 \n"
"    B       loc_F8235FA8 \n"
"    B       loc_F8235FA4 \n"
"    B       loc_F8235ECC \n"
"    B       loc_F8235EA0 \n"

"loc_F8235EA0:\n"
"    STR     R6, [R4, #0x40] \n"
"    STR     R6, [R4, #0x34] \n"
"    STR     R7, [R4, #0xE4] \n"
"    STRH    R6, [R4, #6] \n"
"    STR     R8, [R4, #0xCC] \n"
"    LDR     R0, [R4, #0x10] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x10] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_F8235EE8 \n"

"loc_F8235ECC:\n"
"    STR     R6, [R4, #0x40] \n"
"    STR     R7, [R4, #0xE4] \n"
"    STR     R8, [R4, #0xCC] \n"
"    LDR     R0, [R4, #0x10] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x10] \n"
"    STR     R5, [R4, #0x44] \n"

"loc_F8235EE8:\n"
"    STR     R5, [R4, #8] \n"
"    B       loc_F8235FA8 \n"

"loc_F8235EF0:\n"
);
if (conf.ext_video_time == 1)
{
asm volatile (
"    BL      sub_F8235694_my \n"  // --> Patched. Old value = 0xF8235694.
);
}
else
{
asm volatile (
"    BL      sub_F8235694 \n"
);
}
asm volatile (
"    B       loc_F8235FA8 \n"

"loc_F8235EF8:\n"
"    LDR     R1, [R4, #0xCC] \n"
"    BLX     R1 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    B       loc_F8235FA8 \n"

"loc_F8235F04:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_F84330D8 \n"
"    B       loc_F8235FA8 \n"

"loc_F8235F14:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R5, [R4, #0x34] \n"
"    B       loc_F8235FA8 \n"

"loc_F8235F24:\n"
"    BL      sub_F8234BEC \n"
"    B       loc_F8235FA8 \n"

"loc_F8235F2C:\n"
"    BL      sub_F8234AD4 \n"
"    B       loc_F8235FA8 \n"

"loc_F8235F34:\n"
"    BL      sub_F823478C \n"
"    B       loc_F8235FA8 \n"

"loc_F8235F3C:\n"
"    LDR     R1, [R4, #0x94] \n"
"    LDR     R0, =0x4840F640 \n"
"    CMP     R1, #0 \n"
"    LDREQ   R1, =0xF8234750 \n"
"    LDREQ   R0, [R4, #0x98] \n"
"    BEQ     loc_F8235F60 \n"
"    BL      sub_F8433D94 \n"
"    LDR     R1, =0xF8234750 \n"
"    MOV     R0, #0 \n"

"loc_F8235F60:\n"
"    BL      sub_F8432238 \n"
"    B       loc_F8235FA8 \n"

"loc_F8235F68:\n"
"    LDR     R0, =0x141774 \n"
"    LDR     R0, [R0, #8] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0xF82346D8 \n"
"    LDRNE   R0, =0xF823472C \n"
"    MOVNE   R3, #0 \n"
"    MOVNE   R1, R3 \n"
"    BLNE    sub_F807E8E4 \n"
"    MOV     R0, #3 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_F8235FA8 \n"

"loc_F8235F94:\n"
"    BL      sub_F8234658 \n"
"    B       loc_F8235FA8 \n"

"loc_F8235F9C:\n"
"    BL      sub_F82369FC \n"
"    B       loc_F8235FA8 \n"

"loc_F8235FA4:\n"
"    BL      sub_F823691C \n"

"loc_F8235FA8:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xF82342F0 /*'MovieRecorder.c'*/ \n"
"    STR     R6, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x2C] \n"
"    MOV     R2, R10 \n"
"    BL      sub_0068B044 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_F8235E20 \n"
);
}

/*************************************************************/
//** sub_F8235694_my @ 0xF8235694 - 0xF82359C4, length=205
void __attribute__((naked,noinline)) sub_F8235694_my() {
asm volatile (
"    STMFD   SP!, {R0-R10,LR} \n"
"    LDR     R6, =0x9C78 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R6, #0x34] \n"
"    STR     R0, [R6, #0x38] \n"
"    MOV     R0, R6 \n"
"    LDR     R4, [R0, #0x58] \n"
"    LDRH    R1, [R6, #6] \n"
"    MOV     R0, #0x3E8 \n"
"    MUL     R0, R4, R0 \n"
"    LDR     R8, =0xFFF00 \n"
"    CMP     R1, #0 \n"
"    MOV     R2, #1 \n"
"    BNE     loc_F82356DC \n"
"    LDR     R1, [R6, #0x80] \n"
"    CMP     R1, #0 \n"
"    BNE     loc_F82356EC \n"
"    B       loc_F82356E4 \n"

"loc_F82356DC:\n"
"    CMP     R1, #3 \n"
"    BNE     loc_F82356EC \n"

"loc_F82356E4:\n"
"    STR     R2, [R6, #0x48] \n"
"    B       loc_F82356F8 \n"

"loc_F82356EC:\n"
"    MOV     R1, #0x3E8 \n"
"    BL      sub_006ACF94 \n"
"    STR     R0, [R6, #0x48] \n"

"loc_F82356F8:\n"
"    LDR     R5, =0x141774 \n"
"    MOV     R7, #2 \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_F8235764 \n"
"    CMP     R4, #0x18 \n"
"    MOV     R0, #4 \n"
"    BEQ     loc_F8235750 \n"
"    BGT     loc_F8235738 \n"
"    CMP     R4, #0xA \n"
"    CMPNE   R4, #0xF \n"
"    STREQ   R7, [R5, #0x14] \n"
"    BEQ     loc_F8235764 \n"
"    CMP     R4, #0x14 \n"
"    BNE     loc_F8235758 \n"
"    B       loc_F8235750 \n"

"loc_F8235738:\n"
"    CMP     R4, #0x19 \n"
"    CMPNE   R4, #0x1E \n"
"    BEQ     loc_F8235750 \n"
"    CMP     R4, #0x3C \n"
"    BNE     loc_F8235758 \n"
"    MOV     R0, #8 \n"

"loc_F8235750:\n"
"    STR     R0, [R5, #0x14] \n"
"    B       loc_F8235764 \n"

"loc_F8235758:\n"
"    LDR     R1, =0x74C \n"
"    LDR     R0, =0xF82342F0 /*'MovieRecorder.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_F8235764:\n"
"    LDR     R0, [R6, #0x64] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_F823577C \n"
"    BL      sub_F83DCC7C \n"
"    LDR     R0, =0x14178C \n"
"    BL      sub_F842E560 \n"

"loc_F823577C:\n"
"    LDR     R2, =0x9C7A \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xAA \n"
"    BL      sub_F80D7178 \n"
"    LDR     R2, =0x9C7C \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xA9 \n"
"    BL      sub_F80D7178 \n"
"    LDR     R2, =0x9CC8 \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA2 \n"
"    BL      sub_F80D7178 \n"
"    LDR     R2, =0x9CCC \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA3 \n"
"    BL      sub_F80D7178 \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x9D70 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, #0xF \n"
"    BLNE    _exmem_ualloc \n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R4, =0x9D70 \n"
"    LDR     R9, =0x14175C \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #2 \n"
"    BNE     loc_F82358B0 \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x483FC000 \n"
"    STRNE   R0, [R4] \n"
"    BNE     loc_F82358B0 \n"
"    LDR     R1, =0x484B4600 \n"
"    LDR     R0, =0x3870600 \n"
"    STR     R1, [R4] \n"
"    STR     R0, [R4, #4] \n"
"    LDMIA   R9, {R0,R2} \n"
"    MUL     R0, R2, R0 \n"
"    MOV     R3, R0, LSL#1 \n"
"    CMP     R3, R8 \n"
"    STR     R3, [R6, #0x8C] \n"
"    MOVCC   R2, #0 \n"
"    STR     R1, [R6, #0x90] \n"
"    BCC     loc_F8235878 \n"
"    MOV     R2, #0 \n"
"    STMEA   SP, {R1,R2,R8} \n"
"    MOV     R3, R2 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_F83D561C \n"
"    LDR     R0, [R6, #0x8C] \n"
"    MOV     R2, #0 \n"
"    SUB     R3, R0, #0xF0000 \n"
"    LDR     R0, [R6, #0x90] \n"
"    SUB     R3, R3, #0xFF00 \n"
"    ADD     R1, R0, #0xF0000 \n"
"    ADD     R1, R1, #0xFF00 \n"

"loc_F8235878:\n"
"    STMEA   SP, {R1-R3} \n"
"    MOV     R3, #0 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_F83D561C \n"
"    LDR     R1, [R4] \n"
"    LDR     R0, [R6, #0x8C] \n"
"    ADD     R1, R1, R0, LSL#1 \n"
"    STR     R1, [R4] \n"
"    LDR     R1, [R4, #4] \n"
"    RSB     R0, R0, #0 \n"
"    ADD     R0, R1, R0, LSL#1 \n"
"    STR     R0, [R4, #4] \n"

"loc_F82358B0:\n"
"    LDR     R2, =0x141774 \n"
"    LDR     R3, =0xF8235660 \n"
"    LDR     R0, [R4, #4] \n"
"    LDR     R1, [R4] \n"
"    STRD    R2, [SP] \n"
"    SUB     R3, R2, #0x18 \n"
"    MOV     R2, R0 \n"
"    LDR     R0, [R6, #0x80] \n"
"    BL      sub_F84315E8_my \n"  // --> Patched. Old value = 0xF84315E8.
"    LDRD    R0, [R6, #0xF0] \n"
"    LDR     R2, [R6, #0xA4] \n"
"    BL      sub_F8431C20 \n"
"    LDR     R3, =0x9CF0 \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R6, #0x64] \n"
"    LDR     R1, [R9, #8] \n"
"    AND     R2, R0, #0xFF \n"
"    LDR     R0, [R9] \n"
"    SUB     R3, R3, #4 \n"
"    BL      sub_F842E0BC \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #2 \n"
"    LDREQ   R0, =0xF8235360 \n"
"    STREQ   R0, [R6, #0xCC] \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xF8234F1C \n"
"    STREQ   R1, [R6, #0xCC] \n"
"    LDR     R2, [R6, #0x10] \n"
"    LDR     R1, =0xF87C227C \n"
"    CMP     R2, #2 \n"
"    BNE     loc_F8235954 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R9, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_F83DBA08 \n"
"    LDR     R0, =0xF8234ED4 \n"
"    MOV     R1, #0 \n"
"    BL      sub_F83DBF94 \n"
"    B       loc_F823598C \n"

"loc_F8235954:\n"
"    CMP     R0, #0 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R9, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BNE     loc_F823597C \n"
"    LDR     R1, [R6, #0x88] \n"
"    BL      sub_F83DC074 \n"
"    BL      sub_F83DC0F8 \n"
"    B       loc_F823598C \n"

"loc_F823597C:\n"
"    BL      sub_F83D9BF4 \n"
"    LDR     R0, =0xF8234EC8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_F83DA404 \n"

"loc_F823598C:\n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_F82359C0 \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_F8432E40 \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_F807EB50 \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_F8432E40 \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_F807EB50 \n"

"loc_F82359C0:\n"
"    STR     R7, [R6, #0x44] \n"
"    LDMFD   SP!, {R0-R10,PC} \n"
);
}

/*************************************************************/
//** sub_F84315E8_my @ 0xF84315E8 - 0xF8431954, length=220
void __attribute__((naked,noinline)) sub_F84315E8_my() {
asm volatile (
"    STMFD   SP!, {R0-R11,LR} \n"
"    MOV     R9, R0 \n"
"    LDR     R0, [R3, #0x10] \n"
"    SUB     SP, SP, #4 \n"
"    CMP     R0, #0 \n"
"    LDR     R7, [SP, #0x38] \n"
"    LDREQ   R1, =0x3B7 \n"
"    LDREQ   R0, =0xF842EBCC /*'MovWriter.c'*/ \n"
"    MOV     R6, #0 \n"
"    MOV     R4, R3 \n"
"    MOV     R5, R6 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R8, =0x13220 \n"
"    CMP     R9, #0 \n"
"    MOV     R11, #0 \n"
"    STR     R9, [R8, #0xA0] \n"
"    MOVEQ   R0, #1 \n"
"    STRNE   R11, [R8, #0xE8] \n"
"    STREQ   R0, [R8, #0xE8] \n"
"    LDR     R0, [R4] \n"
"    LDR     R3, =0x61A8 \n"
"    STR     R0, [R8, #0xF0] \n"
"    LDR     R0, [R4, #4] \n"
"    LDR     R1, =0x7530 \n"
"    STR     R0, [R8, #0xF4] \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0x18 \n"
"    STR     R0, [R8, #0x100] \n"
"    LDR     R9, [R4, #8] \n"
"    LDR     R0, =0x3E9 \n"
"    CMP     R9, #0xF \n"
"    MOV     R12, #0x3E8 \n"
"    MOV     R10, #0x1E \n"
"    ADDCC   PC, PC, R9, LSL#2 \n"
"    B       loc_F8431740 \n"
"    B       loc_F84316C8 \n"
"    B       loc_F84316C0 \n"
"    B       loc_F84316B0 \n"
"    B       loc_F843171C \n"
"    B       loc_F843172C \n"
"    B       loc_F8431740 \n"
"    B       loc_F8431740 \n"
"    B       loc_F8431740 \n"
"    B       loc_F8431740 \n"
"    B       loc_F84316E8 \n"
"    B       loc_F84316E0 \n"
"    B       loc_F84316D8 \n"
"    B       loc_F8431714 \n"
"    B       loc_F843170C \n"
"    B       loc_F84316F8 \n"

"loc_F84316B0:\n"
"    LDR     R5, =0x5DC0 \n"
"    STR     R2, [R8, #0xF8] \n"
"    STR     R5, [R8, #0x154] \n"
"    B       loc_F84316D0 \n"

"loc_F84316C0:\n"
"    MOV     R5, R3 \n"
"    B       loc_F84316FC \n"

"loc_F84316C8:\n"
"    MOV     R5, R1 \n"
"    B       loc_F84316EC \n"

"loc_F84316D0:\n"
"    STR     R0, [R8, #0x158] \n"
"    B       loc_F843174C \n"

"loc_F84316D8:\n"
"    LDR     R5, =0x5DC \n"
"    B       loc_F84316EC \n"

"loc_F84316E0:\n"
"    LDR     R5, =0xBB8 \n"
"    B       loc_F84316EC \n"

"loc_F84316E8:\n"
"    LDR     R5, =0x1770 \n"

"loc_F84316EC:\n"
"    STR     R1, [R8, #0x154] \n"
"    STR     R10, [R8, #0xF8] \n"
"    B       loc_F84316D0 \n"

"loc_F84316F8:\n"
"    LDR     R5, =0x4E2 \n"

"loc_F84316FC:\n"
"    STR     R2, [R8, #0xF8] \n"
"    STR     R3, [R8, #0x154] \n"
"    STR     R12, [R8, #0x158] \n"
"    B       loc_F843174C \n"

"loc_F843170C:\n"
"    LDR     R5, =0x9C4 \n"
"    B       loc_F84316FC \n"

"loc_F8431714:\n"
"    LDR     R5, =0x1388 \n"
"    B       loc_F84316FC \n"

"loc_F843171C:\n"
"    STR     R1, [R8, #0x154] \n"
"    LDR     R5, =0x57600000 \n"  // --> Patched. Old value = 0x3A980. 2hrs
"    MOV     R1, #0xF0 \n"
"    B       loc_F8431738 \n"

"loc_F843172C:\n"
"    LDR     R5, =0x28800000 \n"  // --> Patched. Old value = 0x1D4C0. 2hrs
"    STR     R1, [R8, #0x154] \n"
"    MOV     R1, #0x78 \n"

"loc_F8431738:\n"
"    STR     R1, [R8, #0xF8] \n"
"    B       loc_F84316D0 \n"

"loc_F8431740:\n"
"    LDR     R1, =0x411 \n"
"    LDR     R0, =0xF842EBCC /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_F843174C:\n"
"    LDR     R0, [R8, #0xF8] \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0xE0F. 2hrs
"    MOV     R0, R0, LSR#1 \n"
"    STR     R0, [R8, #0xFC] \n"
"    LDR     R0, [R7] \n"
"    STR     R0, [R8, #0x104] \n"
"    LDRH    R0, [R7, #0x10] \n"
"    STR     R0, [R8, #0x108] \n"
"    LDR     R0, [R7, #4] \n"
"    STRH    R0, [R8, #2] \n"
"    LDR     R0, [R7, #8] \n"
"    STRH    R0, [R8, #4] \n"
"    LDR     R0, [R7, #0x14] \n"
"    STR     R0, [R8, #0x10C] \n"
"    LDR     R0, [SP, #0x3C] \n"
"    STR     R0, [R8, #0x150] \n"
"    LDR     R0, [R8, #0xF0] \n"
"    CMP     R0, #0x140 \n"
"    MOVEQ   R0, #0x20000 \n"
"    MOVEQ   R6, #1 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_F84317E4 \n"
"    CMP     R0, #0x280 \n"
"    LDREQ   R0, =0x7A760 \n"
"    MOVEQ   R6, #2 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_F84317E4 \n"
"    CMP     R0, #0x500 \n"
"    LDREQ   R0, =0x11DA50 \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0x707. 2hrs
"    MOVEQ   R6, #4 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_F84317E4 \n"
"    CMP     R0, #0x780 \n"
"    BNE     loc_F84317EC \n"
//"  MOV     R0, #0x200000 \n"
"    MOV     R0, #2097152 \n" // 10 mins
"    MOV     R6, #5 \n"
"    STR     R0, [R8, #0xC4] \n"

"loc_F84317E4:\n"
"    STR     R1, [R8, #0x58] \n"
"    B       loc_F84317F8 \n"

"loc_F84317EC:\n"
"    LDR     R1, =0x439 \n"
"    LDR     R0, =0xF842EBCC /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_F84317F8:\n"
"    LDR     R9, [R4, #8] \n"
"    CMP     R9, #0xB \n"
"    CMPNE   R9, #0xA \n"
"    CMPNE   R9, #9 \n"
"    BNE     loc_F843182C \n"
"    LDR     R0, [R8, #0xF0] \n"
"    CMP     R0, #0x500 \n"
"    BNE     loc_F843182C \n"
"    LDR     R0, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_006ACF94 \n"
"    B       loc_F843184C \n"

"loc_F843182C:\n"
"    LDR     R0, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_006ACF94 \n"
"    MOV     R1, #5 \n"
"    BL      sub_006ACF94 \n"
"    ADD     R0, R0, #1 \n"
"    ADD     R0, R0, R0, LSL#2 \n"

"loc_F843184C:\n"
"    CMP     R9, #0xB \n"
"    CMPNE   R9, #0xA \n"
"    CMPNE   R9, #9 \n"
"    STR     R0, [R8, #0x54] \n"
"    BNE     loc_F8431874 \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R1, R0 \n"
"    MOV     R1, R5 \n"
"    BL      sub_006ACF94 \n"
"    STR     R0, [R8, #0x58] \n"

"loc_F8431874:\n"
"    CMP     R9, #3 \n"
"    CMPNE   R9, #4 \n"
"    BNE     loc_F84318AC \n"
"    RSB     R0, R5, R5, LSL#4 \n"
"    STR     R10, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MOV     R0, R0, LSL#1 \n"
"    BL      sub_006ACF94 \n"
"    LDR     R1, [R8, #0x100] \n"
"    MOV     R10, R1 \n"
"    BL      sub_006ACF94 \n"
"    ADD     R0, R0, #1 \n"
"    MUL     R0, R10, R0 \n"
"    STR     R0, [R8, #0x54] \n"

"loc_F84318AC:\n"
"    ADD     R0, R5, R5, LSL#8 \n"
"    LDR     R1, [R8, #0x158] \n"
"    RSB     R0, R0, R0, LSL#3 \n"
"    BL      sub_006ACF94 \n"
"    STR     R0, [R8, #0x88] \n"
"    LDR     R0, [R4, #0xC] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    STR     R0, [SP] \n"
"    LDR     R5, [R7, #0xC] \n"
"    MOV     R0, R5, LSR#1 \n"
"    STR     R5, [R8, #0xAC] \n"
"    STR     R0, [R8, #0xB0] \n"
"    LDR     R0, [SP, #8] \n"
"    ADD     R0, R0, #3 \n"
"    BIC     R1, R0, #3 \n"
"    STR     R1, [R8, #0x114] \n"
"    LDR     R0, [R8, #0x54] \n"
"    MOV     R0, R0, LSL#2 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R8, #0x118] \n"
"    LDRH    R7, [R8, #4] \n"
"    LDR     R2, [SP, #0xC] \n"
"    LDR     R3, [SP, #8] \n"
"    CMP     R7, #0 \n"
"    ADD     R10, R3, R2 \n"
"    BEQ     sub_F8431B78 \n"
"    ADD     R9, R1, R0 \n"
"    STR     R9, [R8, #0x11C] \n"
"    LDR     R1, [R8, #0xFC] \n"
"    BL      sub_006ACF94 \n"
"    ADD     R0, R0, R9 \n"
"    ADD     R0, R0, #0x1F \n"
"    BIC     R0, R0, #0x1F \n"
"    STR     R0, [R8, #0x120] \n"
"    LDR     R1, [R8, #0xE8] \n"
"    CMP     R1, #0 \n"
"    BEQ     sub_F8431A0C \n"
"    LDR     R2, [R8, #0xC4] \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R8, #0x2C] \n"
"    ADD     R0, R0, #0x20 \n"
"    B       sub_F84319D4 \n"
);
}

/*************************************************************/
//** sub_F8235A30_my @ 0xF8235A30 - 0xF8235DFC, length=244
void __attribute__((naked,noinline)) sub_F8235A30_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x48 \n"
"    MOV     R8, #0 \n"
"    LDR     R5, =0x9C78 \n"
"    STR     R8, [SP, #0x38] \n"
"    STR     R8, [SP, #0x30] \n"
"    STR     R8, [R5, #0xC4] \n"
"    LDR     R1, [R5, #0x44] \n"
"    MOV     R4, R0 \n"
"    CMP     R1, #3 \n"
"    MOV     R6, R8 \n"
"    MOV     R7, #1 \n"
"    BNE     loc_F8235A88 \n"
"    LDR     R0, [R5, #0xE4] \n"
"    LDR     R1, [R5, #0xE8] \n"
"    CMP     R0, R1 \n"
"    BNE     loc_F8235BA8 \n"
"    MOV     R0, #4 \n"
"    STR     R0, [R5, #0x44] \n"
"    MVN     R0, #0 \n"
"    STR     R0, [R5, #0xE4] \n"
"    B       loc_F8235A90 \n"

"loc_F8235A88:\n"
"    CMP     R1, #4 \n"
"    BNE     loc_F8235BA8 \n"

"loc_F8235A90:\n"
"    LDRH    R0, [R5, #6] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_F8235AC8 \n"
"    LDR     R0, [R5, #0xC8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x86B \n"
"    LDREQ   R0, =0xF82342F0 /*'MovieRecorder.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R0, [R5, #0x6C] \n"
"    LDR     R1, [R5, #0xC8] \n"
"    BL      sub_006ACF94 \n"
"    CMP     R1, #0 \n"
"    MOVNE   R7, #0 \n"
"    BNE     loc_F8235AE4 \n"

"loc_F8235AC8:\n"
"    ADD     R3, SP, #0x30 \n"
"    ADD     R2, SP, #0x34 \n"
"    ADD     R1, SP, #0x38 \n"
"    ADD     R0, SP, #0x3C \n"
"    BL      sub_F8433294 \n"
"    MOVS    R8, R0 \n"
"    BNE     loc_F8235B00 \n"

"loc_F8235AE4:\n"
"    LDR     R0, [R5, #0x34] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_F8235BB0 \n"
"    LDR     R0, [R5, #0x6C] \n"
"    LDR     R1, [R5, #0x48] \n"
"    CMP     R0, R1 \n"
"    BCC     loc_F8235BB0 \n"

"loc_F8235B00:\n"
"    MOV     R0, R8 \n"
"    BL      sub_F8234EE0 \n"
"    BL      sub_F82369FC \n"
"    LDR     R2, [R5, #0x64] \n"
"    ADD     R3, SP, #0x40 \n"
"    MVN     R1, #1 \n"
"    MOV     R0, #0 \n"
"    ADD     R7, SP, #0x1C \n"
"    STMIA   R7, {R0-R3} \n"
"    LDR     R3, [R4, #0x1C] \n"
"    LDR     R1, [R5, #0x74] \n"
"    LDR     R2, [R5, #0x78] \n"
"    ADD     R0, SP, #0x44 \n"
"    ADD     R4, SP, #0xC \n"
"    STMIA   R4, {R0-R3} \n"
"    MOV     R3, #0 \n"
"    MOV     R1, #0x40 \n"
"    STMEA   SP, {R1,R3} \n"
"    MOV     R2, #0 \n"
"    STR     R3, [SP, #8] \n"
"    LDR     R3, =0x1417EC \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_F83DA288 \n"
"    LDR     R0, [R5, #0x1C] \n"
"    LDR     R1, [R5, #0x60] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BNE     loc_F8235B7C \n"

"loc_F8235B74:\n"
"    MOV     R1, #1 \n"
"    B       loc_F8235CD0 \n"

"loc_F8235B7C:\n"
"    LDR     R0, [SP, #0x40] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_F8235B90 \n"

"loc_F8235B88:\n"
"    MOV     R1, #1 \n"
"    B       loc_F8235CE8 \n"

"loc_F8235B90:\n"
"    MOV     R0, #1 \n"
"    BL      sub_F83DA334 \n"
"    BL      sub_F83DA3E0 \n"
"    MOV     R0, #5 \n"
"    STR     R6, [R5, #0x34]! \n"
"    STR     R0, [R5, #0x10] \n"

"loc_F8235BA8:\n"
"    ADD     SP, SP, #0x48 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_F8235BB0:\n"
"    CMP     R7, #1 \n"
"    BNE     loc_F8235D74 \n"
"    MOV     R0, #1 \n"
"    STR     R0, [R5, #0x38] \n"
"    LDR     R0, [R5, #0x6C] \n"
"    LDR     R8, [R4, #0xC] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R7, [SP, #0x38] \n"
"    LDRNE   R12, [SP, #0x3C] \n"
"    BNE     loc_F8235C68 \n"
"    LDR     R0, [R4, #0x20] \n"
"    LDR     R2, [R5, #0x64] \n"
"    ADD     R3, SP, #0x40 \n"
"    MVN     R1, #0 \n"
"    ADD     R7, SP, #0x1C \n"
"    STMIA   R7, {R0-R3} \n"
"    LDR     R3, [R4, #0x1C] \n"
"    LDR     R1, [R5, #0x74] \n"
"    LDR     R2, [R5, #0x78] \n"
"    ADD     R0, SP, #0x44 \n"
"    ADD     R7, SP, #0xC \n"
"    STMIA   R7, {R0-R3} \n"
"    LDR     R1, [SP, #0x34] \n"
"    LDR     R2, [SP, #0x38] \n"
"    LDR     R3, [SP, #0x30] \n"
"    STMFA   SP, {R1,R3} \n"
"    STR     R2, [SP] \n"
"    LDMIB   R4, {R0,R1} \n"
"    LDR     R3, [SP, #0x3C] \n"
"    MOV     R2, R8 \n"
"    BL      sub_F83DA288 \n"
"    LDR     R0, [R5, #0x1C] \n"
"    LDR     R1, [R5, #0x60] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BEQ     loc_F8235B74 \n"
"    LDR     R0, [SP, #0x40] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_F8235B88 \n"
"    MOV     R0, #1 \n"
"    BL      sub_F83DA334 \n"
"    LDR     R0, [SP, #0x44] \n"
"    LDR     R1, [SP, #0x3C] \n"
"    ADD     R12, R1, R0 \n"
"    LDR     R1, [SP, #0x38] \n"
"    SUB     R7, R1, R0 \n"

"loc_F8235C68:\n"
"    LDR     R0, [R4, #0x20] \n"
"    LDR     R1, [R5, #0x68] \n"
"    LDR     R2, [R5, #0x64] \n"
"    ADD     R3, SP, #0x40 \n"
"    ADD     LR, SP, #0x1C \n"
"    STMIA   LR, {R0-R3} \n"
"    LDR     R3, [R4, #0x1C] \n"
"    LDR     R1, [R5, #0x74] \n"
"    LDR     R2, [R5, #0x78] \n"
"    ADD     R0, SP, #0x44 \n"
"    ADD     LR, SP, #0xC \n"
"    STMIA   LR, {R0-R3} \n"
"    LDR     R2, [SP, #0x34] \n"
"    LDR     R3, [SP, #0x30] \n"
"    STMFA   SP, {R2,R3} \n"
"    STR     R7, [SP] \n"
"    LDMIB   R4, {R0,R1} \n"
"    MOV     R3, R12 \n"
"    MOV     R2, R8 \n"
"    BL      sub_F83DA288 \n"
"    LDR     R0, [R5, #0x1C] \n"
"    LDR     R1, [R5, #0x60] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BNE     loc_F8235CD8 \n"
"    MOV     R1, #0 \n"

"loc_F8235CD0:\n"
"    MOV     R0, #0x90000 \n"
"    B       loc_F8235CEC \n"

"loc_F8235CD8:\n"
"    LDR     R0, [SP, #0x40] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_F8235CF4 \n"
"    MOV     R1, #0 \n"

"loc_F8235CE8:\n"
"    MOV     R0, #0xA0000 \n"

"loc_F8235CEC:\n"
"    BL      sub_F82352D4 \n"
"    B       loc_F8235BA8 \n"

"loc_F8235CF4:\n"
"    MOV     R0, #0 \n"
"    BL      sub_F83DA334 \n"
"    LDR     R0, [SP, #0x3C] \n"
"    LDR     R1, [SP, #0x44] \n"
"    BL      sub_F843350C \n"
"    LDR     R0, [R5, #0x68] \n"
"    LDR     R3, =0x9CF0 \n"
"    ADD     R1, R0, #1 \n"
"    STR     R1, [R5, #0x68] \n"
"    LDR     R0, [SP, #0x44] \n"
"    SUB     R2, R3, #4 \n"
"    BL      sub_F842E278 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    LDR     R0, [R5, #0x64] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_F8235D80 \n"
"    ADD     R0, SP, #0x2C \n"
"    BL      sub_F81E5928 \n"
"    LDR     R1, =0x14175C \n"
"    LDR     R0, [R1, #4] \n"
"    LDR     R1, [R1] \n"
"    SUB     R2, R0, #0x400 \n"
"    SUBS    R2, R2, #0x38 \n"
"    ADDEQ   R0, R0, #8 \n"
"    MOV     R1, R1, LSR#4 \n"
"    MOV     R0, R0, LSR#4 \n"
"    MUL     R1, R0, R1 \n"
"    LDR     R0, [SP, #0x2C] \n"
"    BL      sub_006ACF94 \n"
"    LDR     R1, =0x14178C \n"
"    STR     R0, [SP, #0x2C] \n"
"    BL      sub_F842E5B4 \n"
"    B       loc_F8235D80 \n"

"loc_F8235D74:\n"
"    LDRH    R0, [R5, #6] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_F8235BA8 \n"

"loc_F8235D80:\n"
"    LDR     R0, [R5, #0x6C] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R5, #0x6C] \n"
"    LDRH    R1, [R5, #6] \n"
"    CMP     R1, #3 \n"
"    LDRNE   R1, [R5, #0x54] \n"
"    MULNE   R0, R1, R0 \n"
"    LDRNE   R1, [R5, #0x50] \n"
"    BNE     loc_F8235DC0 \n"
"    LDR     R1, [R5, #0x58] \n"
"    CMP     R1, #0x19 \n"
"    LDRNE   R1, =0x3E9 \n"
"    MOVEQ   R1, #0x3E8 \n"
"    MUL     R0, R1, R0 \n"
"    LDRNE   R1, =0x1770 \n"
"    LDREQ   R1, =0x1388 \n"

"loc_F8235DC0:\n"
"    BL      sub_006ACF94 \n"
"    MOV     R4, R0 \n"
"    BL      sub_F8433BC8 \n"
"    LDR     R0, [R5, #0x7C] \n"
"    CMP     R0, R4 \n"
"    BNE     loc_F8235DE4 \n"
"    LDR     R0, [R5, #0x3C] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_F8235DF8 \n"

"loc_F8235DE4:\n"
"    LDR     R1, [R5, #0xA8] \n"
"    MOV     R0, R4 \n"
"    BLX     R1 \n"
"    STR     R4, [R5, #0x7C] \n"
"    STR     R6, [R5, #0x3C] \n"

"loc_F8235DF8:\n"
"    STR     R6, [R5, #0x38] \n"
"    B       loc_F8235BA8 \n"
);
}
