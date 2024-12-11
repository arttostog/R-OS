.section ".text.boot"

.global _start
.global get_current_core

.extern kernel_main
.extern kernel_loop
.extern kernel_tasks

_start:
    bl get_current_core
    cbz x0, first_core

    sub x1, x0, #1
    cbz x1, second_core

    sub x1, x0, #2
    cbz x1, third_core

    sub x1, x0, #3
    cbz x1, four_core

halt:
    wfi
    b halt

get_current_core:
    mrs x0, mpidr_el1
    and x0, x0, #0xff
    ret

bss_clean:
    ldr x1, = __bss_start
    ldr x2, = __bss_size
bss_clean_loop:
    cbz x2, bss_clean_loop_end
    str xzr, [x1], 8
    sub x2, x2, #1
    cbnz x2, bss_clean_loop
bss_clean_loop_end:
    ret

first_core:
    ldr x30, = _start
    mov sp, x30
    bl bss_clean
    bl kernel_main

loop:
    bl kernel_loop
    b loop

second_core:
    ldr x30, = __second_core_stack
    b tasks

third_core:
    ldr x30, = __third_core_stack
    b tasks

four_core:
    ldr x30, = __four_core_stack

tasks:
    mov sp, x30
    bl kernel_tasks
    b halt
