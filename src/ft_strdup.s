section .text

extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

global ft_strdup

; rdi - string to copy
ft_strdup:
  mov r14, rdi            ; setup arg2 for ft_strcpy

  call ft_strlen          ; rax = ft_strlen(rdi)
  inc rax                 ; rax++

  mov rdi, rax            ; setup arg1 for malloc

  call malloc wrt ..plt   ; rax = malloc(rdi)

  cmp rax, 0
  jg continue
  ret

continue:
  mov rdi, rax
  mov rsi, r14
  call ft_strcpy
  ret
