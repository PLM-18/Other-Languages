section .data
    xor_key dd 0x73113777            ; The XOR key as a 32-bit integer

section .bss
    ciphertext resb 256              ; Reserve space for the ciphertext input (up to 256 characters)
    plaintext resb 256               ; Reserve space for the decrypted plaintext
    length   resd 1                  ; Reserve space for the length of the ciphertext

section .text
    extern printf, scanf             ; External C functions

    global _start
_start:
    ; Ask the user for input
    mov rdi, format_input            ; Load input format string
    mov rsi, ciphertext              ; Pointer to the ciphertext buffer
    call scanf

    ; Determine length of the ciphertext (assuming it's space-separated integers)
    call count_words                 ; Determine how many numbers (words) are in the input
    mov [length], eax                ; Store the length of the ciphertext

    ; Iterate over each number in the ciphertext
    xor rcx, rcx                     ; Clear rcx, used as a counter
decrypt_loop:
    ; Read the next number from the input
    mov rdi, format_scan_int         ; Load format string for scanning integer
    lea rsi, [ciphertext + rcx * 4]  ; Load address of the current position in ciphertext
    call scanf                       ; Read integer into eax

    ; XOR the number with the constant
    xor eax, [xor_key]               ; XOR with the key

    ; Rotate the character right by 4 bits
    ror al, 4                        ; Rotate the character by 4 bits to the right

    ; Store the decrypted character in the plaintext buffer
    mov [plaintext + rcx], al

    ; Move to the next number
    inc rcx
    cmp rcx, [length]                ; Compare counter to the number of words
    jl decrypt_loop

    ; Null-terminate the plaintext string
    mov byte [plaintext + rcx], 0

    ; Print the decrypted plaintext
    mov rdi, format_output           ; Load output format string
    mov rsi, plaintext               ; Pointer to the decrypted plaintext buffer
    call printf

    ; Exit the program
    mov rax, 60                       ; Exit system call
    xor rdi, rdi                      ; Exit code 0
    syscall

count_words:
    ; C function to count space-separated integers (words) in the input
    xor rax, rax
    xor rcx, rcx
    mov rdi, ciphertext
count_loop:
    cmp byte [rdi + rcx], 0
    je done_counting
    cmp byte [rdi + rcx], ' '
    jne skip_increment
    inc rax
skip_increment:
    inc rcx
    jmp count_loop
done_counting:
    inc rax    ; To account for the last word
    ret

section .rodata
    format_input db "Enter cipher text to decrypt: ", 0
    format_output db "The plaintext is: %s", 0        ; Output format to print the decrypted string
    format_scan_int db "%u", 0                        ; Format string to scan an unsigned integer
