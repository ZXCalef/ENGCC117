#include <stdio.h>

int main() {
    int number;
    int evenSum = 0;
    int oddSum = 0;
    
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    
    if (number != 0) {
        if (number % 2 == 0) {
            evenSum += number;
        } else {
            oddSum += number;
        }
    }
    
    while (1) {
        if (scanf("%d", &number) != 1) {
            return 1;
        }
        
        if (number == 0) {
            break;
        }
        
        if (number % 2 == 0) {
            evenSum += number;
        } else {
            oddSum += number;
        }
    }
    
    printf("Even Sum: %d\n", evenSum);
    printf("Odd Sum: %d\n", oddSum);
    return 0;
}