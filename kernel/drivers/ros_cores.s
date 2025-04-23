.section ".text"

.global get_current_core

get_current_core:
    mrs x0, mpidr_el1
    and x0, x0, #0xff
    ret
