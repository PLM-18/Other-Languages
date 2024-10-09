segment .data
    name db "Bob",0
    address db "22 Duncun street",0
    balance dd 123

global _start
extern strcpy

_start:
    mov [rax], dword 7 ; dword so rax knows the size
    lea rdi, [rax+4]   ; moving the name to rdi
    lea rsi, [name]    ; the string to copy
    call strcpy         ; then call the function
    mov rax, [c]        ; retrive pointer to rax so rax hasn't changes

    lea rdi, [rax+75]
    lea rsi, [address]
    call strcpy
    mov rax, [c]

    mov edx, [balance]
    mov [rax+146], edx