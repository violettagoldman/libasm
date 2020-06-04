global ft_strcpy

ft_strcpy:
	mov rcx, 0 ;count

_while:
	mov al, [rsi + rcx] ;we take one byte
	mov byte [rdi + rcx], al ;we put this byte in the destination
	cmp al, byte 0 ;if '\0'
	jz _end
	inc rcx ;increment counter
	jmp _while ;iterate

_end:
	mov rax, rdi ;return the destionation, first argument
	ret
