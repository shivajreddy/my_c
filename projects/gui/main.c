asm(".code16gcc\n"
    "call main\n"
    "call exit");

// #include <stdio.h>

void main2() {
    // printf("hello there");
    return;
}

void main() {
    char* vga = (char*)0xb8000;
    vga[0] = 'H';
    vga[1] = 0x07; // white on black
}
