ENTRY(_start)

__stack_origin = 0x25000;
__stack_length = 0x1000;
__stack_length_quarter = __stack_length / 4;

MEMORY
{
    boot : ORIGIN = 0x80000, LENGTH = 0x1000
    
    flash : ORIGIN = 0x10000, LENGTH = 0x10000
    ram : ORIGIN = 0x20000, LENGTH = 0x5000
    stack : ORIGIN = __stack_origin, LENGTH = __stack_length
}

SECTIONS
{
    .text : { *(.text.boot) } > boot
    .text : { *(.text) } > flash
    .data : { *(.data) } > flash
    .bss : {
        __bss_start = .;
        *(.bss COMMON)
        __bss_end = .;
    } > ram

    stack_pointer = __stack_origin;
    __first_core_stack = stack_pointer;

    stack_pointer += __stack_length_quarter;
    __second_core_stack = stack_pointer;

    stack_pointer += __stack_length_quarter;
    __third_core_stack = stack_pointer;

    stack_pointer += __stack_length_quarter;
    __four_core_stack = stack_pointer;
}

__bss_size = (__bss_end - __bss_start) >> 3;