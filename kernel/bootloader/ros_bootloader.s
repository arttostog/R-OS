.section ".text.boot"

.global _start

.extern get_current_core

.extern kernel_start
.extern kernel_loop
.extern kernel_tasks

_start:
    ldr x30, = __stack_bottom

    bl get_current_core
    
    cbz x0, first_core

    and x1, x0, #3
    cbnz x1, other_cores

halt:
    wfi
    b halt

first_core:
    mov sp, x30
    mov x30, #0
    
    bl kernel_start

loop:
    bl kernel_loop
    b loop

other_cores:
    ldr x1, = __stack_size_quarter
    madd x30, x0, x1, x30
    mov x1, #0

    mov sp, x30
    mov x30, #0

    bl kernel_tasks
    b halt
