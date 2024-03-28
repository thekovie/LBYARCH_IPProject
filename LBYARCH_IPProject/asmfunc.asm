section .data

section .text 
bits 64
default rel

global saxpy_asm

saxpy_asm:
	PUSH RSI
	PUSH RBP
	XOR RAX, RAX
	; xmm0 a
	LEA R10, [RDX] ; x
	LEA R11, [R8] ; y
	LEA R12, [R9] ; z
	MOV R13, [RBP+32] ; size
	; loop until size is 0
LP: 
	MOVSS xmm1, [R10]
	MULSS xmm1, xmm0 ; a * x

	ADDSS xmm1, [R11] ; a*x + y
	MOVSS [R12], xmm1 ; store to z

	CMP R13, 0
	JE END
	DEC R13
	INC R10
	INC R11
	INC R12
	MOV RCX, R13


END:
	POP RBP
	POP RSI
	ret