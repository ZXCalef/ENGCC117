#include <stdio.h>

int main() {
    int score;

    if (scanf("%d", &score) != 1) {
        return 1;
    }

    if (score >= 80) {
        printf("Grade A");
    } else if (score >= 70 && score <= 79) {
        printf("Grade B");
    } else if (score >= 60 && score <= 69) {
        printf("Grade C");
    } else if (score >= 50 && score <= 59) {
        printf("Grade D");
    } else {
        printf("Grade F");
    }

    return 0;
}