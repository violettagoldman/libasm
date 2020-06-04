global ft_write
extern __errno_location

ft_write:
	mov rax, 1
	syscall
	jc _error
	ret

_error:
	mov r8, rax
	call __errno_location
	mov [rax], r8
	mov rax, -1 
	ret

