#include <stdio.h>

int maxValue = 0;
int bestX[100];

void KnapsackBT(int *w, int *v, int n, int wx, int i, int *x, int currentWeight, int currentValue) {
    if (i == n) {
        if (currentValue > maxValue) {
            maxValue = currentValue;
            for (int j = 0; j < n; j++) {
                bestX[j] = x[j];
            }
        }
        return;
    }
    
    x[i] = 0;
    KnapsackBT(w, v, n, wx, i + 1, x, currentWeight, currentValue);
    
    if (currentWeight + w[i] <= wx) {
        x[i] = 1;
        KnapsackBT(w, v, n, wx, i + 1, x, currentWeight + w[i], currentValue + v[i]);
    }
}

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    maxValue = 0;
    int tempX[100] = {0};
    KnapsackBT(w, v, n, wx, i, tempX, 0, 0);
    
    for (int j = 0; j < n; j++) {
        x[j] = bestX[j];
    }
    
    return maxValue;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x, vx;
    
    x = new int[n];
    vx = KnapsackBT(w, v, n, wx, 0, x);
    
    printf("Value = %d\n", vx);
    for (int i = 0; i < n; i++) 
        printf("%d ", x[i]);
    
    return 0;
}