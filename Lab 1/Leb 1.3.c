#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *num) {
    printf("Enter number of members: ");
    scanf("%d", num);
    
    int *set = (int*)malloc(*num * sizeof(int));
    
    printf("Enter %d values:\n", *num);
    for(int i = 0; i < *num; i++) {
        scanf("%d", &set[i]);
    }
    
    return set;
}

int main() {
    int *data, num;
    data = GetSet(&num);
    
    printf("\n--- Result ---\n");
    printf("Number of members: %d\n", num);
    printf("Set values: ");
    for(int i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    free(data);
    return 0;
}