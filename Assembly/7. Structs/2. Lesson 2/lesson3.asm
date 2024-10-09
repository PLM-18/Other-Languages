segment .data
  format db "%s %s %d",0x0a,0

struct Customer
  c_id resd 1 ; 4 bytes in total
  c_name resb 65 ; 69 bytes in total
  c_address resb 65 align 4 ; aligns to 136
  c_balance resd 1 ; 140 bytes total
  c_rank resb 1 align 4 ; aligns to 144
endstruc

customers dq 0

segement .text
  mov rdi, 100 ; for 100 structs
  imul rdi, Customer_size
  call malloc
  mov [customers], rax

print:
  push rbp
  mov rbp, rsp
  push r15
  push r14
  mov r15, 100
  mov r14, [customers]

more:
  lea rdi, [format]
  lea rsi, [r14,c_name]
  mov ecx, [r14+c_address]
  mov ecx, [r14+c_balance]
  call printf

  add r14, Customer_size
  dec r15
  jnz more
  pop r14
  pop r15
  leave 
  ret
