#include <stdio.h>

int main() {
    int days;
    int seconds;

    printf("Input Days : ");
    scanf("%d", &days);

    seconds = days * 24 * 60 * 60;

    printf("%d days = %d seconds\n", days, seconds);

    return 0;
}
