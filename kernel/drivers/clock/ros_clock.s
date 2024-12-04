.global clock_frequency
clock_frequency:
    mrs x0, cntfrq_el0
    isb
    ret

.global clock_uptime
clock_uptime:
    isb
    mrs x0, cntvct_el0
    isb
    ret
