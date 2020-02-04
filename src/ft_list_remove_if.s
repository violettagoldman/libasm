global _ft_list_remove_if ;void	ft_list_remove_if(t_list **head_list,
					;void *data_ref, int (*cmp)(), void (*free_fct)(void *))
extern _free

;r8 ->	*previous
;r9 ->	*current
;r10 -> *next
;r11 -> temp
;rdi ->	**head_list
;rsi -> data_ref
;rdx -> cmp
;rcx -> free_fct

_ft_list_remove_if:
	mov r8, 0 ; previous = 0
	mov r9, [rdi] ; current = *head_list
	jmp _while

_while: ; while (current)
	cmp r9, 0
	jz _end
	mov r11, qword [r9 + 8]
	mov r10, r11 ; next = current->next
	push rdi
	push rsi
	mov rax, rdx
	mov rdi, [r9]
	call rax
	cmp rax, 0
	jz _if_cmp
	pop rsi
	pop rdi
	mov r8, r9 ; previous = current
	mov r9, r10 ; current = next
	jmp _while

_if_cmp:
	mov rdi, [r9] ; current -> data
	mov rax, rcx ; free_fct
	call rax
	pop rsi
	pop rdi
	push rdi
	push rsi
	push rdx
	push rcx
	push rax
	push r8
	push r9
	push r10
	push r11
	mov rdi, r9
	call _free
	pop r11
	pop r10
	pop r9
	pop r8
	pop rax
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	cmp r8, 0 ; if (previous)
	jz _if_previous
	mov [r8 + 8], r10
	mov r9, r10 ; current = next
	jmp _while

_if_previous: ; else
	mov [rdi], r10 ; *head_list = next
	mov r9, r10 ; current = next
	jmp _while

_end:
	ret
