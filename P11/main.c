#include <stdio.h>

typedef unsigned ui;

int odd_ones(unsigned x) {
    
    //compress parity from 32 bit to 1 bit
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    // 32 -> 16 -> 8 -> 4 -> 2 -> 1 bit

    // The least significant bit now contains the parity (0 if even, 1 if odd)
    return x & 1;
}

int main() {
    printf("%d\n", odd_ones(0xFF00)); 
    printf("%d\n", odd_ones(0x6400)); 
    printf("%d\n", odd_ones(0xFFFFFFFF)); 
    printf("%d\n", odd_ones(0x0)); 

    return 0;
}