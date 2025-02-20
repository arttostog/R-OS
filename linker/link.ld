ENTRY(_start)

__stack_length = 0x2000;
__stack_length_quarter = __stack_length / 4;

MEMORY
{
    boot : ORIGIN = 0x80000, LENGTH = 0x100

    text : ORIGIN = 0x10000, LENGTH = 0x10000
    data : ORIGIN = 0x20000, LENGTH = 0x10000
    bss : ORIGIN = 0x30000, LENGTH = 0x2000

    stack : ORIGIN = 0x32000, LENGTH = __stack_length
}

SECTIONS
{
    .text.boot : { *(.text.boot) } > boot
    .text : { *(.text) } > text
    .data : { *(.data) } > data
    .bss : { *(.bss COMMON) } > bss

    .stack : {
        __stack_bottom = .;
        . += __stack_length;
    } > stack
}