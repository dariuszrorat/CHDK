#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

static long *nrflag = (long*)(0x8868+0x00);  // Found @ ff9e4024 & ff9e406c
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

#define PAUSE_FOR_FILE_COUNTER 300           // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF870DB0

void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
      "STMFD   SP!, {R3-R9,LR} \n"
      "LDR     R4, =0x36D7C \n"
      "LDR     R7, =0x2B64 \n"
      "MOV     R6, #0 \n"
"loc_FF870DC0:\n"
      "LDR     R0, [R7, #4] \n"
      "MOV     R2, #0 \n"
      "MOV     R1, SP \n"
      "BL      sub_003F7218 \n"
      "TST     R0, #1 \n"
      "BEQ     loc_FF870DEC \n"
      "LDR     R1, =0x493 \n"
      "LDR     R0, =0xFF87091C \n" // "SsShootTask.c"
      "BL      _DebugAssert \n"
      "BL      _ExitTask \n"
      "LDMFD   SP!, {R3-R9,PC} \n"
"loc_FF870DEC:\n"
      "LDR     R0, [SP] \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x20 \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF871048 \n"
      "B       loc_FF870E80 \n"
      "B       loc_FF870E98 \n"
      "B       loc_FF870EFC \n"
      "B       loc_FF870F10 \n"
      "B       loc_FF870F08 \n"
      "B       loc_FF870F1C \n"
      "B       loc_FF870F24 \n"
      "B       loc_FF870F2C \n"
      "B       loc_FF870F48 \n"
      "B       loc_FF870F74 \n"
      "B       loc_FF870F54 \n"
      "B       loc_FF870F60 \n"
      "B       loc_FF870F68 \n"
      "B       loc_FF870F7C \n"
      "B       loc_FF870F84 \n"
      "B       loc_FF870F8C \n"
      "B       loc_FF870F94 \n"
      "B       loc_FF870F9C \n"
      "B       loc_FF870FA8 \n"
      "B       loc_FF870FB0 \n"
      "B       loc_FF870FB8 \n"
      "B       loc_FF870FC0 \n"
      "B       loc_FF870FC8 \n"
      "B       loc_FF870FD4 \n"
      "B       loc_FF870FDC \n"
      "B       loc_FF870FE4 \n"
      "B       loc_FF870FEC \n"
      "B       loc_FF870FF4 \n"
      "B       loc_FF871000 \n"
      "B       loc_FF871008 \n"
      "B       loc_FF871014 \n"
      "B       loc_FF871054 \n"
"loc_FF870E80:\n"
      "    BL      shooting_expo_iso_override \n" // added
      "BL      sub_FF8715C8 \n"
      "    BL      shooting_expo_param_override \n" // added
      "BL      sub_FF86EBBC \n"
//      "LDR     R0, [R4, #0x28] \n"
//     "CMP     R0, #0 \n"
//      "BLNE    sub_FF96473C \n" // above 3 lines removed - redundant with added lines below
      "    MOV     R0, #0 \n" // patch added
      "    STR     R0, [R4,#0x28] \n" //fixes overrides behavior at short shutter press
      "B       loc_FF871054 \n"
"loc_FF870E98:\n"
      "LDR     R5, [R0, #0x10] \n"
      "LDR     R0, [R4, #0x28] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF870ED4 \n"
      "BL      sub_FF87249C \n"
      "MOV     R1, R5 \n"
      "BL      sub_FF8724F4 \n"
      "LDR     R0, =0x10F \n"
      "MOV     R2, #4 \n"
      "ADD     R1, R5, #0x24 \n"
      "BL      _SetPropertyCase \n"
      "MOV     R2, #4 \n"
      "ADD     R1, R5, #0x28 \n"
      "MOV     R0, #0x2C \n"
      "BL      _SetPropertyCase \n"
"loc_FF870ED4:\n"
      "MOV     R0, R5 \n"
//      "BL      sub_FF9646A0 \n" //original
      "BL      sub_FF9646A0_my \n" //patch
      "BL      capt_seq_hook_raw_here \n" // patch
      "MOV     R8, R0 \n"
      "MOV     R2, R5 \n"
      "MOV     R1, #1 \n"
      "BL      sub_FF86F06C \n"
      "TST     R8, #1 \n"
      "MOVEQ   R0, R5 \n"
      "BLEQ    sub_FF96401C \n"
      "B       loc_FF871054 \n"
"loc_FF870EFC:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF871898 \n"
      "B       loc_FF871054 \n"
"loc_FF870F08:\n"
      "BL      sub_FF87121C \n"
      "B       loc_FF870F14 \n"
"loc_FF870F10:\n"
      "BL      sub_FF8715A8 \n"
"loc_FF870F14:\n"
      "STR     R6, [R4, #0x28] \n"
      "B       loc_FF871054 \n"
"loc_FF870F1C:\n"
      "BL      sub_FF8715B0 \n"
      "B       loc_FF871054 \n"
"loc_FF870F24:\n"
      "BL      sub_FF871780 \n"
      "B       loc_FF870F4C \n"
"loc_FF870F2C:\n"
      "LDR     R5, [R0, #0x10] \n"
      "MOV     R0, R5 \n"
      "BL      sub_FF9647D4 \n"
      "MOV     R2, R5 \n"
      "MOV     R1, #9 \n"
      "BL      sub_FF86F06C \n"
      "B       loc_FF871054 \n"
"loc_FF870F48:\n"
      "BL      sub_FF871800 \n"
"loc_FF870F4C:\n"
      "BL      sub_FF86EBBC \n"
      "B       loc_FF871054 \n"
"loc_FF870F54:\n"
      "LDR     R0, [R4, #0x58] \n"
      "BL      sub_FF871C88 \n"
      "B       loc_FF871054 \n"
"loc_FF870F60:\n"
      "BL      sub_FF872038 \n"
      "B       loc_FF871054 \n"
"loc_FF870F68:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF87209C \n"
      "B       loc_FF871054 \n"
"loc_FF870F74:\n"
      "BL      sub_FF8715A8 \n"
      "B       loc_FF871054 \n"
"loc_FF870F7C:\n"
      "BL      sub_FF9633C8 \n"
      "B       loc_FF871054 \n"
"loc_FF870F84:\n"
      "BL      sub_FF963628 \n"
      "B       loc_FF871054 \n"
"loc_FF870F8C:\n"
      "BL      sub_FF9636E0 \n"
      "B       loc_FF871054 \n"
"loc_FF870F94:\n"
      "BL      sub_FF9637B4 \n"
      "B       loc_FF871054 \n"
"loc_FF870F9C:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF963A14 \n"
      "B       loc_FF871054 \n"
"loc_FF870FA8:\n"
      "BL      sub_FF963B84 \n"
      "B       loc_FF871054 \n"
"loc_FF870FB0:\n"
      "BL      sub_FF963C18 \n"
      "B       loc_FF871054 \n"
"loc_FF870FB8:\n"
      "BL      sub_FF963CD4 \n"
      "B       loc_FF871054 \n"
"loc_FF870FC0:\n"
      "BL      sub_FF871A0C \n"
      "B       loc_FF871054 \n"
"loc_FF870FC8:\n"
      "BL      sub_FF871A90 \n"
      "BL      sub_FF832298 \n"
      "B       loc_FF871054 \n"
"loc_FF870FD4:\n"
      "BL      sub_FF963884 \n"
      "B       loc_FF871054 \n"
"loc_FF870FDC:\n"
      "BL      sub_FF9638C4 \n"
      "B       loc_FF871054 \n"
"loc_FF870FE4:\n"
      "BL      sub_FF873944 \n"
      "B       loc_FF871054 \n"
"loc_FF870FEC:\n"
      "BL      sub_FF8739B8 \n"
      "B       loc_FF871054 \n"
"loc_FF870FF4:\n"
      "LDR     R0, [R0, #0xC] \n"
      "BL      sub_FF963DFC \n"
      "B       loc_FF871054 \n"
"loc_FF871000:\n"
      "BL      sub_FF963E6C \n"
      "B       loc_FF871054 \n"
"loc_FF871008:\n"
      "BL      sub_FF873A20 \n"
      "BL      sub_FF8739D8 \n"
      "B       loc_FF871054 \n"
"loc_FF871014:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF964ED4 \n"
      "MOV     R0, #1 \n"
      "BL      sub_FF964FFC \n"
      "LDRH    R0, [R4, #0x9C] \n"
      "CMP     R0, #4 \n"
      "LDRNEH  R0, [R4] \n"
      "SUBNE   R1, R0, #0x8200 \n"
      "SUBNES  R1, R1, #0x2E \n"
      "BNE     loc_FF871054 \n"
      "BL      sub_FF8739B8 \n"
      "BL      sub_FF873E7C \n"
      "B       loc_FF871054 \n"
"loc_FF871048:\n"
      "LDR     R1, =0x5F4 \n"
      "LDR     R0, =0xFF87091C \n" // "SsShootTask.c"
      "BL      _DebugAssert \n"
"loc_FF871054:\n"
      "LDR     R0, [SP] \n"
      "LDR     R1, [R0, #4] \n"
      "LDR     R0, [R7] \n"
      "BL      sub_003FAC6C \n"
      "LDR     R5, [SP] \n"
      "LDR     R0, [R5, #8] \n"
      "CMP     R0, #0 \n"
      "LDREQ   R1, =0x117 \n"
      "LDREQ   R0, =0xFF87091C \n" // "SsShootTask.c"
      "BLEQ    _DebugAssert \n"
      "STR     R6, [R5, #8] \n"
      "B       loc_FF870DC0 \n"
	);
}


//**  sub_FF9646A0_my  @ 0xFF9646A0

void __attribute__((naked,noinline)) sub_FF9646A0_my() {
asm volatile (
      "STMFD   SP!, {R4-R6,LR} \n"
      "LDR     R5, =0x36D7C \n"
      "MOV     R6, R0 \n"
      "LDR     R0, [R5, #0x28] \n"
      "MOV     R4, #0 \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF9646D0 \n"
      "MOV     R0, #0xC \n"
      "BL      sub_FF87551C \n"
      "TST     R0, #1 \n"
      "MOVNE   R0, #1 \n"
      "LDMNEFD SP!, {R4-R6,PC} \n"
"loc_FF9646D0:\n"
      "BL      sub_FF8715B8 \n"
      "LDR     R0, [R5, #0x28] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF964720 \n"
      "MOV     R0, R6 \n"
      "BL      sub_FF963F5C \n"
      "TST     R0, #1 \n"
      "LDMNEFD SP!, {R4-R6,PC} \n"
      "MOV     R0, R6 \n"
      "BL      sub_FF9642F0 \n"
      "BL      sub_FF964CB4 \n"
//begin patch
      "BL      wait_until_remote_button_is_released\n"
      "BL      capt_seq_hook_set_nr\n"
//end patch
      "MOV     R0, #2 \n"
      "BL      sub_FF876C34 \n"
      "LDR     R0, [R5, #0x8C] \n"
      "TST     R0, #0x10 \n"
      "BNE     loc_FF964730 \n"
      "MOV     R0, R6 \n"
      "BL      sub_FFA7217C \n"  //original
//      "BL      sub_FFA7217C_my\n" //This function calls "SsStandardCaptureSeq.c"
      "MOV     R4, R0 \n"
      "B       loc_FF964734 \n"
"loc_FF964720:\n"
      "LDR     R0, =0x684C \n"
      "LDR     R0, [R0] \n"
      "CMP     R0, #0 \n"
      "BEQ     loc_FF964734 \n"
"loc_FF964730:\n"
      "MOV     R4, #0x1D \n"
"loc_FF964734:\n"
      "MOV     R0, R4 \n"
      "LDMFD   SP!, {R4-R6,PC} \n"
	);
}


//** sub_FFA7217C_my  @ 0xFFA7217C
/*
void __attribute__((naked,noinline)) sub_FFA7217C_my() {
asm volatile (
      "STMFD   SP!, {R3-R9,LR} \n"
      "MOV     R4, R0 \n"
      "LDR     R1, =0xB1EC \n"
      "MOV     R2, #4 \n"
      "MOV     R0, #0x130 \n"
      "BL      _GetPropertyCase \n"
      "TST     R0, #1 \n"
      "MOVNE   R1, #0x230 \n"
      "LDRNE   R0, =0xFFA723A8 \n"
      "BLNE    _DebugAssert \n"
      "LDR     R6, =0xB1E4 \n"
      "LDR     R0, [R6, #8] \n"
      "AND     R0, R0, #0xFF00 \n"
      "CMP     R0, #0x600 \n"
      "LDRNE   R0, =0xFF964034 \n"
      "LDREQ   R0, =0xFFA71EF4 \n"
      "MOVNE   R1, R4 \n"
      "MOVEQ   R1, #0 \n"
      "BL      sub_FF8A45A4 \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF963FEC \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF9643C0 \n"
      "MOV     R8, R0 \n"
      "LDR     R1, =0xB1E8 \n"
      "MOV     R2, #4 \n"
      "MOV     R0, #0x8A \n"
      "BL      _GetPropertyCase \n"
      "TST     R0, #1 \n"
      "LDRNE   R1, =0x23D \n"
      "LDRNE   R0, =0xFFA723A8 \n"
      "BLNE    _DebugAssert \n"
      "BL      sub_FF8736BC \n"
      "BL      sub_FF9645C8 \n"
      "CMP     R8, #0xA \n"
      "MOV     R7, #0 \n"
      "MOV     R5, #1 \n"
      "ADDCC   PC, PC, R8, LSL #2 \n"
      "B       loc_FFA722DC \n"
      "B       loc_FFA722DC \n"
      "B       loc_FFA72240 \n"
      "B       loc_FFA72250 \n"
      "B       loc_FFA7226C \n"
      "B       loc_FFA7227C \n"
      "B       loc_FFA722A8 \n"
      "B       loc_FFA722DC \n"
      "B       loc_FFA722DC \n"
      "B       loc_FFA722DC \n"
      "B       loc_FFA722C0 \n"
"loc_FFA72240:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF8A45C0 \n"
      "STRH    R7, [R4, #0x10] \n"
      "B       loc_FFA722D0 \n"
"loc_FFA72250:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF8A45C0 \n"
      "MOV     R0, R4 \n"
      "STRH    R5, [R4, #0x10] \n"
      "BL      sub_FFA72004 \n"
"loc_FFA72264:\n"
      "MOV     R5, R0 \n"
      "B       loc_FFA722EC \n"
"loc_FFA7226C:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF8A45C0 \n"
      "MOV     R0, #1 \n"
      "B       loc_FFA72288 \n"
"loc_FFA7227C:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF8A45C0 \n"
      "MOV     R0, #2 \n"
"loc_FFA72288:\n"
      "BL      sub_FF8A4724 \n"
      "MOV     R0, R4 \n"
      "STRH    R5, [R4, #0x10] \n"
      "BL      sub_FFA72004 \n"
      "MOV     R5, R0 \n"
      "MOV     R0, #0 \n"
      "BL      sub_FF8A4724 \n"
      "B       loc_FFA722EC \n"
"loc_FFA722A8:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF8A45C0 \n"
      "MOV     R0, R4 \n"
      "STRH    R7, [R4, #0x10] \n"
      "BL      sub_FFA720CC \n"
      "B       loc_FFA72264 \n"
"loc_FFA722C0:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF8A45C0 \n"
      "MOV     R0, #4 \n"
      "STRH    R0, [R4, #0x10] \n"
"loc_FFA722D0:\n"
      "MOV     R0, R4 \n"
      "BL      sub_FFA71F84 \n"
      "B       loc_FFA72264 \n"
"loc_FFA722DC:\n"
      "LDR     R1, =0x286 \n"
      "LDR     R0, =0xFFA723A8 \n" // "SsStandardCaptureSeq.c"
      "BL      _DebugAssert \n"
      "MOV     R5, #0x1D \n"
"loc_FFA722EC:\n"
      "BL      sub_FF964618 \n"
      "TST     R5, #1 \n"
      "MOVNE   R0, R5 \n"
      "BNE     loc_FFA72384 \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF9644EC \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF964488 \n"
      "LDR     R0, [R6] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FFA7232C \n"
      "LDRH    R0, [R4, #0x10] \n"
      "CMP     R0, #1 \n"
      "CMPNE   R0, #3 \n"
      "CMPNE   R0, #5 \n"
      "BEQ     loc_FFA72380 \n"
"loc_FFA7232C:\n"
      "BL      sub_FF9651BC \n"
      "LDR     R5, =0x2A3 \n"
      "LDR     R2, =0x3A98 \n"
      "LDR     R3, =0xFFA723A8 \n" // "SsStandardCaptureSeq.c"
      "MOV     R1, #0xC \n"
      "STR     R5, [SP] \n"
      "BL      sub_FF875784 \n"
      "CMP     R0, #0 \n"
      "MOVNE   R1, R5 \n"
      "LDRNE   R0, =0xFFA723A8 \n" // "SsStandardCaptureSeq.c"
      "BLNE    _DebugAssert \n"
      "LDR     R0, =0x36D7C \n"
      "LDR     R1, [R0, #0x8C] \n"
      "TST     R1, #2 \n"
      "BNE     loc_FFA72380 \n"
      "LDRH    R0, [R0, #0x9A] \n"
      "CMP     R0, #3 \n"
      "LDRNE   R0, [R4, #8] \n"
      "CMPNE   R0, #1 \n"
      "MOVLS   R0, R4 \n"
      "BLLS    sub_FF9640BC \n"
"loc_FFA72380:\n"
      "MOV     R0, #0 \n"
"loc_FFA72384:\n"
      "LDMFD   SP!, {R3-R9,PC} \n"
	);
}
*/


//** exp_drv_task  @ 0xFF8AFADC 

void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
      "STMFD   SP!, {R4-R9,LR} \n"
      "SUB     SP, SP, #0x2C \n"
      "LDR     R6, =0x3DDC \n"
      "LDR     R7, =0xBB8 \n"
      "LDR     R4, =0x53D2C \n"
      "MOV     R0, #0 \n"
      "ADD     R5, SP, #0x1C \n"
      "STR     R0, [SP, #0xC] \n"
"loc_FF8AFAFC:\n"
      "LDR     R0, [R6, #0x20] \n"
      "MOV     R2, #0 \n"
      "ADD     R1, SP, #0x28 \n"
      "BL      sub_003F7218 \n"
      "LDR     R0, [SP, #0xC] \n"
      "CMP     R0, #1 \n"
      "BNE     loc_FF8AFB48 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R0, [R0] \n"
      "CMP     R0, #0x14 \n"
      "CMPNE   R0, #0x15 \n"
      "CMPNE   R0, #0x16 \n"
      "CMPNE   R0, #0x17 \n"
      "BEQ     loc_FF8AFCA8 \n"
      "CMP     R0, #0x2A \n"
      "BEQ     loc_FF8AFC30 \n"
      "ADD     R1, SP, #0xC \n"
      "MOV     R0, #0 \n"
      "BL      sub_FF8AFA8C \n"
"loc_FF8AFB48:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x30 \n"
      "BNE     loc_FF8AFB74 \n"
      "BL      sub_FF8B0EBC \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #1 \n"
      "BL      sub_003FAC6C \n"
      "BL      _ExitTask \n"
      "ADD     SP, SP, #0x2C \n"
      "LDMFD   SP!, {R4-R9,PC} \n"
"loc_FF8AFB74:\n"
      "CMP     R1, #0x2F \n"
      "BNE     loc_FF8AFB90 \n"
      "LDR     R2, [R0, #0x8C]! \n"
      "LDR     R1, [R0, #4] \n"
      "MOV     R0, R1 \n"
      "BLX     R2 \n"
      "B       loc_FF8B0164 \n"
"loc_FF8AFB90:\n"
      "CMP     R1, #0x28 \n"
      "BNE     loc_FF8AFBE0 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #0x80 \n"
      "BL      sub_003FACA0 \n"
      "LDR     R0, =0xFF8AB3F0 \n"
      "MOV     R1, #0x80 \n"
      "BL      sub_FF955934 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R2, R7 \n"
      "MOV     R1, #0x80 \n"
      "BL      sub_003FABAC \n"
      "TST     R0, #1 \n"
      "LDRNE   R1, =0x157A \n"
      "BNE     loc_FF8AFC9C \n"
"loc_FF8AFBCC:\n"
      "LDR     R1, [SP, #0x28] \n"
      "LDR     R0, [R1, #0x90] \n"
      "LDR     R1, [R1, #0x8C] \n"
      "BLX     R1 \n"
      "B       loc_FF8B0164 \n"
"loc_FF8AFBE0:\n"
      "CMP     R1, #0x29 \n"
      "BNE     loc_FF8AFC28 \n"
      "ADD     R1, SP, #0xC \n"
      "BL      sub_FF8AFA8C \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #0x100 \n"
      "BL      sub_003FACA0 \n"
      "LDR     R0, =0xFF8AB400 \n"
      "MOV     R1, #0x100 \n"
      "BL      sub_FF955AD4 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R2, R7 \n"
      "MOV     R1, #0x100 \n"
      "BL      sub_003FABAC \n"
      "TST     R0, #1 \n"
      "BEQ     loc_FF8AFBCC \n"
      "LDR     R1, =0x1584 \n"
      "B       loc_FF8AFC9C \n"
"loc_FF8AFC28:\n"
      "CMP     R1, #0x2A \n"
      "BNE     loc_FF8AFC40 \n"
"loc_FF8AFC30:\n"
      "LDR     R0, [SP, #0x28] \n"
      "ADD     R1, SP, #0xC \n"
      "BL      sub_FF8AFA8C \n"
      "B       loc_FF8AFBCC \n"
"loc_FF8AFC40:\n"
      "CMP     R1, #0x2D \n"
      "BNE     loc_FF8AFC58 \n"
      "BL      sub_FF89C6CC \n"
      "BL      sub_FF89D3B4 \n"
      "BL      sub_FF89CF1C \n"
      "B       loc_FF8AFBCC \n"
"loc_FF8AFC58:\n"
      "CMP     R1, #0x2E \n"
      "BNE     loc_FF8AFCA8 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #4 \n"
      "BL      sub_003FACA0 \n"
      "LDR     R1, =0xFF8AB420 \n"
      "LDR     R0, =0xFFFFF400 \n"
      "MOV     R2, #4 \n"
      "BL      sub_FF89C11C \n"
      "BL      sub_FF89C3AC \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R2, R7 \n"
      "MOV     R1, #4 \n"
      "BL      sub_003FAAC8 \n"
      "TST     R0, #1 \n"
      "BEQ     loc_FF8AFBCC \n"
      "LDR     R1, =0x15AC \n"
"loc_FF8AFC9C:\n"
      "LDR     R0, =0xFF8ABB14 \n"
      "BL      _DebugAssert \n"
      "B       loc_FF8AFBCC \n"
"loc_FF8AFCA8:\n"
      "LDR     R0, [SP, #0x28] \n"
      "MOV     R8, #1 \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x12 \n"
      "CMPNE   R1, #0x13 \n"
      "BNE     loc_FF8AFD10 \n"
      "LDR     R1, [R0, #0x7C] \n"
      "ADD     R1, R1, R1, LSL #1 \n"
      "ADD     R1, R0, R1, LSL #2 \n"
      "SUB     R1, R1, #8 \n"
      "LDMIA   R1, {R2,R3,R9} \n"
      "STMIA   R5, {R2,R3,R9} \n"
      "BL      sub_FF8AE02C \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R3, [R0, #0x8C] \n"
      "LDR     R2, [R0, #0x90] \n"
      "ADD     R0, R0, #4 \n"
      "BLX     R3 \n"
      "LDR     R0, [SP, #0x28] \n"
      "BL      sub_FF8B12C0 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R2, [R0, #0x98] \n"
      "LDR     R3, [R0, #0x94] \n"
      "B       loc_FF8B0028 \n"
"loc_FF8AFD10:\n"
      "CMP     R1, #0x14 \n"
      "CMPNE   R1, #0x15 \n"
      "CMPNE   R1, #0x16 \n"
      "CMPNE   R1, #0x17 \n"
      "BNE     loc_FF8AFDC8 \n"
      "ADD     R3, SP, #0xC \n"
      "MOV     R2, SP \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_FF8AE28C \n"
      "CMP     R0, #1 \n"
      "MOV     R9, R0 \n"
      "CMPNE   R9, #5 \n"
      "BNE     loc_FF8AFD64 \n"
      "LDR     R0, [SP, #0x28] \n"
      "MOV     R2, R9 \n"
      "LDR     R1, [R0, #0x7C]! \n"
      "LDR     R12, [R0, #0x10]! \n"
      "LDR     R3, [R0, #4] \n"
      "MOV     R0, SP \n"
      "BLX     R12 \n"
      "B       loc_FF8AFD9C \n"
"loc_FF8AFD64:\n"
      "LDR     R0, [SP, #0x28] \n"
      "CMP     R9, #2 \n"
      "LDR     R3, [R0, #0x90] \n"
      "CMPNE   R9, #6 \n"
      "BNE     loc_FF8AFDB0 \n"
      "LDR     R12, [R0, #0x8C] \n"
      "MOV     R2, R9 \n"
      "MOV     R1, #1 \n"
      "MOV     R0, SP \n"
      "BLX     R12 \n"
      "LDR     R0, [SP, #0x28] \n"
      "MOV     R2, SP \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_FF8AF77C \n"
"loc_FF8AFD9C:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R2, [SP, #0xC] \n"
      "MOV     R1, R9 \n"
      "BL      sub_FF8AF9CC \n"
      "B       loc_FF8B0030 \n"
"loc_FF8AFDB0:\n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R12, [R0, #0x8C] \n"
      "MOV     R2, R9 \n"
      "ADD     R0, R0, #4 \n"
      "BLX     R12 \n"
      "B       loc_FF8B0030 \n"
"loc_FF8AFDC8:\n"
      "CMP     R1, #0x24 \n"
      "CMPNE   R1, #0x25 \n"
      "BNE     loc_FF8AFE14 \n"
      "LDR     R1, [R0, #0x7C] \n"
      "ADD     R1, R1, R1, LSL #1 \n"
      "ADD     R1, R0, R1, LSL #2 \n"
      "SUB     R1, R1, #8 \n"
      "LDMIA   R1, {R2,R3,R9} \n"
      "STMIA   R5, {R2,R3,R9} \n"
      "BL      sub_FF8AD018 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R3, [R0, #0x8C] \n"
      "LDR     R2, [R0, #0x90] \n"
      "ADD     R0, R0, #4 \n"
      "BLX     R3 \n"
      "LDR     R0, [SP, #0x28] \n"
      "BL      sub_FF8AD458 \n"
      "B       loc_FF8B0030 \n"
"loc_FF8AFE14:\n"
      "ADD     R1, R0, #4 \n"
      "LDMIA   R1, {R2,R3,R9} \n"
      "STMIA   R5, {R2,R3,R9} \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x28 \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF8B0018 \n"
      "B       loc_FF8AFED0 \n"
      "B       loc_FF8AFED0 \n"
      "B       loc_FF8AFED8 \n"
      "B       loc_FF8AFEE0 \n"
      "B       loc_FF8AFEE0 \n"
      "B       loc_FF8AFEE0 \n"
      "B       loc_FF8AFED0 \n"
      "B       loc_FF8AFED8 \n"
      "B       loc_FF8AFEE0 \n"
      "B       loc_FF8AFEE0 \n"
      "B       loc_FF8AFEF8 \n"
      "B       loc_FF8AFEF8 \n"
      "B       loc_FF8B0004 \n"
      "B       loc_FF8B000C \n"
      "B       loc_FF8B000C \n"
      "B       loc_FF8B000C \n"
      "B       loc_FF8B000C \n"
      "B       loc_FF8B0014 \n"
      "B       loc_FF8B0018 \n"
      "B       loc_FF8B0018 \n"
      "B       loc_FF8B0018 \n"
      "B       loc_FF8B0018 \n"
      "B       loc_FF8B0018 \n"
      "B       loc_FF8B0018 \n"
      "B       loc_FF8AFEE8 \n"
      "B       loc_FF8AFEF0 \n"
      "B       loc_FF8AFEF0 \n"
      "B       loc_FF8AFEF0 \n"
      "B       loc_FF8AFF04 \n"
      "B       loc_FF8AFF04 \n"
      "B       loc_FF8AFF0C \n"
      "B       loc_FF8AFF44 \n"
      "B       loc_FF8AFF7C \n"
      "B       loc_FF8AFFB4 \n"
      "B       loc_FF8AFFEC \n"
      "B       loc_FF8AFFEC \n"
      "B       loc_FF8B0018 \n"
      "B       loc_FF8B0018 \n"
      "B       loc_FF8AFFF4 \n"
      "B       loc_FF8AFFFC \n"
"loc_FF8AFED0:\n"
      "BL      sub_FF8AB998 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFED8:\n"
      "BL      sub_FF8ABC3C \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFEE0:\n"
      "BL      sub_FF8ABE64 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFEE8:\n"
      "BL      sub_FF8AC188 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFEF0:\n"
      "BL      sub_FF8AC3A0 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFEF8:\n"
//      "BL      sub_FF8AC74C \n"  //original
      "BL      sub_FF8AC74C_my \n" //patched
      "MOV     R8, #0 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFF04:\n"
      "BL      sub_FF8AC88C \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFF0C:\n"
      "LDRH    R1, [R0, #4] \n"
      "STRH    R1, [SP, #0x1C] \n"
      "LDRH    R1, [R4, #2] \n"
      "STRH    R1, [SP, #0x1E] \n"
      "LDRH    R1, [R4, #4] \n"
      "STRH    R1, [SP, #0x20] \n"
      "LDRH    R1, [R4, #6] \n"
      "STRH    R1, [SP, #0x22] \n"
      "LDRH    R1, [R0, #0xC] \n"
      "STRH    R1, [SP, #0x24] \n"
      "LDRH    R1, [R4, #0xA] \n"
      "STRH    R1, [SP, #0x26] \n"
      "BL      sub_FF8B0F50 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFF44:\n"
      "LDRH    R1, [R0, #4] \n"
      "STRH    R1, [SP, #0x1C] \n"
      "LDRH    R1, [R4, #2] \n"
      "STRH    R1, [SP, #0x1E] \n"
      "LDRH    R1, [R4, #4] \n"
      "STRH    R1, [SP, #0x20] \n"
      "LDRH    R1, [R4, #6] \n"
      "STRH    R1, [SP, #0x22] \n"
      "LDRH    R1, [R4, #8] \n"
      "STRH    R1, [SP, #0x24] \n"
      "LDRH    R1, [R4, #0xA] \n"
      "STRH    R1, [SP, #0x26] \n"
      "BL      sub_FF8B10C0 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFF7C:\n"
      "LDRH    R1, [R4] \n"
      "STRH    R1, [SP, #0x1C] \n"
      "LDRH    R1, [R0, #6] \n"
      "STRH    R1, [SP, #0x1E] \n"
      "LDRH    R1, [R4, #4] \n"
      "STRH    R1, [SP, #0x20] \n"
      "LDRH    R1, [R4, #6] \n"
      "STRH    R1, [SP, #0x22] \n"
      "LDRH    R1, [R4, #8] \n"
      "STRH    R1, [SP, #0x24] \n"
      "LDRH    R1, [R4, #0xA] \n"
      "STRH    R1, [SP, #0x26] \n"
      "BL      sub_FF8B1174 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFFB4:\n"
      "LDRH    R1, [R4] \n"
      "STRH    R1, [SP, #0x1C] \n"
      "LDRH    R1, [R4, #2] \n"
      "STRH    R1, [SP, #0x1E] \n"
      "LDRH    R1, [R4, #4] \n"
      "STRH    R1, [SP, #0x20] \n"
      "LDRH    R1, [R4, #6] \n"
      "STRH    R1, [SP, #0x22] \n"
      "LDRH    R1, [R0, #0xC] \n"
      "STRH    R1, [SP, #0x24] \n"
      "LDRH    R1, [R4, #0xA] \n"
      "STRH    R1, [SP, #0x26] \n"
      "BL      sub_FF8B121C \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFFEC:\n"
      "BL      sub_FF8ACDCC \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFFF4:\n"
      "BL      sub_FF8AD55C \n"
      "B       loc_FF8B0018 \n"
"loc_FF8AFFFC:\n"
      "BL      sub_FF8AD840 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8B0004:\n"
      "BL      sub_FF8ADB00 \n"
      "B       loc_FF8B0018 \n"
"loc_FF8B000C:\n"
      "BL      sub_FF8ADCBC \n"
      "B       loc_FF8B0018 \n"
"loc_FF8B0014:\n"
      "BL      sub_FF8ADE24 \n"
"loc_FF8B0018:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R2, [R0, #0x90] \n"
      "LDR     R3, [R0, #0x8C] \n"
"loc_FF8B0028:\n"
      "ADD     R0, R0, #4 \n"
      "BLX     R3 \n"
"loc_FF8B0030:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R0, [R0] \n"
      "CMP     R0, #0x10 \n"
      "BEQ     loc_FF8B0068 \n"
      "BGT     loc_FF8B0058 \n"
      "CMP     R0, #1 \n"
      "CMPNE   R0, #4 \n"
      "CMPNE   R0, #0xE \n"
      "BNE     loc_FF8B009C \n"
      "B       loc_FF8B0068 \n"
"loc_FF8B0058:\n"
      "CMP     R0, #0x13 \n"
      "CMPNE   R0, #0x17 \n"
      "CMPNE   R0, #0x1A \n"
      "BNE     loc_FF8B009C \n"
"loc_FF8B0068:\n"
      "LDRSH   R0, [R4] \n"
      "CMN     R0, #0xC00 \n"
      "LDRNESH R1, [R4, #8] \n"
      "CMNNE   R1, #0xC00 \n"
      "STRNEH  R0, [SP, #0x1C] \n"
      "STRNEH  R1, [SP, #0x24] \n"
      "BNE     loc_FF8B009C \n"
      "ADD     R0, SP, #0x10 \n"
      "BL      sub_FF8B14CC \n"
      "LDRH    R0, [SP, #0x10] \n"
      "STRH    R0, [SP, #0x1C] \n"
      "LDRH    R0, [SP, #0x18] \n"
      "STRH    R0, [SP, #0x24] \n"
"loc_FF8B009C:\n"
      "LDR     R0, [SP, #0x28] \n"
      "CMP     R8, #1 \n"
      "BNE     loc_FF8B00EC \n"
      "LDR     R1, [R0, #0x7C] \n"
      "MOV     R2, #0xC \n"
      "ADD     R1, R1, R1, LSL #1 \n"
      "ADD     R0, R0, R1, LSL #2 \n"
      "SUB     R8, R0, #8 \n"
      "LDR     R0, =0x53D2C \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_003FC17C \n"
      "LDR     R0, =0x53D38 \n"
      "MOV     R2, #0xC \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_003FC17C \n"
      "LDR     R0, =0x53D44 \n"
      "MOV     R2, #0xC \n"
      "MOV     R1, R8 \n"
      "BL      sub_003FC17C \n"
      "B       loc_FF8B0164 \n"
"loc_FF8B00EC:\n"
      "LDR     R0, [R0] \n"
      "MOV     R3, #1 \n"
      "CMP     R0, #0xB \n"
      "BNE     loc_FF8B0130 \n"
      "MOV     R2, #0 \n"
      "STRD    R2, [SP] \n"
      "MOV     R2, R3 \n"
      "MOV     R1, R3 \n"
      "MOV     R0, #0 \n"
      "BL      sub_FF8AB778 \n"
      "MOV     R3, #1 \n"
      "MOV     R2, #0 \n"
      "STRD    R2, [SP] \n"
      "MOV     R2, R3 \n"
      "MOV     R1, R3 \n"
      "MOV     R0, #0 \n"
      "B       loc_FF8B0160 \n"
"loc_FF8B0130:\n"
      "MOV     R2, #1 \n"
      "STRD    R2, [SP] \n"
      "MOV     R3, R2 \n"
      "MOV     R1, R2 \n"
      "MOV     R0, R2 \n"
      "BL      sub_FF8AB778 \n"
      "MOV     R3, #1 \n"
      "MOV     R2, R3 \n"
      "MOV     R1, R3 \n"
      "MOV     R0, R3 \n"
      "STR     R3, [SP] \n"
      "STR     R3, [SP, #4] \n"
"loc_FF8B0160:\n"
      "BL      sub_FF8AB8E4 \n"
"loc_FF8B0164:\n"
      "LDR     R0, [SP, #0x28] \n"
      "BL      sub_FF8B0EBC \n"
      "B       loc_FF8AFAFC \n"
	);
}


//** sub_FF8AC74C_my  @ 0xFF8AC74C 

void __attribute__((naked,noinline)) sub_FF8AC74C_my() {
asm volatile (
      "STMFD   SP!, {R4-R8,LR} \n"
      "LDR     R7, =0x3DDC \n"
      "MOV     R4, R0 \n"
      "LDR     R0, [R7, #0x1C] \n"
      "MOV     R1, #0x3E \n"
      "BL      sub_003FACA0 \n"
      "MOV     R2, #0 \n"
      "LDRSH   R0, [R4, #4] \n"
      "MOV     R1, R2 \n"
      "BL      sub_FF8AB480 \n"
      "MOV     R6, R0 \n"
      "LDRSH   R0, [R4, #6] \n"
      "BL      sub_FF8AB5D0 \n"
      "LDRSH   R0, [R4, #8] \n"
      "BL      sub_FF8AB628 \n"
      "LDRSH   R0, [R4, #0xA] \n"
      "BL      sub_FF8AB680 \n"
      "LDRSH   R0, [R4, #0xC] \n"
      "MOV     R1, #0 \n"
      "BL      sub_FF8AB6D8 \n"
      "MOV     R5, R0 \n"
      "LDR     R0, [R4] \n"
      "LDR     R8, =0x53D44 \n"
      "CMP     R0, #0xB \n"
      "MOVEQ   R6, #0 \n"
      "MOVEQ   R5, R6 \n"
      "BEQ     loc_FF8AC7E0 \n"
      "CMP     R6, #1 \n"
      "BNE     loc_FF8AC7E0 \n"
      "LDRSH   R0, [R4, #4] \n"
      "LDR     R1, =0xFF8AB3E0 \n"
      "MOV     R2, #2 \n"
      "BL      sub_FF9559B8 \n"
      "STRH    R0, [R4, #4] \n"
      "MOV     R0, #0 \n"
      "STR     R0, [R7, #0x28] \n"
      "B       loc_FF8AC7E8 \n"
"loc_FF8AC7E0:\n"
      "LDRH    R0, [R8] \n"
      "STRH    R0, [R4, #4] \n"
"loc_FF8AC7E8:\n"
      "CMP     R5, #1 \n"
      "LDRNEH  R0, [R8, #8] \n"
      "BNE     loc_FF8AC804 \n"
      "LDRSH   R0, [R4, #0xC] \n"
      "LDR     R1, =0xFF8AB464 \n"
      "MOV     R2, #0x20 \n"
      "BL      sub_FF8B0F0C \n"
"loc_FF8AC804:\n"
      "STRH    R0, [R4, #0xC] \n"
      "LDRSH   R0, [R4, #6] \n"
//      "BL      sub_FF89C418 \n" //original
      "BL      sub_FF89C418_my \n" //patched
      "B       sub_FF8AC810 \n" // continue in firmware
	);
}


//** sub_FF89C418_my  @ 0xFF89C418

void __attribute__((naked,noinline)) sub_FF89C418_my() {
asm volatile (
      "STMFD   SP!, {R4-R6,LR} \n"
      "LDR     R5, =0x3A68 \n"
      "MOV     R4, R0 \n"
      "LDR     R0, [R5, #4] \n"
      "CMP     R0, #1 \n"
      "LDRNE   R1, =0x14D \n"
      "LDRNE   R0, =0xFF89C250 \n"
      "BLNE    _DebugAssert \n"
      "CMN     R4, #0xC00 \n"
      "LDREQSH R4, [R5, #2] \n"
      "CMN     R4, #0xC00 \n"
      "LDREQ   R1, =0x153 \n"
      "LDREQ   R0, =0xFF89C250 \n"
      "STRH    R4, [R5, #2] \n"
      "BLEQ    _DebugAssert \n"
      "MOV     R0, R4 \n"
//      "BL      _apex2us \n" //original apex2us function
      "BL      apex2us \n"    //patch
      "MOV     R4, R0 \n"
      "BL      sub_FF8EA590 \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF8F2D98 \n"
      "TST     R0, #1 \n"
      "LDMEQFD SP!, {R4-R6,PC} \n"
      "LDMFD   SP!, {R4-R6,LR} \n"
      "MOV     R1, #0x158 \n"
      "LDR     R0, =0xFF89C250 \n"
      "B       _DebugAssert \n"
	);
}
