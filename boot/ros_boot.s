.global _start
.extern stack

_start:
    ldr x30, =stack_top
    mov sp, x30
    mov x0, #0
    bl kernel_main
    bl halt

halt:
    wfi
    b halt
