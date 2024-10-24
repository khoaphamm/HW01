#include <stdio.h>

typedef unsigned ui;

ui replace_byte (ui x, int i, unsigned char b){
    ui mask = 0xFFFFFFFF;
    if (i >= 4) return 0;
    i = i << 3;
    
    mask = mask ^ (0xFF << i);

    x &= mask;
    return x | ((ui)b << i);
}

int main() {
    unsigned int x = 0x12345678;

    printf("0x%X\n", replace_byte(x, 2, 0xAB));
    //This gives 0x12AB5678
    printf("0x%X\n", replace_byte(x, 0, 0xAB));
    //This gives 0x123456AB
    return 0;
}