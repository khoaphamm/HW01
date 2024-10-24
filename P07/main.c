#include <stdio.h>

typedef unsigned ui;

int A(int x){
    return (x << 4) + x;    
}

int B(int x){
    return (-x << 3) + x;
}

int C(int x){
    return (x << 6) - (x << 2);
}

int D(int x){
    return (-x << 7) + (x << 4);
}

int main() {
    
    int x = 10;

    printf("%d\n", A(x));
    printf("%d\n", B(x));
    printf("%d\n", C(x));
    printf("%d\n", D(x));

    return 0;
}