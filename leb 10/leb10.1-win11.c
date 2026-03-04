#include <stdio.h>

long SumLoop(int n) {
    long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

long SumRecur(int n) {
    if (n <= 1) {
        return n;
    }
    return n + SumRecur(n - 1);
}

int main() {
    printf("SumLoop(10) = %ld\n", SumLoop(10));
    printf("SumRecur(10) = %ld\n", SumRecur(10));
    
    // ทดลองใช้ค่า n สูงๆ เพื่อให้เกิด run-time error
    printf("\n--- Testing with large n values ---\n");
    
    // ทดสอบ SumLoop กับค่าสูง
    printf("SumLoop(1000000) = %ld\n", SumLoop(1000000));
    printf("SumLoop(10000000) = %ld\n", SumLoop(10000000));
    printf("SumLoop(100000000) = %ld\n", SumLoop(100000000));
    
    // ทดสอบ SumRecur กับค่าสูง (จะเกิด stack overflow)
    printf("SumRecur(10000) = %ld\n", SumRecur(10000));
    // printf("SumRecur(100000) = %ld\n", SumRecur(100000)); // จะเกิด stack overflow
    
    return 0;
}