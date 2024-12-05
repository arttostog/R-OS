ENTRY(_start)
SECTIONS
{
    . = 0x80000;
    .text : { *(.boot) *(.text) }
    .data : { *(.data) }
    . = ALIGN(16);
    .bss : { *(.bss) }

    __first_core_stack = .;
    . += 1024;
    __second_core_stack = .;
    . += 1024;
    __third_core_stack = .;
    . += 1024;
    __fourth_core_stack = .;
    . += 1024;
    __end = .;
}