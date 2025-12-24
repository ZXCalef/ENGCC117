#include <stdio.h>

int main() {
    int termCode;
    float investmentAmount;
    float aprRate = 0.0;
    float totalInterest = 0.0;
    
    if (scanf("%d %f", &termCode, &investmentAmount) != 2) {
        return 1;
    }
    
    switch (termCode) {
        case 1:
            if (investmentAmount < 5000.0) {
                aprRate = 0.03;
            } else {
                aprRate = 0.04;
            }
            totalInterest = investmentAmount * aprRate;
            printf("%.2f\n", totalInterest);
            break;
            
        case 2:
            if (investmentAmount < 10000.0) {
                aprRate = 0.05;
            } else {
                aprRate = 0.065;
            }
            totalInterest = investmentAmount * aprRate;
            printf("%.2f\n", totalInterest);
            break;
            
        case 3:
            aprRate = 0.08;
            totalInterest = investmentAmount * aprRate;
            printf("%.2f\n", totalInterest);
            break;
            
        default:
            printf("Invalid Term Code\n");
            break;
    }
    
    return 0;
}