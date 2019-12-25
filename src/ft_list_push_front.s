extern _malloc
global _ft_list_push_front:

_ft_create_elem: ;void	ft_list_push_front(t_list **begin_list, void *data)
	push rdi ;store data in stack
	mov rdi, 16 ;16 bytes to malloc a structure
	call _malloc
	pop rdi ;get data from stack
	mov qword [rax], qword rdi ;initialize data in a node
	mov qword [rax + 8], qword 0 ;initialize new address to NULL
	ret ;return node

_ft_list_push_front:
	mov rcx, [rdi] ;
	push rdi ;store first arg
	mov rdi, rsi ;store second argument(data) to use i in a funciton
	call _ft_create_elem
	pop rdi ;get fist arg(list)
	cmp rbx, 0 ;check if list is empty
	jnz _not_empty ;if not emtpy then go to _not_empty
	mov [rdi], rax ;put the first node at the beginning of the list
	ret

_not_empty:
	mov rcx, [rdi] ;store the node
	mov qword [rax + 8], rcx ;connect with the next node
	mov [rdi], rax ;put the first node at the beginning of the list
	ret
