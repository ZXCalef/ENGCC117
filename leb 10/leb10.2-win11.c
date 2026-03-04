#include <stdio.h>

void TowerHanoi(int n, int from, int to);

int main() {
    int n = 3;
    TowerHanoi(n, 1, 3);
    return 0;
}

void TowerHanoi(int n, int from, int to) {
    if (n == 1) {
        printf("Disc 1 from %d to %d\n", from, to);
        return;
    }
    
    int aux;
    if (from == 1 && to == 2) aux = 3;
    else if (from == 1 && to == 3) aux = 2;
    else if (from == 2 && to == 1) aux = 3;
    else if (from == 2 && to == 3) aux = 1;
    else if (from == 3 && to == 1) aux = 2;
    else if (from == 3 && to == 2) aux = 1;
    
    TowerHanoi(n - 1, from, aux);
    printf("Disc %d from %d to %d\n", n, from, to);
    TowerHanoi(n - 1, aux, to);
}