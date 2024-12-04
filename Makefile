BUILD_DIRECTORY = ./build/
OBJECTS_DIRECTORY = $(BUILD_DIRECTORY)objects/

CREATE_DIRS = mkdir "$(OBJECTS_DIRECTORY)"
REMOVE_DIRS = rmdir /s /q "$(BUILD_DIRECTORY)"

AS = aarch64-none-elf-as

G++ = aarch64-none-elf-g++
PATH_TO_LINKER = ./linker/link.ld
G++_FLAGS = -ffreestanding -I./include -nostdlib -T $(PATH_TO_LINKER)

OUTPUT = $(BUILD_DIRECTORY)R-OS.elf

QEMU = qemu-system-aarch64
QEMU_FLAGS = -machine virt -cpu cortex-a57 -kernel $(OUTPUT) -nographic

$(OUTPUT) :
	$(CREATE_DIRS)
	$(AS) ./boot/ros_boot.s -o $(OBJECTS_DIRECTORY)ros_boot.o
	$(G++) $(G++_FLAGS) $(wildcard ./kernel/*.cpp ./kernel/*/*.cpp ./kernel/*.s $(OBJECTS_DIRECTORY)*.o) -o $(OUTPUT)

run:
	$(QEMU) $(QEMU_FLAGS)

clean:
	$(REMOVE_DIRS)