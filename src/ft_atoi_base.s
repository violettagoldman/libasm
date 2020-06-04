global ft_atoi_base ;int	ft_atoi_base(char *str, char *base)
extern ft_strlen

; rcx -> count
; r8 -> int i
; r9 -> base (iterate heler)
; r10 -> str (iterate helper)
; r11 -> int base_len
; r12 -> int nb
; r13 -> sign
; rdi -> char *str
; rsi -> char *base
; r14 -> flag
; r15 -> iterator

ft_atoi_base:
	cmp rdi, 0
	jz _end
	cmp rsi, 0
	jz _end
	mov r12, 0 ; nb = 0
	mov r8, 0 ; i = 0
	mov rcx, 0 ; count = 0
	mov r13, 1 ; sign = 1
	push rdi
	mov rdi, rsi
	call ft_strlen
	mov r11, rax ; base_len = ft_strlen(base)
	pop rdi
	cmp r11, 1
	jz _end
	mov r9b, byte [rsi]
	call _base_check ; int		base_check(char *base)
	mov r10b, byte [rdi]
	cmp rax, 0
	jz _end
	mov rax, 0
	mov r8, 0
	mov rcx, 0
	call _while_sp
	call _while_sign
	jmp _while_str

_ret_neg:
	mov rax, 0
	ret

_base_check:
	cmp r9b, 0 ; if (!base[i])
	jz _base_check_end_false ; return (0)
	call _while_base_check ; while (base[i])
	ret

_while_base_check:
	cmp r9b, 0 ; base[i]
	jz _base_check_end_true
	cmp r9b, 9
	jz _base_check_end_false
	cmp r9b, 10
	jz _base_check_end_false
	cmp r9b, 11
	jz _base_check_end_false
	cmp r9b, 12
	jz _base_check_end_false
	cmp r9b, 13
	jz _base_check_end_false
	cmp r9b, 32
	jz _base_check_end_false
	cmp r9b, 43
	jz _base_check_end_false
	cmp r9b, 45
	jz _base_check_end_false
	mov rcx, r8 ; j = i
	inc rcx
	mov r10b, byte [rsi + rcx]  ; base[j]
	mov r14, 0
	call _while_base_check_2
	cmp r14, 1
	jz _end_while
	inc r8
	mov r9b, byte [rsi + r8]
	jmp _while_base_check

_while_base_check_2:
	cmp r10b, 0 ; while base[j]
	jz _end_while
	cmp r10b, r9b ; base[j] == base[i]
	jz _base_check_end_false
	inc rcx ; j++
	mov r10b, [rsi + rcx]
	jmp _while_base_check_2

_end_while:
	ret

_base_check_end_true:
	mov rax, 1
	ret

_base_check_end_false:
	mov rax, 0
	mov r14, 1
	ret

_while_sp: ; while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	cmp r10b, 9
	jz _sp
	cmp r10b, 10
	jz _sp
	cmp r10b, 11
	jz _sp
	cmp r10b, 12
	jz _sp
	cmp r10b, 13
	jz _sp
	cmp r10b, 32
	jz _sp
	ret

_sp:
	inc r8
	mov r10b, byte [rdi + r8]
	jmp _while_sp

_while_sign:
	cmp r10b, byte 43 ; str[i] == '+'
	jz _if_sign
	cmp r10b, byte 45 ; str[i] == '-'
	jz _if_sign_min
	ret

_if_sign:
	inc r8
	mov r10b, byte [rdi + r8]
	jmp _while_sign

_if_sign_min:
	imul r13, -1 ; sign *= -1
	inc r8
	mov r10b, byte [rdi + r8]
	jmp _while_sign

_while_str:
	cmp byte [rdi + r8], byte 0
	jz _end
	mov r10b, byte [rdi + r8]
	cmp r10b, byte 0 ; while (str)
	jz _end
	mov rcx, 0 ; count = 0
	call _while_base ; while (base[count] != str[i])
	cmp rcx, 0
	jl _end
	imul r12, r11 ; nb = nb * base_len
	add r12, rcx ; nb = nb + count
	inc r8 ; i++
	jmp _while_str

_while_base: ; while (base[count] != str[i])
	cmp byte [rsi + rcx], byte 0
	jz _end_error
	mov r9b, byte [rsi + rcx] ; base[count]
	cmp r9b, r10b ; base[count] != str[i]
	jnz _inc
	ret

_end_error:
	mov rcx, -1
	ret

_inc:
	inc rcx ; count++
	jmp _while_base

_end:
	mov rax, r12
	imul rax, r13 ; nb *= sign
	ret
