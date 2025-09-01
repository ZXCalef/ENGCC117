#include <stdio.h>

int main() {
    int n;
    printf("Enter number : ");
    scanf("%d", &n);

    // loop จาก n ลงไปถึง 2
    for (int i = n; i >= 2; i--) {
        int isPrime = 1; 

        // ตรวจสอบว่ามีตัวหารอื่นนอกจาก 1 และตัวเองหรือไม่
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0; 
                break;      
            }
        }

        if (isPrime) {
            printf("%d ", i);
        }
    }

    return 0;
}
