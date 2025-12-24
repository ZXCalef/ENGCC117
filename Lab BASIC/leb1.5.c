#include <stdio.h>

int main() {
    int number;
    int evenSum = 0;
    int oddSum = 0;
    
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    
    while (number != 0) {
        if (number % 2 == 0) {
            evenSum += number;  // คู่
        } else {
            oddSum += number;   // คี่
        }
        
        if (scanf("%d", &number) != 1) {
            break;
        }
    }
    
    printf("Even Sum: %d\n", evenSum);
    printf("Odd Sum: %d\n", oddSum);
    return 0;
}