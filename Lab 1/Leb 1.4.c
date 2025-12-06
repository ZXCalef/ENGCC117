#include <stdio.h>
#include <stdlib.h>

int GetSet(int **arr);  // แก้ prototype ให้ถูกต้อง

int GetSet(int **arr) {
    int n;
    
    printf("Enter number of members: ");
    scanf("%d", &n);
    
    *arr = (int*)malloc(n * sizeof(int));
    
    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }
    
    printf("Enter %d members:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Member %d: ", i + 1);
        scanf("%d", &((*arr)[i]));
    }
    
    return n;
}

int main() {
    int *data, num;
    num = GetSet(&data);  // ส่ง address ของ pointer
    
    printf("\nYou entered %d members:\n", num);
    for (int i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    free(data);
    
    return 0;
}