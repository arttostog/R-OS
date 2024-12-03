ENTRY(_start)
SECTIONS
{
    . = 0x40000000;
    .startup . : { ros_boot.o(.text) }
    .text : { *(.text) }
    .data : { *(.data) }
    .bss : { *(.bss COMMON) }
    . = ALIGN(8);
    . += 0x1000;
    stack_top = .;
}