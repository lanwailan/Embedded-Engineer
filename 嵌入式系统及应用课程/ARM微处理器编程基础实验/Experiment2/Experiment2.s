
		AREA Test2,CODE,READONLY
		CODE32
		ENTRY

START
		B Reset_Handler
		
Undefined_Handler
		B Undefined_Handler
		
SWI_Handler
		B SWI_Handler
		
Prefetch_Handler
		B Prefetch_Handler
		
Abort_Handler
		B Abort_Handler
		
IRQ_Handler
		B IRQ_Handler
		
FIQ_Handler
		B FIQ_Handler
		
Reset_Handler
; go into system model

		MRS R0,CPSR				;copy CPSR to R0
		BIC R0,R0,#0x1F			;clear R0 last five bit
		ORR R0,R0,#0x1F			;set R0 last five bit to 1111
		MSR CPSR_c,R0			;load R0 to CPSR, switch to system model
		
		MOV R0,#1				;set value to R0-R14
		MOV R1,#2
		MOV R2,#3
		MOV R3,#4
		MOV R4,#5
		MOV R5,#6
		MOV R6,#7
		MOV R7,#8
		MOV R8,#9
		MOV R9,#10
		MOV R10,#11
		MOV R11,#12
		MOV R12,#13
		MOV R13,#14
		MOV R14,#15
		
; go into FIQ model

		MRS R0,CPSR
		BIC R0,R0,#0x1F
		ORR R0,R0,#0x11			;set last R0 five bit to 10001
		MSR CPSR_c,R0			;load R0 to CPSR,switch to Fiq
		
		MOV R8,#16
		MOV R9,#17
		MOV R10,#18
		MOV R11,#19
		MOV R12,#20
		MOV R13,#21
		MOV R14,#22

; go into IRQ model		
		MRS R0,CPSR
		BIC R0,R0,#0x1F
		ORR R0,R0,#0x12			;set R0 to 10011
		MSR CPSR_c,R0			;switch to IRQ
		
		MOV R13,#23
		MOV R14,#24
		
;go into SVCģʽ
		MRS R0,CPSR
		BIC R0,R0,#0x1F		
		ORR R0,R0,#0x13			;
		MSR CPSR_c,R0
		
		MOV R13,#25
		MOV R14,#26
		
;go into UNDEF
		MRS R0,CPSR
		BIC R0,R0,#0x1F
		ORR R0,R0,#0x1b
		MSR CPSR_c,R0
		
		MOV R13,#29
		MOV R14,#30
		
		B Reset_Handler
		
		END
		
		
		