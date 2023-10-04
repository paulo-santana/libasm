SECTION .rodata
  msg:    db  "Hello, world!", 10
  len:   equ $ - msg

SECTION .text

global print_hello

print_hello:
  mov rax, 1      ; write
  mov rdi, 1      ; stdout
  mov rsi, msg    ; msg pointer
  mov rdx, len    ; length in bytes
  syscall         ; write(stdout, msg, msg));
  ret
