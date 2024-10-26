section .data


section .text

global readfile

readfile:
    push ebp
    mov ebp, esp
    sub esp, 8

    mov eax, [ebp + 8]
    mov ebx, [ebp + 12]
    mov ecx, [ebp + 16]
    mov edx, [ebp + 20]

    mov eax, 5
    mov ebx, eax
    mov ecx, [ebp + 8]
    mov edx, [ebp + 12]
    int 0x80

    mov eax, 6
    mov ebx, eax
    mov ecx, [ebp + 16]
    mov edx, [ebp + 20]
    int 0x80

    mov eax, 1
    mov ebx, eax
    mov ecx, 0
    int 0x80

    leave
    ret