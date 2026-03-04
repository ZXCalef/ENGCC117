#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int **value, int *row, int *col);

int main() {
    int *data, m, n;
    
    GetMatrix(&data, &m, &n);
    
    printf("\nMatrix %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", data[i * n + j]);
        }
        printf("\n");
    }
    
    free(data);
    
    return 0;
}

void GetMatrix(int **value, int *row, int *col) {
    printf("Enter number of rows: ");
    scanf("%d", row);
    
    printf("Enter number of columns: ");
    scanf("%d", col);
    
    *value = (int*)malloc((*row) * (*col) * sizeof(int));
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &((*value)[i * (*col) + j]));
        }
    }
}