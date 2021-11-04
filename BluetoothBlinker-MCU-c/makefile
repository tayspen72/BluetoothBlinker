CC="arm-none-eabi-gcc"
OBJCOPY="arm-none-eabi-objcopy"
MFLAGS= -mthumb
CFLAGS= -O0 -g3  -Wall -mcpu=cortex-m3 -std=gnu11 -include"stdint.h"
DEFINES= 
LINKER= 
INCLUDES_PATHS= \
	./app/ \
	./ble/ \
	./drivers/ \
	./mcu/ \
	./

SRC_PATHS= \
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
	$(CC) -o $@.elf $(OBJS) $(MFLAGS) $(LINKER)
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
