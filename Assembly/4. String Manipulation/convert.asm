section .data
    global convertStringToFloat

extern atof
convertStringToFloat:
    mov rdi, rdi
    // Call the atof function from the C standard library
    call atof
    // Return the result in st0
    ret