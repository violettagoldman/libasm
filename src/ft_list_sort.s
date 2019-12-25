global _ft_list_sort: ;void	ft_list_sort(t_list **begin_list, int (*cmp)())
extern _ft_write
_swap:
	mov r9, qword [rdi] ;temp
	mov [rdi], rsi
	mov qword [rsi], r9

_ft_list_sort:
	cmp rdi, 0 ;check if NULL
	jz _end
	mov r13, rsi ;cmp function
	mov rcx, [rdi] ;current = *begin_list;
	cmp rcx, 0 ;if *begin_list == NULL
	jmp _end ;empty, doesn't need to be sorted
	cmp qword [rcx + 8], 0 ;if *(begin_list)->next == NULL
	jmp _end ;only one node, doesn't need to be sorted

_while_1:
	cmp rcx, 0 ;current != NULL
	jz _end
	mov rdx, qword [rcx + 8] ;next = current->next;
	call _while_2
	mov rcx, qword [rcx + 8] ;current = current->next
	jmp _while_1

_while_2:
	cmp rdx, 0 ;next != NULL
	jz _end
	mov rax, r13
	mov rdi, qword [rcx]
	mov rsi, qword [rdx]
	call rax
	cmp rax, byte 0
	jg _swap
	mov rdi, qword [rdi + 8] ;next = next->next;

_end:
	ret
