.section ".text.boot"

.global _start
.global get_current_core

.extern kernel_start
.extern kernel_loop
.extern kernel_tasks

get_current_core:
    mrs x0, mpidr_el1
    and x0, x0, #0xff
    ret

_start:
    bl get_current_core
    
    ldr x30, = __stack_bottom

    cbz x0, first_core

    and x1, x0, #3
    cbz x1, halt
    mov x1, #0

    b other_cores

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
    ldr x1, = __stack_length_quarter
    madd x30, x0, x1, x30
    mov x1, #0

    mov sp, x30
    mov x30, #0

    bl kernel_tasks
    b halt
