#include <stdio.h>

int main() {
    int num;
    printf("User Input : ");
    scanf("%d", &num);

    // ตรวจสอบและแสดงผลเป็นคำ
    switch (num) {
        case 0:  printf("Result : zero\n"); break;
        case 1:  printf("Result : one\n"); break;
        case 2:  printf("Result : two\n"); break;
        case 3:  printf("Result : three\n"); break;
        case 4:  printf("Result : four\n"); break;
        case 5:  printf("Result : five\n"); break;
        case 6:  printf("Result : six\n"); break;
        case 7:  printf("Result : seven\n"); break;
        case 8:  printf("Result : eight\n"); break;
        case 9:  printf("Result : nine\n"); break;
        case 10: printf("Result : ten\n"); break;
        case 11: printf("Result : eleven\n"); break;
        case 12: printf("Result : twelve\n"); break;
        case 13: printf("Result : thirteen\n"); break;
        case 14: printf("Result : fourteen\n"); break;
        case 15: printf("Result : fifteen\n"); break;
        case 16: printf("Result : sixteen\n"); break;
        case 17: printf("Result : seventeen\n"); break;
        case 18: printf("Result : eighteen\n"); break;
        case 19: printf("Result : nineteen\n"); break;
        case 20: printf("Result : twenty\n"); break;
        default:
            printf("Result : (out of range)\n");
    }

    return 0;
}
