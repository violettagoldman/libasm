global _ft_atoi_base ;int	ft_atoi_base(char *str, char *base)
extern _ft_strlen

; rcx -> count
; r8 -> int i
; r9 -> base (iterate heler)
; r10 -> str (iterate helper)
; r11 -> int base_len
; r12 -> int nb
; r13 -> sign
; rdi -> char *str
; rsi -> char *base

_ft_atoi_base:
	mov r12, 0 ; nb = 0
	mov r8, 0 ; i = 0
	mov rcx, 0 ; count = 0
	mov r13, 1 ; sign = 1
	push rdi
	mov rdi, rsi
	call _ft_strlen
	mov r11, rax ; base_len = ft_strlen(base)
	pop rdi
	mov r10b, byte [rdi + r8]
	call _while_sign
	jmp _while_str

_while_sign:
	cmp r10b, byte 43 ; str[i] == '+'
	jz _if_sign
	cmp r10b, byte 45 ; str[i] == '-'
	jz _if_sign
	ret

_if_sign: ; if (str[i++] == '-')
	cmp r10b, byte 45
	call _if_sign_min
	inc r8
	mov r10b, byte [rdi + r8]
	jmp _while_sign

_if_sign_min:
	imul r13, -1 ; sign *= -1
	ret

_while_str:
	cmp byte [rdi + r8], byte 0
	jz _end
	mov r10b, byte [rdi + r8]
	cmp r10b, byte 0 ; while (str)
	jz _end
	mov rcx, 0 ; count = 0
	call _while_base ; while (base[count] != str[i])
	imul r12, r11 ; nb = nb * base_len
	add r12, rcx ; nb = nb + count
	inc r8 ; i++
	jmp _while_str

_while_base: ; while (base[count] != str[i])
	cmp qword [rsi + rcx], qword 0
	jz _end
	mov r9b, byte [rsi + rcx] ; base[count]
	cmp r9b, r10b ; base[count] != str[i]
	jnz _inc
	ret

_inc:
	inc rcx ; count++
	jmp _while_base

_end:
	mov rax, 0
	mov rax, r12
	imul rax, r13 ; nb *= sign
	ret
