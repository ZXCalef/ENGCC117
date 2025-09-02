#include <stdio.h>

int main() {
    int n;
    printf("Enter number : ");
    scanf("%d", &n);

    int i = n;
    do {
        int isPrime = 1;
        int j = 2; 

        do {
            if (i % j == 0 && j != i) {
                isPrime = 0;
                break;
            }
            j++;
        } while (j < i);

        if (isPrime && i >= 2) {
            printf("%d ", i);
        }

        i--;
    } while (i >= 2);

    return 0;
}
