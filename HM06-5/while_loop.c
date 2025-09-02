#include <stdio.h>

int main() {
    int n;

    printf("Enter number : ");
    scanf("%d", &n);

    int i = n;
    while (i >= 2) {
        int j = 2;

        while (j < i && i % j != 0) {
            j++;
        }

        if (j == i) {
            printf("%d ", i);
        }

        i--;
    }

    return 0;
}
