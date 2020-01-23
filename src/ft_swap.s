global _ft_swap:

_ft_swap:
	mov r9, qword [rdi]
	mov r10, qword [rsi]
	mov [rdi], r10
	mov [rsi], r9
	ret
