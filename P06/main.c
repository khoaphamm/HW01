#include <limits.h>
#include <stdio.h>

int isPos(int x){
    return !((x >> 31) & 1);
}

int saturating_add(int x, int y) {
    int sum = x + y;
    
    // Detect positive overflow
    int pos_overflow = (isPos(x) & isPos(y) & !isPos(sum));
    
    // Detect negative overflow
    int neg_overflow = (!isPos(x) & !isPos(y) & isPos(sum));
    
    // Create masks for overflow conditions
    int pos_mask = INT_MAX & ((int)0xFFFFFFFF + !pos_overflow);
    int neg_mask = INT_MIN & ((int)0xFFFFFFFF + !neg_overflow);


    
    // Return TMax if positive overflow, TMin if negative overflow, otherwise return sum
    return (pos_mask | neg_mask | (((int) 0xFFFFFFFF + pos_overflow + neg_overflow) & sum));
}

int main(){

    int x1 = (int) -2;
    int y1 = (int) -3;

    int x2 = (int) 2;
    int y2 = (int) 1;

    int x3 = (int) 2e9;
    int y3 = (int) 1e9;

    int x4 = (int) -2e9;
    int y4 = (int) -1e9;


    printf("#1 Result : %d\n", saturating_add(x1, y1));
    printf("#2 Result : %d\n", saturating_add(x2, y2));
    printf("#3 Result : %d\n", saturating_add(x3, y3));
    printf("#4 Result : %d\n", saturating_add(x4, y4));
    return 0;
}