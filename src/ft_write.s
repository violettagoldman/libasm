global ft_write
extern __errno_location

ft_write:
	mov rax, 1
	syscall
	cmp rax, 0
	jl _error
	mov r8, rax
	call __errno_location
	mov qword [rax], 0
	mov rax, r8
	ret

_error:
	mov r8, rax
	imul r8, -1
	call __errno_location
	mov [rax], r8
	mov rax, -1 
	ret

