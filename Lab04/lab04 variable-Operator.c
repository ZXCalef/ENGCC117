#include <stdio.h>

int main() {
    int id;
    float hoursWorked, payPerHour, totalIncome;

    printf("Enter employee ID: ");
    scanf("%d", &id);

    printf("Enter hours worked: ");
    scanf("%f", &hoursWorked);

    printf("Enter hourly wage (U$): ");
    scanf("%f", &payPerHour);

    totalIncome = hoursWorked * payPerHour;

    printf("Employees ID = %04d\n", id);
    printf("Salary = U$ %.2f\n", totalIncome);

    return 0;
}
