// IXUS120-SD940 fw 1.01A

#include "conf.h"

/*----------------------------------------------------------------------
	change_video_tables()
-----------------------------------------------------------------------*/
void change_video_tables(__attribute__ ((unused))int a, __attribute__ ((unused))int b) {}

/*----------------------------------------------------------------------
	set_quality()
-----------------------------------------------------------------------*/
// from sx10, not sure if the values are right, seems to work
void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) 
	*x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

/*----------------------------------------------------------------------
	movie_record_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"	STMFD	SP!, {R2-R8,LR} \n"                
"	LDR	R7, =0x2710 \n"                  
"	LDR	R4, =0x6228 \n"                  
"	MOV	R6, #0 \n"                           
"	MOV	R5, #1 \n"                           
"loc_FF93D65C:\n"
"	LDR	R0, [R4, #0x18] \n"                  
"	MOV	R2, #0 \n"                           
"	ADD	R1, SP, #0x04 \n"                       
"	BL	sub_FF837DC8 \n"                      
"	LDR	R0, [R4, #0x20] \n"                  
"	CMP	R0, #0 \n"                           
"	BNE	loc_FF93D72C \n"                     
"	LDR	R0, [SP, #0x04] \n"                     
"	LDR	R1, [R0] \n"                     
"	SUB	R1, R1, #2 \n"                       
"	CMP	R1, #9 \n"                           
"	ADDLS	PC, PC, R1, LSL #2 \n"             
"	B	loc_FF93D72C \n"  
                     
"	B	loc_FF93D6E0 \n"  
                     
"	B	loc_FF93D700 \n"  
                     
"	B	loc_FF93D710 \n"   
                    
"	B	loc_FF93D718 \n"   
                    
"	B	loc_FF93D6E8 \n"   
                    
"	B	loc_FF93D720 \n"   
                    
"	B	loc_FF93D6F0 \n"    
                   
"	B	loc_FF93D72C \n"    
                   
"	B	loc_FF93D728 \n"   
                   
"	B	loc_FF93D6B8 \n"      
                 
"loc_FF93D6B8:\n"
"	LDR	R0, =0xFF93D35C \n"                  
"	STR	R6, [R4, #0x34] \n"                  
"	STR	R0, [R4, #0x9C] \n"                  
"	LDR	R2, =0xFF93C890 \n"                  
"	LDR	R1, =0x67F58 \n"                  
"	LDR	R0, =0xFF93C974 \n"                  
"	STR	R6, [R4, #0x24] \n"                  
"	BL	sub_FF8D9F28 \n"                      
"	STR	R5, [R4, #0x38] \n"                  
"	B	loc_FF93D72C \n"
                       
"loc_FF93D6E0:\n"
"	BL     unlock_optical_zoom \n"		// patched
"	BL	sub_FF93D464 \n"                      
"	B	loc_FF93D72C \n" 
                      
"loc_FF93D6E8:\n"
//"	BL	sub_FF93CFDC \n"   
"	BL	sub_FF93CFDC_my \n"     		// patched                
"	B	loc_FF93D72C \n" 
                      
"loc_FF93D6F0:\n"
"	LDR	R1, [R0, #0x18] \n"                  
"	LDR	R0, [R0, #4] \n"                     
"	BL	sub_FFA63B20 \n"                      
"	B	loc_FF93D72C \n"   
                  
"loc_FF93D700:\n"
"	LDR	R0, [R4, #0x38] \n"                  
"	CMP	R0, #5 \n"                           
"	STRNE	R5, [R4, #0x28] \n"                
"	B	loc_FF93D72C \n"
                       
"loc_FF93D710:\n"
"	BL	sub_FF93CCDC \n"                      
"	B	loc_FF93D72C \n" 
                      
"loc_FF93D718:\n"
"	BL	sub_FF93C9C0 \n"                      
"	B	loc_FF93D72C \n"
                       
"loc_FF93D720:\n"
"	BL	sub_FF93C81C \n"                      
"	B	loc_FF93D72C \n"    
                   
"loc_FF93D728:\n"
"	BL	sub_FF93D898 \n"
                      
"loc_FF93D72C:\n"
"	LDR	R1, [SP, #0x04] \n"                     
"	MOV	R3, #0x460 \n"                       
"	STR	R6, [R1] \n"                     
"	STR	R3, [SP] \n"                     
"	LDR	R0, [R4, #0x1C] \n"                  
"	LDR	R3, =0xFF93C67C \n"                  
"	MOV	R2, R7 \n"                           
"	BL	sub_FF83871C \n"                      
"	B	loc_FF93D65C \n"
  	);
}


/*----------------------------------------------------------------------
	sub_FF93CFDC_my()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) sub_FF93CFDC_my() {
asm volatile (
"	STMFD	SP!, {R4-R8,LR} \n"                
"	SUB	SP, SP, #0x40 \n"                    
"	MOV	R7, #0 \n"                           
"	LDR	R6, =0x6228 \n"                  
"	MOV	R4, R0 \n"                           
"	STR	R7, [SP, #0x30] \n"                  
"	STR	R7, [SP, #0x28] \n"                  
"	LDR	R0, [R6, #0x38] \n"                  
"	MOV	R8, #4 \n"                           
"	CMP	R0, #3 \n"                           
"	STREQ	R8, [R6, #0x38] \n"                
"	LDR	R0, [R6, #0x9C] \n"                  
"	BLX	R0 \n"                               
"	LDR	R0, [R6, #0x38] \n"                  
"	CMP	R0, #4 \n"                           
"	BNE	loc_FF93D14C \n"                     
"	ADD	R3, SP, #0x28 \n"                    
"	ADD	R2, SP, #0x2C \n"                    
"	ADD	R1, SP, #0x30 \n"                    
"	ADD	R0, SP, #0x34 \n"                    
"	BL	sub_FFA63BBC \n"                      
"	CMP	R0, #0 \n"                           
"	MOV	R5, #1 \n"                           
"	BNE	loc_FF93D058 \n"                     
"	LDR	R1, [R6, #0x28] \n"                  
"	CMP	R1, #1 \n"                           
"	BNE	loc_FF93D154 \n"                     
"	LDR	R1, [R6, #0x4C] \n"                  
"	LDR	R2, [R6, #0x3C] \n"                  
"	CMP	R1, R2 \n"                           
"	BCC	loc_FF93D154 \n"                     
"loc_FF93D058:\n"
"	CMP	R0, #0x80000001 \n"                  
"	STREQ	R8, [R6, #0x50] \n"                
"	BEQ	loc_FF93D090 \n"                     
"	CMP	R0, #0x80000003 \n"                  
"	STREQ	R5, [R6, #0x50] \n"                
"	BEQ	loc_FF93D090 \n"                     
"	CMP	R0, #0x80000005 \n"                  
"	MOVEQ	R0, #2 \n"                         
"	BEQ	loc_FF93D08C \n"                     
"	CMP	R0, #0x80000007 \n"                  
"	STRNE	R7, [R6, #0x50] \n"                
"	BNE	loc_FF93D090 \n"                     
"	MOV	R0, #3 \n"                           
"loc_FF93D08C:\n"
"	STR	R0, [R6, #0x50] \n"                  
"loc_FF93D090:\n"
"	LDR	R0, =0x67F8C \n"                  
"	LDR	R0, [R0, #8] \n"                     
"	CMP	R0, #0 \n"                           
"	BEQ	loc_FF93D0A8 \n"                     
"	BL	sub_FF85A840 \n"                      
"	B	loc_FF93D0AC \n"                       
"loc_FF93D0A8:\n"
"	BL	sub_FF93C81C \n"                      
"loc_FF93D0AC:\n"
"	LDR	R0, [R4, #0x1C] \n"                  
"	ADD	R4, SP, #0x18 \n"                    
"	ADD	R3, SP, #0x38 \n"                    
"	MVN	R2, #1 \n"                           
"	MOV	R1, #0 \n"                           
"	STMIA	R4, {R0-R3} \n"                    
"	LDR	R2, [R6, #0x64] \n"                  
"	LDR	R3, [R6, #0x68] \n"                  
"	ADD	R1, SP, #0x3c \n"                    
"	ADD	R4, SP, #0x08 \n"                       
"	MOV	R0, #0 \n"                           
"	STMIA	R4, {R0-R3} \n"                    
"	MOV	R3, #0 \n"                           
"	MOV	R2, #0x40 \n"                        
"	STRD	R2, [SP] \n"               
"	LDR	R3, =0x67FA4 \n"                  
"	MOV	R2, #0 \n"                           
"	MOV	R1, #0 \n"                           
"	BL	sub_FFA28044 \n"                      
"	LDR	R0, [R6, #0x10] \n"                  
"	MOV	R1, #0x3E8 \n"                       
"	BL	sub_FF8381E4 \n"                      
"	CMP	R0, #9 \n"                           
"	BNE	loc_FF93D11C \n"                     
"loc_FF93D10C:\n"
"	BL	sub_FFA64090 \n"                      
"	MOV	R0, #1 \n"                           
"	STR	R5, [R6, #0x38] \n"                  
"	B	loc_FF93D27C \n"                       
"loc_FF93D11C:\n"
"	LDR	R0, [SP, #0x38] \n"                  
"	CMP	R0, #0 \n"                           
"	BEQ	loc_FF93D138 \n"                     
"loc_FF93D128:\n"
"	BL	sub_FFA64090 \n"                      
"	MOV	R0, #1 \n"                           
"	STR	R5, [R6, #0x38] \n"                  
"	B	loc_FF93D2A8 \n"                       
"loc_FF93D138:\n"
"	MOV	R0, #1 \n"                           
"	BL	sub_FFA280EC \n"                      
"	BL	sub_FFA28128 \n"                      
"	MOV	R0, #5 \n"                           
"	STR	R0, [R6, #0x38] \n"                  
"loc_FF93D14C:\n"
"	ADD	SP, SP, #0x40 \n"                    
"	LDMFD	SP!, {R4-R8,PC} \n"                
"loc_FF93D154:\n"
"	LDR	R12, [SP, #0x30] \n"                 
"	CMP	R12, #0 \n"                          
"	BEQ	loc_FF93D304 \n"                     
"	STR	R5, [R6, #0x2C] \n"                  
"	LDR	R0, [R6, #0x4C] \n"                  
"	LDR	R8, [R4, #0xC] \n"                  
"	CMP	R0, #0 \n"                           
"	LDRNE	LR, [SP, #0x34] \n"                
"	BNE	loc_FF93D200 \n"                     
"	LDR	R0, [R4, #0x1C] \n"                  
"	LDR	R1, [R4, #0x20] \n"                  
"	ADD	R3, SP, #0x38 \n"                    
"	MVN	R2, #0 \n"                           
"	ADD	LR, SP, #0x18 \n"                    
"	STMIA	LR, {R0-R3} \n"                    
"	LDR	R0, [SP, #0x28] \n"                  
"	LDR	R2, [R6, #0x64] \n"                  
"	LDR	R3, [R6, #0x68] \n"                  
"	ADD	R1, SP, #0x3C \n"                    
"	ADD	LR, SP, #0x08 \n"                       
"	STMIA	LR, {R0-R3} \n"                    
"	LDR	R3, [SP, #0x2C] \n"                  
"	STR	R12, [SP] \n"                    
"	STR	R3, [SP, #0x04] \n"                     
"	LDMIB	R4, {R0,R1} \n"                    
"	LDR	R3, [SP, #0x34] \n"                  
"	MOV	R2, R8 \n"                           
"	BL	sub_FFA28044 \n"                      
"	LDR	R0, [R6, #0x10] \n"                  
"	MOV	R1, #0x3E8 \n"                       
"	BL	sub_FF8381E4 \n"                      
"	CMP	R0, #9 \n"                           
"	BEQ	loc_FF93D10C \n"                     
"	LDR	R0, [SP, #0x38] \n"                  
"	CMP	R0, #0 \n"                           
"	BNE	loc_FF93D128 \n"                     
"	MOV	R0, #1 \n"                           
"	BL	sub_FFA280EC \n"                      
"	LDR	R0, [SP, #0x3C] \n"                  
"	LDR	R1, [SP, #0x34] \n"                  
"	ADD	LR, R1, R0 \n"                       
"	LDR	R1, [SP, #0x30] \n"                  
"	SUB	R12, R1, R0 \n"                      
"loc_FF93D200:\n"
"	LDR	R2, [R6, #0x48] \n"                  
"	LDR	R0, [R4, #0x1C] \n"                  
"	LDR	R1, [R4, #0x20] \n"                  
"	ADD	R3, SP, #0x38 \n"                    
"	STR	R0, [SP, #0x18] \n"                  
"	STR	R1, [SP, #0x1C] \n"                  
"	STR	R3, [SP, #0x24] \n"                  
"	STR	R2, [SP, #0x20] \n"                  
"	LDR	R2, [R6, #0x64] \n"                  
"	LDR	R3, [R6, #0x68] \n"                  
"	LDR	R0, [SP, #0x28] \n"                  
"	STR	R3, [SP, #0x14] \n"                  
"	LDR	R3, [SP, #0x2C] \n"                  
"	ADD	R1, SP, #0x3C \n"                    
"	STR	R2, [SP, #0x10] \n"                  
"	STR	R3, [SP, #0x04] \n"                     
"	STR	R1, [SP, #0x0C] \n"                  
"	STR	R12, [SP] \n"                    
"	STR	R0, [SP, #0x08] \n"                     
"	LDMIB	R4, {R0,R1} \n"                    
"	MOV	R3, LR \n"                           
"	MOV	R2, R8 \n"                           
"	BL	sub_FFA28044 \n"                      
"	LDR	R0, [R6, #0x10] \n"                  
"	MOV	R1, #0x3E8 \n"                       
"	BL	sub_FF8381E4 \n"                      
"	CMP	R0, #9 \n"                           
"	BNE	loc_FF93D290 \n"                     
"	BL	sub_FFA64090 \n"                      
"	MOV	R0, #0 \n"                           
"	STR	R5, [R6, #0x38] \n"                  
"loc_FF93D27C:\n"
"	BL	sub_FFA280EC \n"                      
"	MOV	R0, #0xC \n"                        
"	BL	sub_FF87F3CC \n"                      
"	MOV	R0, #0x90000 \n"                     
"	B	loc_FF93D2B8 \n"                       
"loc_FF93D290:\n"
"	LDR	R0, [SP, #0x38] \n"                  
"	CMP	R0, #0 \n"                           
"	BEQ	loc_FF93D2CC \n"                     
"	BL	sub_FFA64090 \n"                      
"	MOV	R0, #0 \n"                           
"	STR	R5, [R6, #0x38] \n"  
                
"loc_FF93D2A8:\n"
"	BL	sub_FFA280EC \n"                      
"	MOV	R0, #0xC \n"                        
"	BL	sub_FF87F3CC \n"                      
"	MOV	R0, #0xA0000 \n"
                   
"loc_FF93D2B8:\n"
"	BL	sub_FF88ACFC \n"                      
"	LDR	R1, [R6, #0x8C]! \n"                 
"	LDR	R0, [R6, #0xC] \n"                  
"	BLX	R1 \n"                               
"	B	loc_FF93D14C \n"                       
"loc_FF93D2CC:\n"
"	MOV	R0, #0 \n"                           
"	BL	sub_FFA280EC \n"                      
"	LDR	R0, [SP, #0x34] \n"                  
"	LDR	R1, [SP, #0x3C] \n"                  
"	BL	sub_FFA63DE8 \n"                      
"	LDR	R0, [R6, #0x48] \n"                  
"	LDR	R3, =0x6290 \n"                  
"	ADD	R1, R0, #1 \n"                       
"	STR	R1, [R6, #0x48] \n"                  
"	STR	R3, [SP] \n"                     
"	LDR	R0, [SP, #0x3C] \n"                  
"	SUB	R3, R3, #4 \n"                       
"	MOV	R2, #0x0F \n"                        
"	BL	sub_FFA61F6C \n" 

"		LDR	R0, =0x6290-4 \n"    // patched
"		BL	set_quality \n"	
  
"loc_FF93D304:\n"
"	LDR	R0, [R6, #0x4C] \n"                  
"	ADD	R0, R0, #1 \n"                       
"	STR	R0, [R6, #0x4C] \n"                  
"	LDR	R1, [R6, #0x74] \n"                  
"	MUL	R0, R1, R0 \n"                       
"	LDR	R1, [R6, #0x70] \n"                  
"	BL	sub_FFB092C4 \n"                      
"	MOV	R4, R0 \n"                           
"	BL	sub_FFA640C8 \n"                      
"	LDR	R1, [R6, #0x6C] \n"                  
"	CMP	R1, R4 \n"                           
"	BNE	loc_FF93D340 \n"                     
"	LDR	R0, [R6, #0x30] \n"                  
"	CMP	R0, #1 \n"                           
"	BNE	loc_FF93D354 \n"                     
"loc_FF93D340:\n"
"	LDR	R1, [R6, #0x80] \n"                  
"	MOV	R0, R4 \n"                           
"	BLX	R1 \n"                               
"	STR	R4, [R6, #0x6C] \n"                  
"	STR	R7, [R6, #0x30] \n"                  
"loc_FF93D354:\n"
"	STR	R7, [R6, #0x2C] \n"                  
"	B	loc_FF93D14C \n"                       
	);
}
