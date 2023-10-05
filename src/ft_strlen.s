section .text

global ft_strlen

ft_strlen:
  mov rsi, rax
  jmp label

label:
  mov dil, [rsi]
  cmp dil, 0
  je end
  inc rsi
  loop label

end:
  sub rsi, rax
  mov rax, rsi
  ret

section .data
  char: db 0
