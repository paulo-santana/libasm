section .text

global ft_strlen

ft_strlen:
  mov rax, rdi

main_loop:
  cmp byte [rax], 0
  je end
  inc rax
  jmp main_loop

end:
  sub rax, rdi
  ret
