#include <stdio.h>

int main() {
    float H, W, Area;

    // รับค่าจากผู้ใช้
    printf("Enter height (H): ");
    scanf("%f", &H);

    printf("Enter base (W): ");
    scanf("%f", &W);

    // คำนวณพื้นที่สามเหลี่ยม
    Area = (H * W) / 2;

    // แสดงผล
    printf("Area = %.1f\n", Area);

    return 0;
}
