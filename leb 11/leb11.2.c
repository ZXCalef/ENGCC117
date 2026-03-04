#include <stdio.h>
#include <stdlib.h>

void merge(int *u, int m, int *v, int n, int *t) {
    int i = 0, j = 0, k = 0;
    
    while (i < m && j < n) {
        if (u[i] <= v[j]) {
            t[k++] = u[i++];
        } else {
            t[k++] = v[j++];
        }
    }
    
    while (i < m) {
        t[k++] = u[i++];
    }
    
    while (j < n) {
        t[k++] = v[j++];
    }
}

void mergesort(int t[], int k) {
    if (k <= 1) return;
    
    int mid = k / 2;
    int *u = (int *)malloc(mid * sizeof(int));
    int *v = (int *)malloc((k - mid) * sizeof(int));
    
    for (int i = 0; i < mid; i++) {
        u[i] = t[i];
    }
    for (int i = mid; i < k; i++) {
        v[i - mid] = t[i];
    }
    
    mergesort(u, mid);
    mergesort(v, k - mid);
    
    merge(u, mid, v, k - mid, t);
    
    free(u);
    free(v);
}

int main() {
    int data[7] = {4, 6, 1, 2, 5, 1, 8};
    int n = 7;
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    mergesort(data, n);
    
    printf("Sorted array:   ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}