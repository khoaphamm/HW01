#include <stdio.h>

typedef unsigned ui;

int A(int k){
    if(k >= 32)
        return 0;
    
    return ((1 << k) - 1) ^ (0xFFFFFFFF);
}

int B(int k, int j){
    if(k + j >= 32) return 0;
    return ((1 << (k + j)) - 1) ^ ((1 << j) - 1);
}

void print_binary(ui n) {
    for (int i = sizeof(ui) * 8 - 1; i >= 0; i--) {
        printf("%c", (n & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

int main() {
    ui result1 = A(6);
    ui result2 = A(17);
    ui result3 = A(32);

    ui result4 = B(3, 6);
    ui res = B(6, 10);

    print_binary(result1);
    print_binary(result2);
    print_binary(result3);

    print_binary(result4);
    print_binary(res);

    return 0;
}