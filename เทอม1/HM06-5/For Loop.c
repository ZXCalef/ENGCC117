#include <stdio.h>

int main() {
    int n;
    printf("Enter number : ");
    scanf("%d", &n);

    for (int i = n; i >= 2; i--) {
        int j;
        for (j = 2; j < i && i % j != 0; j++) {
        }

        if (j == i) {
            printf("%d ", i);
        }
    }

    return 0;
}
