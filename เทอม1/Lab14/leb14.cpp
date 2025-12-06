#include <stdio.h>

int main() {
    int a[100], n = 0, min, max;

    printf("Enter value:\n");
    while (scanf("%d", &a[n]) == 1) {
        n++;
        if (getchar() == '\n') break;
    }

    min = max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }

    printf("Index: ");
    for (int i = 0; i < n; i++) printf("%d ", i);

    printf("\nArray: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    printf("\n\nMin : %d\nMax : %d", min, max);
}
