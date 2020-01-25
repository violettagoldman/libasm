global _ft_list_sort: ;void	ft_list_sort(t_list **begin_list, int (*cmp)())
; r8 -> current
; r9 -> next
; r12 -> *a !preserved
; r13 -> *b !preserved

_ft_swap: ; void	swap(void **a, void **b)
	push r12
	push r13
	mov r12, qword [rdi] ; temp1 = *a
	mov r13, qword [rsi] ; temp2 = *b
	mov [rdi], qword r13 ; *a = temp1
	mov [rsi], qword r12 ; *b = temp2
	mov rax, 0
	pop r13
	pop r12
	ret

_ft_list_sort: ; void	ft_list_sort(t_list **begin_list, int (*cmp)())
	mov r8, [rdi] ; current = *begin_list;
	jmp _while_1

_while_1:
	cmp r8, 0 ; while (current)
	jz _end
	mov r9, qword [r8 + 8] ; next = current->next;
	cmp r9, 0
	call _while_2
	mov r8, qword [r8 + 8] ; current = current->next;
	jmp _while_1

_while_2: ; while (next)
	cmp r9, 0
	jz _end
	mov rax, rsi
	push rdi
	push rsi
	mov rdi, qword [r8] ; current -> data
	mov rsi, qword [r9] ; next -> data
	call rax
	pop rsi
	pop rdi
	cmp rax, 0 ; if (cmp(current->data, next->data) > 0)
	jg _cmp_gz
	mov r9, qword [r9 + 8] ; next = next->next;
	jmp _while_2

_cmp_gz:
	push rdi
	push rsi
	mov rdi, r8
	mov rsi, r9
	call _ft_swap
	pop rsi
	pop rdi
	mov r9, qword [r9 + 8] ; next = next->next
	jmp _while_2

_end:
	ret
