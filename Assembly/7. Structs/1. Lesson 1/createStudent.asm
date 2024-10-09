BITS 64

global createStudent
extern malloc

section .data
    struc Student
        .name resb 50 align 8
        .age resb 1
        .gpa resb 1
    endstruc

section .text

; The function protptype is
; Student* createStudent(char *name, int age, float gpa);

createStudent:
    .name equ 0
    .age equ 8
    .gpa equ 16

    push rbp
    mov rbp, rsp

    sub rbp, 32
    mov [rsp + createStudent.name], rdi
    mov [rsp + createStudent.age], edx
    movsd [rsp + createStudent.gpa], xmm0

    mov rdi, 58
    call malloc

    test rax, rax
    jz .exit

    mov rsi, [rsp + createStudent.name]
    lea rdi, [rax + Student.name]
    mov rcx, 50
    rep movsb

    mov rsi, [rsp + createStudent.age]
    mov [rax + Student.age], esi

    movsd xmm0, [rsp + createStudent.gpa]
    movsd [rax + Student.gpa], xmm0

.exit:
    leave 
    ret
