.section ".text.boot"

.global _start

.extern stack_top
.extern kernel_main
.extern kernel_loop

_start:
    mrs x1, mpidr_el1
    and x1, x1, #3
    cbz x1, main

halt:
    wfe
    b halt

main:
    ldr x30, =stack_top
    mov sp, x30
    mov x0, #0

    bl kernel_main

loop:
    bl kernel_loop
    b loop
