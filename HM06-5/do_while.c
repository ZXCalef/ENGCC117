#include <stdio.h>#include <stdio.h>

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int i = n;
    do {
        int j = 2;

        do {
            j++;
        } while (j < i && i % (j - 1) != 0);

        if (j == i) {
            printf("%d ", i);
        }

        i--;
    } while (i >= 2);

    printf("\n");
    return 0;
}
