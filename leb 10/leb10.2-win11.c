#include <stdio.h>

void TowerHanoi(int m, int i, int j) {
    if (m == 1) {
        printf("Disc %d from %d to %d\n", m, i, j);
    } else {
        int k = 6 - i - j;
        TowerHanoi(m - 1, i, k);
        printf("Disc %d from %d to %d\n", m, i, j);
        TowerHanoi(m - 1, k, j);
    }
}

int main() {
    TowerHanoi(3, 1, 3);
    return 0;
}