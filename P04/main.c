#include <stdio.h>

typedef unsigned ui;

int any_odd_one(ui x){
    return !!(x & 0xAAAAAAAA); 
}

int main() {
    ui x = 0x00000001;
    ui y = 0x00000002;
    ui z = 0x55555555;

    printf("%d\n", any_odd_one(x)); // 0
    printf("%d\n", any_odd_one(y)); // 1
    printf("%d\n", any_odd_one(z)); // 0

    return 0;
}