global get_value

SECTION .text align=0

get_value:
  mov rax, msg
  ret

SECTION .data
  msg:    db  "Hello World from Brazil!", 0
  .len:   equ $ - msg
