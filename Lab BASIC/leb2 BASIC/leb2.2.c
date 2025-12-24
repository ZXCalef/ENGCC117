#include <stdio.h>

int main() {
    int N, i, quantity;
    float unitPrice, itemCost, grandTotal = 0.0;
    
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    
    for (i = 0; i < N; i++) {
        if (scanf("%f %d", &unitPrice, &quantity) != 2) {
            return 1;
        }
        
        itemCost = unitPrice * quantity;
        
        if (unitPrice >= 1000.00) {
            itemCost = itemCost * 0.9;
        }
        
        grandTotal += itemCost;
    }
    
    printf("Grand Total: %.2f\n", grandTotal);
    return 0;
}