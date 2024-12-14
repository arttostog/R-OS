ENTRY(_start)

MEMORY
{
    ram : ORIGIN = 0x80000, LENGTH = 0x8000
}

SECTIONS
{
    .text : { *(.text.boot) *(.text) } > ram
    .data : { *(.data) } > ram
    .bss ALIGN(16) : {
        __bss_start = .;
        *(.bss COMMON)
        __bss_end = .;
    } > ram

    . = ALIGN(4096);
    __first_core_stack = .;

    . += 1024;
    __second_core_stack = .;

    . += 1024;
    __third_core_stack = .;

    . += 1024;
    __four_core_stack = .;
}

__bss_size = (__bss_end - __bss_start) >> 3;