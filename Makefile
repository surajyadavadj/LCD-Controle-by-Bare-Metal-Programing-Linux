PROJECT = led_pa5
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -O0 -Wall -nostdlib
LDFLAGS = -T stm32f4.ld

all: main.c
	$(CC) $(CFLAGS) main.c -o $(PROJECT).elf $(LDFLAGS)
	arm-none-eabi-objcopy -O binary $(PROJECT).elf $(PROJECT).bin
	arm-none-eabi-objcopy -O ihex $(PROJECT).elf $(PROJECT).hex

flash:
	openocd -f board/st_nucleo_f4.cfg -c "program $(PROJECT).elf verify reset exit"

clean:
	rm -f *.elf *.bin *.hex

