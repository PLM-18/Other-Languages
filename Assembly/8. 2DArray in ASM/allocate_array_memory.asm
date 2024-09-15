section .data

section .text
    global allocate_array_memory
    extern malloc

allocate_array_memory:
    push ebp
    mov ebp, esp
    push ebx
    push esi
    push edi

    mov eax, [ebp + 8]       ; row
    mov ebx, [ebp + 12]      ; col

    ; Allocate memory for float* array = malloc(row * sizeof(float*))
    push eax                 ; Push row to stack (malloc argument)
    mov ecx, 4               ; sizeof(float*) = 4 bytes
    imul eax, ecx            ; eax = row * sizeof(float*)
    push eax                 ; Push malloc argument
    call malloc              ; malloc(row * sizeof(float*))
    add esp, 4               ; Clean up stack after malloc
    mov edi, eax             ; edi = array (float**)

    ; Allocate memory for each row
    mov esi, [ebp + 8]       ; row count in esi
    xor ecx, ecx             ; ecx = 0 (row index)
allocate_rows_loop:
    cmp ecx, esi             ; Compare row index with row count
    jge done                 ; If ecx >= row, exit the loop

    ; Allocate memory for array[ecx] = malloc(col * sizeof(float))
    push ebx                 ; Push col to stack
    mov eax, 4               ; sizeof(float) = 4
    imul ebx, eax            ; eax = col * sizeof(float)
    push ebx                 ; Push malloc size (col * sizeof(float))
    call malloc              ; malloc(col * sizeof(float))
    add esp, 4               ; Clean up stack
    mov [edi + ecx * 4], eax ; Store malloc result in array[ecx]

    inc ecx                  ; ecx++
    jmp allocate_rows_loop   ; Repeat for the next row

done:
    mov eax, edi             ; Return the 2D array (float**)

    pop edi
    pop esi
    pop ebx
    leave
    ret
