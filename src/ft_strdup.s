global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	push rdi ;store argument
	call ft_strlen
	mov rdi, rax ;store len
	inc rdi ;avec '\0'
	call malloc
	mov rdi, rax
	pop rsi ;get stored argument
	call ft_strcpy
	ret
