section .data

;extern float* allocate_array_memory(int n);
section .text
    global allocate_array_memory
    extern malloc

allocate_array_memory:
    push ebp
    mov ebp, esp
    push ebx
    push esi
    push edi

    mov eax, [ebp + 8]
    mov ebx, 4
    mul ebx
    push eax
    call malloc
    add esp, 4

    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret