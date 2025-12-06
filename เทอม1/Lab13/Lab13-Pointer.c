#include <stdio.h>

void swapNumbers(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main() {
    int num1, num2;
    int *ptr1, *ptr2;

    printf("Enter num1 : ");
    scanf("%d", &num1);
    printf("Enter num2 : ");
    scanf("%d", &num2);

    ptr1 = &num1;
    ptr2 = &num2;

    printf("Before swap (num1 & num2) : %d, %d\n", num1, num2);

    swapNumbers(ptr1, ptr2);

    printf("After swap (num1 & num2) : %d, %d\n", num1, num2);

    return 0;
}
