#include <stdio.h>

void TowerHanoi(int m, int i, int j) {
    if (m == 1) {
        printf("Disc %d from %d to %d\n", m, i, j);
    } else {
        int k = 6 - i - j;  // หาเสากลาง (1+2+3 = 6)
        TowerHanoi(m - 1, i, k);  // ย้าย m-1 แผ่นจาก i ไป k
        printf("Disc %d from %d to %d\n", m, i, j);  // ย้ายแผ่นล่างสุด
        TowerHanoi(m - 1, k, j);  // ย้าย m-1 แผ่นจาก k ไป j
    }
}

int main() {
    TowerHanoi(3, 1, 3);
    return 0;
}