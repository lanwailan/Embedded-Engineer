a   EQU   12;  ���峣��a, ��ֵ12
b   EQU    3;
c   EQU    7;

		AREA SWIStack,DATA, READWRITE
temp    DCD  0x0
	
		AREA Test1,CODE,READONLY
		CODE32
		ENTRY
		
START	MOV   	r0,#a              ;��r0��Ϊa
		MOV   	r0,r0,lsl #8       ;r0 = r0<<8 �൱��a����2��8����
		MOV   	r1,#b              ;
		ADD   	r2,r0,r1,lsr #1    ;r2 = r0+r1>>1
		LDR   	r3 ,=temp          ;ȡ���ݻ�������ַ
		STR   	r2,[r3]            ;�����������뻺����
		
		MOV	  	r0 , #c             ;��r0��Ϊc
		AND   	r0 , r0, #0xFF   	   ; r0 = r0 & 0xFF
		MOV   	r1 ,  #b             ;��r1��Ϊb
		ADD   	r2 , r0, r1, lsr #1   ; r2 = r0 + r1>>1
		
		
		LDR	   	r0,[r3]				;�ӻ�������ȡ����һ�ε�������
		MOV		r1 ,#0x01			;r1 = 1
		ORR		r0,r0,r1			; r0=r0|r1
		MOV		r1,r2				; ���ڶ�������������r1
		ADD		r2,r0,r1,lsr #1		;r2=r0+r1>>1
		
		B		START
		
		END