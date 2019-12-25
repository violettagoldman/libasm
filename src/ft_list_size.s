global _ft_list_size:

_ft_list_size:
	mov rcx, 0 ;count

_while:
	cmp rdi, 0
	jz _end ; if we reached NULL
	inc rcx
	mov rdi, [rdi + 8]
	jmp _while

_end:
	mov rax, rcx
	ret
