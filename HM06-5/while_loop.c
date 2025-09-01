#include <stdio.h>

int main() {
    int n;

    printf("Enter number : ");
    scanf("%d", &n);

    int i = n;
    while (i >= 2) {
        int isPrime = 1;
        int j = 2;

        while (j < i) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
            j++;
        }

        if (isPrime) {
            printf("%d ", i);
        }

        i--;
    }

    return 0;
}
