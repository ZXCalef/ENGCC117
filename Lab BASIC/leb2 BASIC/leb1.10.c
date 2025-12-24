#include <stdio.h>

int main() {
    int clearanceLevel, age, isActive;
    
    if (scanf("%d %d %d", &clearanceLevel, &age, &isActive) != 3) {
        return 1;
    }
    
    if (isActive == 1 && 
        (clearanceLevel == 3 || (clearanceLevel == 2 && age >= 25))) {
        printf("Access Granted");
    } 
    else {
        printf("Access Denied");
    }
    
    return 0;
}