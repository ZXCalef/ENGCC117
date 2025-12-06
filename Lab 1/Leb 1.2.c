#include <stdio.h>

void GetSet(int *[], int *);

int main() {
    int temp[100];
    int *data = temp;
    int num;
    
    GetSet(&data, &num);
    
    printf("\n=== OUTPUT ===\n");
    printf("Number of elements in set: %d\n", num);
    printf("Elements: { ");
    for (int i = 0; i < num; i++) {
        printf("%d", data[i]);
        if (i < num - 1) printf(", ");
    }
    printf(" }\n");
    
    return 0;
}

void GetSet(int *set[], int *num) {
    printf("Enter number of elements in set: ");
    scanf("%d", num);
    
    printf("\n");
    for (int i = 0; i < *num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", (*set) + i);
    }
}