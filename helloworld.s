global _hello

section	.text

_hello:
	mov rax, 0x02000004
	mov rdi, 1
	mov rsi, message
	mov rdx, 14
	syscall
	ret

section	.data
	message: db "Hello World !", 0xA`