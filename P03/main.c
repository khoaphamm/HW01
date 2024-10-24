#include <stdio.h>

typedef unsigned ui;

int A(int x){
    return !!x;
}

int B(int x){
    int y = x ^ (0xFFFFFFFF);
    return A(y);
}

int C(int x){
    int y = x & (0x000000FF);
    return A(y);
}

int D(int x){
    int y = x | (0x00FFFFFF);
    return B(y);
}


int main() {
    ui x1 = 0x00000001;
    ui x2 = 0x00000000;

    ui x3 = 0xFEFFFFFF;
    ui x4 = 0xFFFFFFFF;

    ui x5 = 0x00000010;
    ui x6 = 0xFFFFFF00;

    ui x7 = 0xFDFFFFFF;
    ui x8 = 0xFF000000;

    printf("A(x1) = %d\n", A(x1)); // 1
    printf("A(x2) = %d\n", A(x2)); // 0

    printf("B(x3) = %d\n", B(x3)); // 1
    printf("B(x4) = %d\n", B(x4)); // 0

    printf("C(x5) = %d\n", C(x5)); // 1
    printf("C(x6) = %d\n", C(x6)); // 0

    printf("D(x7) = %d\n", D(x7)); // 1
    printf("D(x8) = %d\n", D(x8)); // 0

    return 0;
}