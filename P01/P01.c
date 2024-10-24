#include <stdio.h>

unsigned int func(unsigned int x, unsigned int y){
    return ((x & 0x000000FF) | (y & 0xFFFFFF00));
}

int main() {
    unsigned int x = 0x89ABCDEF;
    unsigned int y = 0x76543210;

    printf("0x");
    printf("%X\n", func(x, y));
    // This should print out 0x765432EF
    return 0;
}