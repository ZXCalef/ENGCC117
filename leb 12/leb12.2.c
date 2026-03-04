#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int weight;
    int value;
    float ratio;
} Item;

int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    int *x = (int *)calloc(n, sizeof(int));
    
    Item *items = (Item *)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        items[i].index = i;
        items[i].weight = w[i];
        items[i].value = v[i];
        items[i].ratio = (float)v[i] / w[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    
    int remainingWeight = wx;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingWeight) {
            x[items[i].index] = 1;
            remainingWeight -= items[i].weight;
        }
    }
    
    free(items);
    return x;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    
    int *x = KnapsackGreedy(w, v, n, wx);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    
    free(x);
    
    return 0;
}