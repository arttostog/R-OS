ENTRY(_start)
SECTIONS
{
    flash_data 0x00100000 : { ./build/objects/flash.o }

    . = 0x40000000;
    .startup . : { ./build/objects/ros_boot.o(.text) }
    .text : { *(.text) }
    . = ALIGN(2048);
    .data : { *(.data) }
    . = ALIGN(2048);
    .bss : { *(.bss) }
    . = ALIGN(2048);
    stack_top = .;
}