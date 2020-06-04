global ft_strcmp

ft_strcmp:
	mov rcx, 0 ;count
	mov rax, 0 ;result
	mov rdx, 0

_while:
	mov al, byte [rdi + rcx]
	mov dl, byte [rsi + rcx]
	cmp dl, al ;and compare it with the second argument
	jnz _different
	cmp al, byte 0
	jz _end
	cmp dl, byte 0
	jz _end
	inc rcx
	jmp _while

_different:
	sub rax, rdx
	jmp _end
	
_end:
	ret
