OUTPUT = R-OS.elf

AS = aarch64-none-elf-as
G++ = aarch64-none-elf-g++
QEMU = qemu-system-aarch64

G++_FLAGS = -ffreestanding -I./include -nostdlib -T ./linker/link.ld
QEMU_FLAGS = -machine virt -cpu cortex-a57 -kernel $(OUTPUT) -nographic

ifeq ($(OS), Windows_NT)
	CLEAN_COMMAND = del *.o $(OUTPUT)
else
	CLEAN_COMMAND = rm *.o $(OUTPUT)
endif

$(OUTPUT) :
	$(AS) ./boot/ros_boot.s -o ros_boot.o
	$(AS) ./kernel/ros_system.s -o ros_system.o
	$(G++) $(G++_FLAGS) $(wildcard ./kernel/*.cpp ./kernel/drivers/*.cpp) *.o -o $(OUTPUT)

run:
	$(QEMU) $(QEMU_FLAGS)

clean:
	$(CLEAN_COMMAND)