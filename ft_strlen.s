section .text
	global _ft_strlen

_ft_strlen:
	xor rax, rax ; Reset compteur

while:
	mov dl, [rdi + rax] ; Caractere temporaire
	cmp dl, 0x0 ; Compare avec \0
	je end ; Si oui stop
	add rax, 1 ; Sinon incrémentation du compteur
	jmp while ; Retour en haut de la boucle

end:
	ret ; Retour de rax = compteur