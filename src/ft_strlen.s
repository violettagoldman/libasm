global _ft_strlen

_ft_strlen:
	mov rcx, 0 ;use rcx for count

_while:
	cmp byte [rdi + rcx], byte 0 ;use rdi for the first argument
	jz _end ;return rax if we reached '\0'
	inc rcx ;increment count
	jmp _while ;iterate

_end:
	mov rax, rcx ;return rax
 	ret
