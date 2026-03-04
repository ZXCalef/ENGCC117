#include <stdio.h>
#include <stdlib.h>

int* GetMatrix(int *row, int *col);

int main() {
    int *data, m, n;
    data = GetMatrix(&m, &n);
    
    // Display matrix
    printf("\nMatrix (%d x %d):\n", m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", data[i * n + j]);
        }
        printf("\n");
    }
    
    free(data); // Free memory
    return 0;
}

int* GetMatrix(int *row, int *col) {
    printf("Enter number of rows: ");
    scanf("%d", row);
    
    printf("Enter number of columns: ");
    scanf("%d", col);
    
    int *matrix = (int*)malloc((*row) * (*col) * sizeof(int));
    
    if(matrix == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    printf("Enter %d elements:\n", (*row) * (*col));
    for(int i = 0; i < (*row) * (*col); i++) {
        printf("Element %d: ", i);
        scanf("%d", &matrix[i]);
    }
    
    return matrix;
}