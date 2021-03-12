section .text
	global _ft_strcpy

_ft_strcpy:
	xor rax, rax ; Reset de rax a 0

while:
	mov dl, [rsi + rax] ; Caractere temporaire = str[i]
	cmp dl, BYTE 0 ; Check si c'est pas un \0
	je end ; Si oui on stop
	mov [rdi + rax], dl ; Sinon on le copie dans la nouvelle chaine
	add rax, 1 ; On incremente le compteur
	jmp while ; On recommence la boucle

end:
	mov [rdi + rax], BYTE 0 ; On  met le \0 a la fin
	mov rax, rdi ; On met la nouvelle chaine dans rax
	ret ; On return rax