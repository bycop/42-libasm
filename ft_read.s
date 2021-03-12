section	.text
	global _ft_read
	extern ___error ; Dependence fonction errno

_ft_read:
	mov rax, 0x02000003 ; = Appel systeme pour read
	syscall ; Appel systeme qui va remplir rax
	jc error ; Detecte une erreur
	ret ; Sinon return read avec rax

error:
	mov rdi, rax ; Variable temporaire
	call ___error ; Error qui va remplir rdi
	mov [rax], rdi ; On fais pointé rax sur errno
	mov rax, -1 ; Rax prends la valeur de retour -1
	ret ; Retour