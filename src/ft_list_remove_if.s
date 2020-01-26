global _ft_list_remove_if ;void	ft_list_remove_if(t_list **head_list,
					;void *data_ref, int (*cmp)(), void (*free_fct)(void *))
extern _free

; r8 -> *head_list
; r9 -> temp

; Arguments:
; rdi -> **head_list
; rsi -> data_ref
; rdx -> cmp
; rcx -> free_fct

_ft_list_remove_if:
	mov r8, [rdi]
	jmp _rec

_rec:
	cmp qword r8, qword 0 ; if (*head_list)
	jz _end
	mov rax, rdx ; cmp function
	push rdi
	mov rdi, qword [r8] ; (*head_list)->data
	call rax ; if (cmp((*head_list)->data, data_ref) == 0)
	cmp rax, 0
	jz _else
	pop rdi
	mov r9, qword [r8 + 8] ; temp = *head_list->next
	mov [rdi], r9
	push rdi
	mov rdi, qword [r8] ; temp->data
	mov rax, rcx ; free_fct
	call rax ; free_fct(temp->data);
	pop rdi
	push rdi
	mov rdi, r9 ; temp
	call _free ; free(temp)
	pop rdi
	mov rdi, r8
	jmp _rec

_else:
	mov r8, qword [r8 + 8] ; *begin_list = (*begin_list)->next
	mov rdi, r8
	jmp _rec

_end:
	ret
