.data
s: .string "z= %d\n"
x: .int 1
y: .int 0
.text
.globl main
main:
sub $8, %rsp
mov x, %ecx
mov y, %edx
sub $32, %rsp
call task1_asm
add $32, %rsp
lea s(%rip), %rcx
mov %eax, %edx
sub $32, %rsp
call printf
add $32, %rsp
add $8, %rsp
xor %eax, %eax
ret
