ENTRY(_start)

__stack_size = 0x2000;
__stack_size_quarter = __stack_size / 4;

MEMORY
{
    boot : ORIGIN = 0x80000, LENGTH = 0x100

    text : ORIGIN = 0x10000, LENGTH = 0x10000
    data : ORIGIN = 0x20000, LENGTH = 0x10000
    bss : ORIGIN = 0x30000, LENGTH = 0x2000

    stack : ORIGIN = 0x32000, LENGTH = __stack_size
}

SECTIONS
{
    .text.boot : { *(.text.boot) } > boot
    .text : { *(.text) } > text
    .data : { *(.data) } > data
    .bss : { *(.bss COMMON) } > bss

    .stack : {
        __stack_bottom = .;
        . += __stack_size;
    } > stack
}