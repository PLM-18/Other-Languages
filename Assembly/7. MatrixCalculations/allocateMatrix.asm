section .data

section .bss
    matrix resq 1

section .text
    extern malloc
    global allocateMatrix

allocateMatrix:
    ; Input: rows in rdi, cols in rsi
    ; Allocate memory for rows pointers
    mov rax, rdi
    shl rax, 3          ; rows * sizeof(float*)
    call malloc
    test rax, rax       ; check if malloc succeeded
    jz .allocation_failed
    mov [matrix], rax   ; store the pointer to the array of pointers

    ; Loop through each row
    xor rcx, rcx        ; i = 0
.loop_rows:
    cmp rcx, rdi
    jge .end_loop_rows

    ; Allocate memory for each row
    mov rax, rsi
    shl rax, 2          ; cols * sizeof(float)
    call malloc
    test rax, rax       ; check if malloc succeeded
    jz .allocation_failed
    mov rbx, [matrix]
    mov [rbx + rcx*8], rax

    inc rcx
    jmp .loop_rows

.end_loop_rows:
    mov rax, [matrix]   ; return the pointer to the matrix
    ret

.allocation_failed:
    mov rax, 0          ; return NULL on failure
    ret