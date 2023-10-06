section .text

global ft_strcmp

; rdi - 1st string
; rsi - 2nd string
ft_strcmp:
  xor rax, rax          ; initialize rax to 0

main_loop:
  mov al, byte [rdi]  ; get current byte from 1st string
  cmp al, byte [rsi]  ; compare with current byte from 2nd string
  jne end             ; end if different
  cmp byte [rsi], 0   ; check if string finished
  je end              ; end if string finished
  inc rdi
  inc rsi
  jmp main_loop

end:
  sub al, byte[rsi]
  jz EQUAL
  js LESSER
  jns GREATER

EQUAL:
  ret
LESSER:
  mov rax, -1
  ret
GREATER:
  mov rax, 1
  ret
