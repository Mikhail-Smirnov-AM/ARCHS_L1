.text
.globl task1_asm
task1_asm:

    sub $8, %rsp
    mov %ecx, %eax
    imul $5, %eax
    mov %eax, %ecx
    mov %edx, %eax
    imul $2, %eax
    add %ecx, %eax
    add $657, %eax
    add $8, %rsp
    ret
