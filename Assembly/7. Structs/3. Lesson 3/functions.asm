BITS 64

section .data
    msg db "Welcome to the Program ", 0
    buffer resb 256

global AddInts
global MulBy
global Sub5x
global printer

extern strcat

segment .text
AddInts:
    mov eax, edi
    add eax, esi
    add eax, ecx
    add eax, edx
    ret

MulBy:
    mov eax, edi
    imul eax, 17
    ret

Sub5x:
    imul esi, 5
    sub edi, esi
    mov eax, edi
    ret 

printer:
    mov rsi, msg
    call strcat

    mov rsi, rdi
    call strcat

    mov rax, buffer
    ret
