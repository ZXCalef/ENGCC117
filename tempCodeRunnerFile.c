#include <stdio.h>

int main() {
    char empID[11]; // 10 characters + null terminator
    float hoursWorked, payRate, totalIncome;

    // รับข้อมูล
    printf("Input the Employees ID(Max. 10 chars): \n");
    scanf("%s", empID);

    printf("Input the working hrs: \n");
    scanf("%f", &hoursWorked);

    printf("Salary amount/hr: \n");
    scanf("%f", &payRate);

    // คำนวณรายได้
    totalIncome = hoursWorked * payRate;

    // แสดงผล
    printf("\nEmployee ID: %s\n", empID);
    printf("Total Salary: %.2f Baht\n", totalIncome);

    return 0;
}
