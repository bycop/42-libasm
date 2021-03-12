section	.text
	global _ft_strdup
	extern _ft_strcpy
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	call _ft_strlen ; On met rax a strlen
	add rax, 1 ; Ajout de 1 pour copier le \0
	push rdi ; Sauvegarde de rdi
	mov rdi, rax ; On met la valeur a malloc dans rdi
	call _malloc ; Call de malloc avec rdi en argument
	pop rdi ; on recupere rdi
	or rax, rax ; On regarde si la valeur de retour = 0
	jz return ; Si oui on return 0
	mov rsi, rdi ; Sinon on met la source dans rsi
	mov rdi, rax ; On fait pointer rdi sur le debut du malloc
	call _ft_strcpy ; On copie la chaine avec strcpy(Dest=rdi, source=rsi)
	ret ; On return rax = pointeur vers la chaine copiée

return:
	mov rax, 0 ; rax = 0
	ret ; Return rax = 0 pour malloc invalide