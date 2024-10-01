global createStudent
extern malloc

section .data
    struc Student
        .name: resb 50 alignb 8
        .age: resd 1
        .marks: resq 1
    endstruc

section .text

createStudent:
    .name equ 0
    .age equ 8
    .marks equ 16

    push rbp
    mov rbp, rsp

    sub rsp, 24
    mov [rsp + createStudent.name], rdi
    mov [rsp + createStudent.age], rsi
    movsd [rsp + createStudent.marks], xmm0

    mov rdi, 24
    call malloc

    test rax, rax
    jz .exit

    mov rsi, [rsp + createStudent.name]
    lea rdi, [rax + Student.name]
    mov rcx, 50
    rep movsb

    mov rsi, [rsp + createStudent.age]
    mov rdi, [rax + Student.age]
    mov [rdi], rsi

    movsd xmm0, [rsp + createStudent.marks]
    mov rdi, [rax + Student.marks]
    movsd [rdi], xmm0

.exit:
    leave
    ret