segment .text
global _start
_start:
    mov eax, 1 ; 1 is the exit system call
    mov ebx, 5 ; the status value
    int 0x80 ;execute system call interrupt
