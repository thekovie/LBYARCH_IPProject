section .data

section .text 
bits 64
default rel

global saxpy_asm

saxpy_asm:
	PUSH RBP
	MOV RBP, RSP
	ADD RBP, 16
	; xmm0 a
	LEA R10, [RDX] ; x
	LEA R11, [R8] ; y
	LEA RAX, [R9] ; z
	MOV RDX, [RBP+32] ; size
	; loop until size is 0
LP: 
	MOVSS xmm1, [R10]
	MULSS xmm1, xmm0 ; a * x

	ADDSS xmm1, [R11] ; a*x + y
	MOVSS [RAX], xmm1 ; store to z

	DEC RDX
	CMP RDX, 0
	JE END
	ADD R10, 4
	ADD R11, 4
	ADD RAX, 4
	JMP LP


END:
	POP RBP
	ret