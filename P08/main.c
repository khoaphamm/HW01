#include <stdio.h>

typedef unsigned ui;

int func(int x){
    return (x + (-x >> 2));    
}

int main() {
    
    int x = 40;
    printf("%d\n", func(x));

    return 0;
}