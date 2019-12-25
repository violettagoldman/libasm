global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
	push rdi ;store argument
	call _ft_strlen
	mov rdi, rax ;store len
	inc rdi ;avec '\0'
	call _malloc
	mov rdi, rax
	pop rsi ;get stored argument
	call _ft_strcpy
	ret
