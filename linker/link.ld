ENTRY(_start)

SECTIONS
{
    . = 0x80000;
    . = ALIGN(4096);
    .text : { *(.boot) *(.text) }
    .data : { *(.data) }
    .bss ALIGN(16) :
    {
        __bss_start = .;
        *(.bss COMMON)
        __bss_end = .;
    }

    . = ALIGN(4096);
    . += 1024;
    __first_core_stack = .;
    . += 1024;
    __second_core_stack = .;
    . += 1024;
    __third_core_stack = .;
    . += 1024;
    __fourth_core_stack = .;
}

__bss_size = (__bss_end - __bss_start) >> 3;