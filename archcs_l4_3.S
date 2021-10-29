// Задание Л4.№3 Вариант № 5. Код вызывающей функции

.data
    fmt: .string "Returned value: x5 = %d\n"

.text
.globl main
main:

    sub $8, %rsp

    mov $1, %rcx
    mov $2, %rdx
    mov $3, %r8
    mov $4, %r9
    mov $5, %r10
    push %r10
    sub $32, %rsp
    call task3_cpp
    add $32, %rsp
    pop %r10

    lea fmt(%rip), %rcx
    mov %rax, %rdx
    sub $32, %rsp
    call printf
    add $32, %rsp

    add $8, %rsp
    xor %eax, %eax
    ret
