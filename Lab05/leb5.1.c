#include <stdio.h>

int main() {
    char empID[11];      
    int hours;           
    double rate;
    double salary;       

    printf("Input the Employees ID(Max. 10 chars): ");
    scanf("%10s", empID);

    printf("Input the working hrs: ");
    scanf("%d", &hours);

    printf("Salary amount/hr: ");
    scanf("%lf", &rate);

    salary = hours * rate;

    printf("Employees ID = %s\n", empID);
    printf("Salary = U$ %.2f\n", salary);

    return 0;
}
