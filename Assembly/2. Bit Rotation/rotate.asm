section .data
    msg db 'MOVE', 0 
    len equ $ - msg
    rotated db 4 dup(0)

section .bss

section .text
global _start

_start:
    lea esi, [msg]
    lea edi, [rotated]
    mov ecx, 4
rotate_loop:
    lodsb      
    add al, 4   
    stosb     
    loop rotate_loop

    ; Output the rotated string
    mov edx, 4 
    lea ecx, [rotated]
    mov ebx, 1  
    mov eax, 4  
    int 0x80  

    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80