#! /bin/sh

# clear
make clean
make
objdump -b binary -m i8086 -D ./gui.com
