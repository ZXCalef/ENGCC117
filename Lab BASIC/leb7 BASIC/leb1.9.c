#include <stdio.h>

int main() {
    int zoneCode;
    float weight_kg;
    float totalCost = 0.0;
    
    if (scanf("%d %f", &zoneCode, &weight_kg) != 2) {
        return 1;
    }
    
    switch (zoneCode) {
        case 1:
            if (weight_kg <= 5.0) {
                totalCost = 50.0;
            } else {
                totalCost = 80.0;
            }
            printf("%.2f\n", totalCost);
            break;
            
        case 2:
            if (weight_kg <= 10.0) {
                totalCost = 150.0;
            } else {
                totalCost = 250.0;
            }
            printf("%.2f\n", totalCost);
            break;
            
        case 3:
            totalCost = 500.0;
            printf("%.2f\n", totalCost);
            break;
            
        default:
            printf("Invalid Zone Code\n");
            break;
    }
    
    return 0;
}