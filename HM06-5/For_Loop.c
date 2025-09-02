#include <stdio.h>

int main() {
    int num, i, j, isPrime;

    printf("Enter number: ");
    scanf("%d", &num);

    for (i = num; i >= 2; i--) {
        isPrime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
            }
        }
        if (isPrime) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}