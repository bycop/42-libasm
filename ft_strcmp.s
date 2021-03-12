section .text
	global _ft_strcmp

_ft_strcmp:
    xor rax, rax ; Reset rax a 0

while:
    movzx r8, BYTE [rdi + rax] ; Caractere r8 = str[i]
    movzx r9, BYTE [rsi + rax] ; Caractere r9 = str2[i]
    mov r10, r8 ; Création d'une save de r8
    or r8, r9 ; Ou logique entre r8 et r9
    jz equal ; Si les deux sont a \0 on stop
    sub r10, r9 ; On soustrait r9 a r10 (r8) pour comparer
    jg higher ; Si r10 > 0 
    jl lower ; Si r10 < 0
    add rax, 1 ; On incrémente le compteur
    jmp while ; Retour au debut de la boucle

equal:
	mov rax, 0 ; Retour valeur nulle si meme string
    ret ; Retour de rax

higher:
    mov rax, 1 ; Retour valeur positive si str1 > str2
    ret ; Retour de rax

lower:
    mov rax, -1 ; Retour valeur negative si str1 < str2
    ret ; Retour de rax