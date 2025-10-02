# Alternative Makefile - using objcopy for cleaner 16-bit output

flags := -fno-stack-protector -O0 -Wall -std=gnu23 -m16
flags += -ffreestanding -fno-pic -fno-pie -I include
ldflags := -m elf_i386 --nmagic --script=gui.ld

objects := main.o
xobjects := xgfx.o
NASMENV := -i include/asm/
export NASMENV

.PHONY: clean all

all: gui.com

gui.com: $(objects) $(xobjects)
	ld $(ldflags) $^ -o $@

main.o: main.c
	cc $(flags) -c $< -o $@

xgfx.o: xgfx.asm
	nasm -f elf32 $(NASMENV) $< -o $@

clean:
	rm -f *.o *.com *.elf

# Debug target to see what's being produced
info:
	@echo "Objects: $(objects) $(xobjects)"
	@file *.o 2>/dev/null || true
