#include <stdio.h>

int main() {
    float base, height, area;

    // รับค่าฐานและสูงจากผู้ใช้
    printf("Enter the base of the triangle: ");
    scanf("%f", &base);

    printf("Enter the height of the triangle: ");
    scanf("%f", &height);

    // คำนวณพื้นที่
    area = (base * height) / 2;

    // แสดงผล
    printf("The area of the triangle is: %.2f\n", area);

    return 0;
}
