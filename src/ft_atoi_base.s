global _ft_atoi_base ;int	ft_atoi_base(char *str, char *base)
extern _ft_strlen

; rcx -> count
; r8 -> int i
; r9 -> base (iterate heler)
; r10 -> str (iterate helper)
; r11 -> int base_len
; r12 -> int nb
; rdi -> char *str
; rsi -> char *base

_ft_atoi_base:
	mov r12, 0 ; nb = 0
	mov r8, 0 ; i = 0
	mov rcx, 0 ; count = 0
	push rdi
	mov rdi, rsi
	call _ft_strlen
	mov r11, rax ; base_len = ft_strlen(base)
	pop rdi
	call _while_str
	jmp _end

_while_str:
	cmp qword [rdi + r8], qword 0
	jz _end
	mov r10, [rdi + r8]
	cmp r10, 0 ; while (str)
	jz _end
	mov rcx, 0 ; count = 0
	push rsi
	push rdi
	call _while_base ; while (base[count] != str[i])
	pop rdi
	pop rsi
	;imul r12, r11 ; nb = nb * base_len
	add r12, rcx ; nb = nb + count
	inc r8 ; i++
	jmp _while_str

_while_base: ; while (base[count] != str[i])
	cmp qword [rsi + rcx], qword 0
	jz _end
	mov r9, [rsi + rcx] ; base[count]
	cmp r9, r10 ; base[count] != str[i]
	jnz _inc ; 

_inc:
	inc rcx ; count++
	jmp _while_base

_end:
	mov rax, r12
	;mov rax, r8
	ret
