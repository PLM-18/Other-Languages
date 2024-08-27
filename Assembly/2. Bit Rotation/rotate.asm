section .data
    input db 'HELLO WORLD', 0  ; Input string
    shift db 3                 ; Shift value
    output db 12 dup(0)        ; Output buffer

section .bss

section .text
    global _start

_start:
    ; Initialize pointers
    mov rsi, input     ; Source pointer
    mov rdi, output    ; Destination pointer
    mov cl, [shift]    ; Load shift value

encrypt_loop:
    lodsb              ; Load byte from input into AL
    test al, al        ; Check if end of string (null terminator)
    jz done            ; If zero, end of string

    ; Check if character is uppercase letter
    cmp al, 'A'
    jb not_uppercase
    cmp al, 'Z'
    ja not_uppercase

    ; Encrypt uppercase letter
    sub al, 'A'
    add al, cl
    cmp al, 26
    jb no_wrap_upper
    sub al, 26
no_wrap_upper:
    add al, 'A'
    jmp store_char

not_uppercase:
    ; Check if character is lowercase letter
    cmp al, 'a'
    jb store_char
    cmp al, 'z'
    ja store_char

    ; Encrypt lowercase letter
    sub al, 'a'
    add al, cl
    cmp al, 26
    jb no_wrap_lower
    sub al, 26
no_wrap_lower:
    add al, 'a'

store_char:
    stosb              ; Store byte in output buffer
    jmp encrypt_loop   ; Repeat for next character

done:
    ; Print the encrypted string
    mov rdx, rdi       ; Length of the string
    sub rdx, output
    mov rsi, output    ; Pointer to the string
    mov rdi, 1         ; File descriptor (stdout)
    mov rax, 1         ; Syscall number (sys_write)
    syscall

    ; Exit program
    mov rax, 60        ; Syscall number (sys_exit)
    xor rdi, rdi       ; Exit code 0
    syscall