section .data
    msg  db 'Hello world',0xa  
    len  equ $ - msg  

section .text
global  _start 
_start: 
    mov  edx,len   
    mov  ecx,msg   
    mov  ebx,1   
    mov  eax,4   
    syscall 

    mov  eax,1  
    xor  ebx,ebx
    syscall  
