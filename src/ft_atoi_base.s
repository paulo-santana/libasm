section .data
  lookup_table times 256 db 0     ; reserve 256 bytes
  lookup_table_index db 0 ;

global ft_atoi_base

section .text

; is_space(' ') == 1

; arguments
; rdi - the character to check
is_space:
  xor rax, rax
  cmp rdi, ' '
  je isspace_true
  cmp rdi, 9
  jl isspace_false
  cmp rdi, 13
  jg isspace_false
  jmp isspace_true

isspace_false:
  mov rax, 0
  ret

isspace_true:
  mov rax, 1
  ret


; ft_atoi_base("01010", "01") == 10

; arguments
; rdi - the number as string
; rsi - the base characters

; internal registers
; rax - temporary values and return value
; rdx - the base size
; r9  - pointer backup
; r10 - pointer to lookup_table
; r11 - sign multiplier
ft_atoi_base:
  xor rax, rax        ; initialize rax to 0
  xor rdx, rdx        ; initialize base size to 0
  mov r9, rsi         ; save base pointer
  mov r11, 1
  lea r10, [rel lookup_table] ; load lookup_table address

clear_lookup_table:
  mov qword [r10 + rax], -1  ; fill 8 bytes with value 255 each
  add rax, 8                   ; increment pointer by 8
  cmp rax, 256                 ; check if finished the table
  jne clear_lookup_table       ; do it again until finished
  xor rax, rax

validate_base_loop:
  cmp byte [rsi], 0          ; compare end of string
  je validate_base_end
  mov al, byte [rsi]         ; get byte for comparison
  cmp byte [r10 + rax], 0xff ; check if base character is repeated
  jne error
  cmp al, '-'                ; those are self explanatory
  je error
  cmp al, '+'
  je error

  push rax                  ; prepare checking if byte is space
  push rdi
  mov rdi, rax
  call is_space
  pop rdi
  cmp rax, 1                ; return error if byte is space
  pop rax
  je error

  mov byte [r10 + rax], dl  ; save digit for checking duplicity
  inc rsi                   ; increment base pointer
  inc rdx                   ; increment base size
  jmp validate_base_loop

validate_base_end:
  cmp rdx, 1                ; return error if base size is less than 2
  jle error
  mov rsi, r9               ; restore the base pointer
  mov r9, rdi               ; save the number pointer
  push rdi
  xor rdi, rdi
  dec r9                    ; for the ++p operations

skip_spaces_loop:
  inc r9                    ; ++p
  mov dil, byte [r9]
  call is_space
  cmp rax, 1                ; continue while is space
  je skip_spaces_loop
  pop rdi

; the first - and + characters should be skipped
validate_input_signs_loop:
  mov dil, byte [r9]
  cmp dil, '+'
  je skip_sign
  cmp dil, '-'
  jne parse_number
  neg r11

skip_sign:
  inc r9
  jmp validate_input_signs_loop

; r9 is now pointing to the first digit of the number
parse_number:
  xor rax, rax
  xor r8, r8

; get the current digit value
; check if it's in the base
; if invalid return the value computed so far
; multiply the accumulated value by the base size
; add the current digit value
parse_number_loop:
  mov r8b, byte [r9]
  cmp byte [r10 + r8], 0xff
  je end
  mov r8b, byte [r10 + r8]
  imul rax, rdx
  add rax, r8
  inc r9
  jmp parse_number_loop

end:
  imul rax, r11
  ret

error:
  mov rax, 0
  ret
