BITS 64

global createStudent
extern malloc
extern strcpy

section .data
    struc Student
        .age resd 1
        .name resb 50 
        align 8
        .gpa resq 1 
        align 4
    endstruc

section .text

; The function prototype is
; Student* createStudent(char *name, int age, float gpa);

createStudent:
    push rbp
    mov rbp, rsp

    sub rsp, 32
    mov [rsp + 0], rdi
    mov [rsp + 8], esi
    movss [rsp + 16], xmm0

    mov rdi, Student_size
    call malloc

    test rax, rax
    jz .exit

    mov esi, [rsp + 8]
    mov [rax + Student.age], esi

    mov rsi, [rsp + 0]
    lea rdi, [rax + Student.name]
    mov rcx, 50
    rep movsb

    movsd xmm0, [rsp + 16]
    movsd [rax + Student.gpa], xmm0

    leave
    ret

.exit:
    leave 
    ret