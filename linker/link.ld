ENTRY(_start)

__stack_length = 0x1000;
__stack_length_quarter = __stack_length / 4;

MEMORY
{
    boot : ORIGIN = 0x80000, LENGTH = 0x100

    flash : ORIGIN = 0x10000, LENGTH = 0x9000
    ram : ORIGIN = 0x20000, LENGTH = 0x1000
    stack : ORIGIN = 0x25000, LENGTH = __stack_length
}

SECTIONS
{
    .text.boot : { *(.text.boot) } > boot
    .text : { *(.text) } > flash
    .data : { *(.data) } > flash
    .bss : { *(.bss COMMON) } > ram
    .stack : {
        __stack_bottom = .;
        . += __stack_length;
    } > stack
}