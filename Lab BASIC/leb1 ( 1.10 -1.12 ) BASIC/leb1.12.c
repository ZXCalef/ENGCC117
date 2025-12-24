#include <stdio.h>

int main() {
    int planCode;
    float dataUsage_GB;
    float totalBill = 0.0;
    
    if (scanf("%d %f", &planCode, &dataUsage_GB) != 2) {
        return 1;
    }
    
    if (planCode == 1) {
        if (dataUsage_GB <= 10.0) {
            totalBill = 299.0;
        } else {
            totalBill = 299.0 + 10.0 * (dataUsage_GB - 10.0);
        }
        printf("%.2f\n", totalBill);
    } 
    else if (planCode == 2) {
        if (dataUsage_GB <= 20.0) {
            totalBill = 599.0;
        } else {
            totalBill = 599.0 + 50.0 + 5.0 * (dataUsage_GB - 20.0);
        }
        printf("%.2f\n", totalBill);
    }
    else {
        printf("Invalid Plan Code\n");
    }
    
    return 0;
}