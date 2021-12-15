/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
//** boot @ 0xFF00000C - 0xFF000170, length=90
void __attribute__((naked,noinline)) boot() {
asm volatile (
"    LDR     R1, =0xC0410000 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R1] \n"
"    MOV     R1, #0x78 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    MOV     R1, #0 \n"
"    MCR     p15, 0, R1, c7, c10, 4 \n"
"    MCR     p15, 0, R1, c7, c5 \n"
"    MCR     p15, 0, R1, c7, c6 \n"
"    MOV     R0, #0x3D \n"
"    MCR     p15, 0, R0, c6, c0 \n"
"    MOV     R0, #0xC000002F \n"
"    MCR     p15, 0, R0, c6, c1 \n"
"    MOV     R0, #0x33 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000033 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF00002F \n"
"    MCR     p15, 0, R0, c6, c5 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0, 1 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c3, c0 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 2 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 3 \n"
"    MRC     p15, 0, R0, c1, c0 \n"
"    ORR     R0, R0, #0x1000 \n"
"    ORR     R0, R0, #4 \n"
"    ORR     R0, R0, #1 \n"
"    MCR     p15, 0, R0, c1, c0 \n"
"    MOV     R1, #0x80000006 \n"
"    MCR     p15, 0, R1, c9, c1 \n"
"    MOV     R1, #6 \n"
"    MCR     p15, 0, R1, c9, c1, 1 \n"
"    MRC     p15, 0, R1, c1, c0 \n"
"    ORR     R1, R1, #0x50000 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    LDR     R2, =0xC0200000 \n"
"    MOV     R1, #1 \n"
"    STR     R1, [R2, #0x10C] \n"
"    MOV     R1, #0xFF \n"
"    STR     R1, [R2, #0xC] \n"
"    STR     R1, [R2, #0x1C] \n"
"    STR     R1, [R2, #0x2C] \n"
"    STR     R1, [R2, #0x3C] \n"
"    STR     R1, [R2, #0x4C] \n"
"    STR     R1, [R2, #0x5C] \n"
"    STR     R1, [R2, #0x6C] \n"
"    STR     R1, [R2, #0x7C] \n"
"    STR     R1, [R2, #0x8C] \n"
"    STR     R1, [R2, #0x9C] \n"
"    STR     R1, [R2, #0xAC] \n"
"    STR     R1, [R2, #0xBC] \n"
"    STR     R1, [R2, #0xCC] \n"
"    STR     R1, [R2, #0xDC] \n"
"    STR     R1, [R2, #0xEC] \n"
"    STR     R1, [R2, #0xFC] \n"
"    LDR     R1, =0xC0400008 \n"
"    LDR     R2, =0x430005 \n"
"    STR     R2, [R1] \n"
"    LDR     R2, =0xC0242010 \n"
"    LDR     R1, [R2] \n"
"    ORR     R1, R1, #1 \n"
"    STR     R1, [R2] \n"
"    LDR     R0, =0xFF6934FC \n"
"    LDR     R1, =0x671000 \n"
"    LDR     R3, =0x69BADC \n"

"loc_FF000130:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000130 \n"
"    LDR     R0, =0xFF67F878 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x15584 \n"

"loc_FF00014C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF00014C \n"
"    LDR     R1, =0x242F28 \n"
"    MOV     R2, #0 \n"

"loc_FF000164:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF000164 \n"
/* Install task hooks via 0x193x is not possible with this new dryos version
   So the below code patches the CreateTask function in RAM to install our
   hook -- ERR99
*/
// Install CreateTask patch
"    LDR     R0, =patch_CreateTask\n"   // Patch data
"    LDM     R0, {R1,R2}\n"             // Get two patch instructions
"    LDR     R0, =hook_CreateTask\n"    // Address to patch
"    STM     R0, {R1,R2}\n"             // Store patch instructions

"    B       sub_FF000380_my \n"  // --> Patched. Old value = 0xFF000380.

"patch_CreateTask:\n"
"    LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask_my
"    .long   CreateTask_my\n"
);
}

/*************************************************************/
//** CreateTask_my @ 0x006768B0 - 0x006768B4, length=2
void __attribute__((naked,noinline)) CreateTask_my() {
asm volatile (
"    STMFD   SP!, {R0}\n"
//R3 = Pointer to task function to create

/*** INSTALL capt_seq_task() hook ***/
"    LDR     R0, =task_CaptSeq\n"       // DryOS original code function ptr.
"    CMP     R0, R3\n"                  // is the given taskptr equal to our searched function?
"    LDREQ   R3, =capt_seq_task\n"      // if so replace with our task function base ptr.
"    BEQ     exitHook\n"                // below compares not necessary if this check has found something.

/*** INSTALL exp_drv_task() hook ***/
"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =exp_drv_task\n"
"    BEQ     exitHook\n"

/*** INSTALL filewrite() hook ***/
"    LDR     R0, =task_FileWrite\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =filewritetask\n"
"    BEQ     exitHook\n"

/*** INSTALL movie_record_task() hook ***/
/*
"    LDR     R0, =task_MovieRecord\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =movie_record_task\n"
"    BEQ     exitHook\n"
*/

/*** INSTALL init_file_modules_task() hook ***/
"    LDR     R0, =task_InitFileModules\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =init_file_modules_task\n"

"exitHook:\n" 
// restore overwritten registers
"    LDMFD   SP!, {R0}\n"
// Execute overwritten instructions from original code, then jump to firmware
"    STMFD   SP!, {R1-R9,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     PC, =0x006768B8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF000380_my @ 0xFF000380 - 0xFF0003E8, length=27
void __attribute__((naked,noinline)) sub_FF000380_my() {

    //Replacement of sub_ for correct power-on.
    //(short press = playback mode, long press = record mode)

    // look at power-on switch sub_FF031094
    // value and pointer from sub_FF090160
    if ((*(int*) 0xC0220100) & 1)
        *(int*)(0x2F30) = 0x200000; // Playmode
    else
        *(int*)(0x2F30) = 0x100000; // Shootingmode

asm volatile (
"    LDR     R0, =0xFF0003F8 \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF000430 \n"

"loc_FF00038C:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF00038C \n"
"    LDR     R0, =0xFF000430 \n"
"    MOV     R1, #0x1B0 \n"
"    LDR     R3, =0xFF000618 \n"

"loc_FF0003A8:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF0003A8 \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x398 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF0003DC:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF0003DC \n"
"    BL      sub_FF001100_my \n"  // --> Patched. Old value = 0xFF001100.
);
}

/*************************************************************/
//** sub_FF001100_my @ 0xFF001100 - 0xFF0011B4, length=46
void __attribute__((naked,noinline)) sub_FF001100_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_006953A4 \n"
"    MOV     R0, #0x73000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x242F28 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x54F15C \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x98 \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R0, =0x1E2 \n"
"    LDR     R1, =0x559C00 \n"
"    STR     R2, [SP, #0x10] \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0xF6 \n"
"    STR     R1, [SP] \n"
"    STR     R1, [SP, #0x14] \n"
"    STR     R0, [SP, #0x24] \n"
"    MOV     R0, #0xB6 \n"
"    STR     R0, [SP, #0x28] \n"
"    MOV     R0, #0x85 \n"
"    STR     R0, [SP, #0x2C] \n"
"    MOV     R0, #0x40 \n"
"    STR     R0, [SP, #0x30] \n"
"    MOV     R0, #4 \n"
"    STR     R0, [SP, #0x34] \n"
"    MOV     R0, #0x10 \n"
"    STR     R0, [SP, #0x5C] \n"
"    MOV     R0, #0x800 \n"
"    STR     R0, [SP, #0x60] \n"
"    MOV     R0, #0xA0 \n"
"    STR     R0, [SP, #0x64] \n"
"    MOV     R0, #0x280 \n"
"    STR     R0, [SP, #0x68] \n"
"    LDR     R1, =sub_FF004200_my \n"  // --> Patched. Old value = 0xFF004200.
"    MOV     R2, #0 \n"
"    MOV     R0, SP \n"
"    BL      sub_006727E8 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF004200_my @ 0xFF004200 - 0xFF004274, length=30
void __attribute__((naked,noinline)) sub_FF004200_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF000ADC \n"
"    BL      sub_FF005144 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004340 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF003E38 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004348 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF004358 /*'/_term'*/ \n"
"    BL      sub_FF003F20 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004360 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF004358 /*'/_term'*/ \n"
"    BL      sub_FF002940 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004374 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF004AE0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004380 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF0015F8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF00438C /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF00A610_my \n"  // --> Patched. Old value = 0xFF00A610.
);
}

/*************************************************************/
//** sub_FF00A610_my @ 0xFF00A610 - 0xFF00A680, length=29
void __attribute__((naked,noinline)) sub_FF00A610_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_FF036EE4 \n"
"    BL      sub_FF0382CC \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF00A634 \n"
"    BL      sub_FF033228 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF00A638 \n"

"loc_FF00A634:\n"
"    MOV     R0, #0 \n"

"loc_FF00A638:\n"
"    BL      sub_FF031094_my \n"  // --> Patched. Old value = 0xFF031094.
"    CMP     R0, #0 \n"
"    BNE     loc_FF00A64C \n"
"    BL      sub_FF03097C \n"

"loc_FF00A648:\n"
"    B       loc_FF00A648 \n"

"loc_FF00A64C:\n"
"    BL      sub_006779E0 \n"
"    LDR     R1, =0x5CE000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF03881C \n"
"    BL      sub_00677BF8 /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF00A5A8.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF00A68C /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF031094_my @ 0xFF031094 - 0xFF0310F8, length=26
void __attribute__((naked,noinline)) sub_FF031094_my() {
asm volatile (
"    STMFD   SP!, {R2-R8,LR} \n"
"    MOV     R6, #0 \n"
"    MOV     R8, R0 \n"
"    MOV     R7, R6 \n"
//"  BL      _sub_FF090058 \n"  // --> Nullsub call removed.
"    LDR     R0, =0xC0220100 \n"
"    BL      sub_FF08E458 \n"
"    MOV     R4, #1 \n"
"    BIC     R5, R4, R0 \n"
"    LDR     R0, =0xC0220104 \n"
"    BL      sub_FF08E458 \n"
"    CMP     R8, #0 \n"
"    BIC     R4, R4, R0 \n"
"    BEQ     loc_FF0310D4 \n"
"    ORRS    R0, R5, R4 \n"
"    BEQ     loc_FF0310F8 \n"

"loc_FF0310D4:\n"
"    BL      sub_FF0382CC \n"
"    MOV     R2, R0 \n"
"    MOV     R3, #0 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    STRD    R6, [SP] \n"
//"  BL      _sub_FF090060 \n"  // Disable StartUpChecks
//"  BL      _sub_FF09005C \n"  // --> Nullsub call removed.
"    MOV     R0, #1 \n"

"loc_FF0310F8:\n"
"    LDMFD   SP!, {R2-R8,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF00A5A8 - 0xFF00A60C, length=26
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF004898 \n"
"    BL      sub_FF0322B8 \n"
"    BL      sub_FF030928 \n"
//"  BL      _sub_FF0906F0 \n"  // --> Nullsub call removed.
"    BL      sub_FF03853C \n"
//"  BL      _sub_FF0383C4 \n"  // load DISKBOOT.BIN
"    BL      sub_FF0386B8 \n"
"    BL      sub_FF038E90 \n"
"    BL      sub_FF03867C \n"
"    BL      sub_FF038574 \n"
"    BL      sub_FF036E1C \n"
"    BL      sub_FF038E98 \n"
"    BL      CreateTask_spytask\n" // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF030F38.
"    BL      sub_FF035068 \n"
"    BL      sub_FF0D5AE8 \n"
"    BL      sub_FF02E738 \n"
"    BL      sub_FF0302A0 \n"
"    BL      sub_FF0380FC \n"
"    BL      sub_FF0308DC \n"
"    BL      sub_FF03023C \n"
"    BL      sub_FF07D3D4 \n"
"    BL      sub_FF02F390 \n"
"    BL      sub_FF030200 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF0049B8 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF030F38 - 0xFF030F88, length=21
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1DEC \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF030F6C \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF030F04.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF0311F0 /*'PhySw'*/ \n"
"    BL      sub_00677C50 /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #4] \n"

"loc_FF030F6C:\n"
"    BL      sub_FF0C089C \n"
"    BL      sub_FF033178 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF030F88 \n"
"    LDR     R1, =0x3A95C \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0C0808 /*_OpLog.Start_FW*/ \n"

"loc_FF030F88:\n"
"    LDMFD   SP!, {R3-R5,PC} \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF08208C - 0xFF0820C0, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF0C319C \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF0C31D0 \n"
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0 \n"
"    B       _PostLogicalEventToUI \n"
);
}
