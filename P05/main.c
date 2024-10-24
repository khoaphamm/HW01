#include <stdio.h>

typedef unsigned ui;

int lower_one_mask(int n){
    if(n == 32) return 0xFFFFFFFF;
    return (1 << n) - 1;
}

int main() {
    
    printf("0x%X\n", lower_one_mask(6));
    printf("0x%X\n", lower_one_mask(17));
    printf("0x%X\n", lower_one_mask(32));

    return 0;
}