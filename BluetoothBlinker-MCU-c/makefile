CC="arm-none-eabi-gcc"
OBJCOPY="arm-none-eabi-objcopy"
MFLAGS= -mthumb
CFLAGS= -O0 -Wall -march=armv7-m -mthumb -mcpu=cortex-m3 -std=gnu11 -include"stdint.h" -ffunction-sections -fdata-sections -g3 -gdwarf-3 -gstrict-dwarf
DEFINES= -DDeviceFamily_CC26X0R2
LINKER= -T./linker.ld 
INCLUDES_PATHS= \
	./app/ \
	./ble/ \
	./cc26x0r2/startup_files/ \
	./drivers/ \
	./mcu/ \
	./

SRC_PATHS= \
	./cc26x0r2/startup_files/startup_gcc.c \
	./app/app.c \
	./ble/ble.c \
	./mcu/mcu.c \
	./main.c

INCLUDES=$(addprefix -I,$(INCLUDES_PATHS))
BUILD_DIR=./output
SRCS=$(notdir $(SRC_PATHS))
OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS=$(OBJS:%.o=%.d)
TARGET=BluetoothBlinker-MCU
vpath %.h $(INCLUDES_PATHS)
vpath %.c $(dir $(SRC_PATHS))

application: $(BUILD_DIR)/$(TARGET)
	@echo "Build complete!"

$(BUILD_DIR)/$(TARGET): $(OBJS)
	@echo "linking final target: $(notdir $@)"
	$(CC) $(DEFINES) $(CFLAGS) -nostartfiles -static  -o $@.elf $(OBJS) $(MFLAGS) $(LINKER) -lnosys
	$(OBJCOPY) -O binary $@.elf $@.bin
	$(OBJCOPY) -O ihex -R .eeprom -R .fuse -R .lock -R .signature $@.elf $@.hex
	@cp $@.elf $@

$(BUILD_DIR)/%.o: %.c
	@echo "assembling object file: $(notdir $@)"
	@mkdir -p $(dir $@)
	@$(CC) -x c $(MFLAGS) $(DEFINES) $(INCLUDES) $(CFLAGS) -c -MMD -MP -o $@ $<

.PHONY: clean
clean:
	rm -rf ./output 

-include $(DEPS)
