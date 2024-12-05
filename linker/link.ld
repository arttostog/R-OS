ENTRY(_start)
SECTIONS
{
    . = 0x80000;
    .text : { *(.text.boot) *(.text) }
    . = ALIGN(2048);
    .data : { *(.data) }
    . = ALIGN(2048);
    .bss : { *(.bss) }
    . = ALIGN(2048);
    stack_top = .;
}