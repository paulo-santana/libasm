SECTION .rodata
  msg:    db  "Hello World from Brazil!", 0
  .len:   equ $ - msg

SECTION .text

global get_value

get_value:
  mov rax, msg
  ret
