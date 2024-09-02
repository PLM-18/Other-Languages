section .text
    global convertToFloat
    extern strtof

convertToFloat:
    push    rbp                  ; Save the base pointer
    mov     rbp, rsp             ; Set the new base pointer
    sub     rsp, 16              ; Allocate space on the stack

    mov [rbp-8], rdi
    mov rax, [rbp-8]
    mov esi, 0
    mov rdi, rax
    call strtof             

    leave                      
    ret                         
