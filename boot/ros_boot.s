.global _start
.extern stack_top
.extern kernel_main
.extern kernel_loop

_start:
    ldr x30, =stack_top
    mov sp, x30
    mov x0, #0

main:
    bl kernel_main

loop:
    bl kernel_loop
    b loop
