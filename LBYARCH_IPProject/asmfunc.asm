section .data
msg db "Hello World", 13, 10, 0

section .text 
bits 64
default rel

global asmhello
extern printf

asmhello:
	SUB RSP, 8*5
	LEA RCX, [msg]
	call printf
	add RSP, 8*5
	ret