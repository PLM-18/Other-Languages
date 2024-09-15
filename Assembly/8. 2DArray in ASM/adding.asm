BITS 64

section .data

section .text
    global addMatrices

addMatrices:
    push rbx
    push r12
    push r13
    push r14
    push r15

    mov rdi, rdx
    mov rsi, rcx
    extern allocateMatrix
    call allocateMatrix
    mov r15, rax
    xor r12, r12

.loop:
    cmp r12, rcx
    je .end
    xor r13, r13

    .innerLoop:
        cmp r13, rdx
        je .nextRow
        mov rax, r12
        imul rax, rdx
        add rax, r13

        mov r14, [rdi + rax * 8]
        mov rbx, [rsi + rax * 8]

        add r14, rbx

        mov [r15 + rax * 8], r14
        inc r13
        jmp .innerLoop

    .nextRow:
        inc r12
        jmp .loop

.end:
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx

    mov rax, r15
    ret
