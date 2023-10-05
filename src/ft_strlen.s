section .text

global ft_strlen

ft_strlen:
  mov rax, rdi
  jmp main_loop

main_loop:
  mov bl, byte [rax]
  cmp bl, 0
  je end
  inc rax
  jmp main_loop

end:
  sub rax, rdi
  ret
