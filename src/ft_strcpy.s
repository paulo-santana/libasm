section .text

global ft_strcpy

; rdi - destination buffer
; rsi - source string
ft_strcpy:
  mov rbx, rdi
  jmp copy

copy:
  cmp byte [rsi], 0
  je end
  mov al, [byte rsi]
  mov byte [rbx], al
  inc rsi
  inc rbx
  jmp copy

end:
  mov al, [byte rsi]
  mov byte [rbx], al
  mov rax, rdi
  ret
