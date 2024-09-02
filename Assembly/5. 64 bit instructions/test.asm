
BITS 64

section .data
section .bss
section .text

; Remove the global directive
_start:
    movq mm1, mm0
    movq mm2, mm7
    paddb mm1, mm2
    movq mm3, mm1
    movq mm4, mm1
    movq mm5, mm1
    movq mm6, mm1
    movq mm7, mm1
    movq mm0, mm1
    emms