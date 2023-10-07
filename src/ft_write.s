extern __errno_location

section .text

global ft_write

ft_write:
  call __errno_location wrt ..plt ; get errno address
  mov r15, rax                    ; save at r15
  mov qword [r15], 0              ; reset errno value to 0
  mov rax, 1                      ; load sys_write
  syscall                         ; execute syscall with the default parameters
  cmp rax, 0                      ; check if it returned any negative value
  jl err                          ; handle errors
  ret

err:
  neg rax                         ; change the error number to a positive int
  mov [r15], rax                  ; load the error number to errno location
  mov rax, -1                     ; set the error return value
  ret
