#include <stdio.h>

int main() {
    int a, b, c, sum;

    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    sum = a + b + c;

    printf("Answer = %d\n", sum);

    return 0;
}
