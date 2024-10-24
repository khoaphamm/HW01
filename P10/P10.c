#include <stdio.h>

typedef unsigned ui;

int leftmost_one(ui x){
    if (x == 0) return 0;

    
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    // make it into 0000...111111 form

    return x & ~(x >> 1);
    //extract leftmost 1
}

int main() {
    
    printf("0x%X\n", leftmost_one(0xFF00));
    printf("0x%X\n", leftmost_one(0x6600));


    return 0;
}