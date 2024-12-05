KERNEL_DIRECTORY = ./kernel/
INCLUDE_DIRECTORY = ./include
BUILD_DIRECTORY = ./build/

CREATE_DIRS = if not exist "$(BUILD_DIRECTORY)" (mkdir "$(BUILD_DIRECTORY)")
REMOVE_DIRS = if exist "$(BUILD_DIRECTORY)" (rmdir /s /q "$(BUILD_DIRECTORY)")

AS = aarch64-none-elf-as

G++ = aarch64-none-elf-g++
PATH_TO_LINKER = ./linker/link.ld
G++_FLAGS = -Wall -nostartfiles -nostdinc -ffreestanding -I$(INCLUDE_DIRECTORY) -nostdlib -T $(PATH_TO_LINKER)

rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

OUTPUT = $(BUILD_DIRECTORY)R-OS.elf

QEMU = qemu-system-aarch64
QEMU_FLAGS = -machine virt -cpu cortex-a57 -device virtio-gpu-pci -m 128M -kernel $(OUTPUT) -nographic

$(OUTPUT) :
	$(CREATE_DIRS)
	$(G++) $(G++_FLAGS) $(call rwildcard,.,*.cpp *.s) -o $(OUTPUT)

run:
	$(QEMU) $(QEMU_FLAGS)

clean:
	$(REMOVE_DIRS)