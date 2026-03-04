#include <stdio.h>
#include <stdlib.h>

void merge(int *u, int m, int *v, int n, int *t) {
    int i = 0, j = 0, k = 0;
    
    // เปรียบเทียบและรวมข้อมูลจาก u และ v ไปยัง t
    while (i < m && j < n) {
        if (u[i] <= v[j]) {
            t[k++] = u[i++];
        } else {
            t[k++] = v[j++];
        }
    }
    
    // คัดลอกข้อมูลที่เหลือจาก u (ถ้ามี)
    while (i < m) {
        t[k++] = u[i++];
    }
    
    // คัดลอกข้อมูลที่เหลือจาก v (ถ้ามี)
    while (j < n) {
        t[k++] = v[j++];
    }
}

void mergesort(int t[], int k) {
    if (k <= 1) return;  // กรณีฐาน: มีข้อมูล 1 ตัวหรือน้อยกว่า ไม่ต้อง sort
    
    int mid = k / 2;
    int *u = (int *)malloc(mid * sizeof(int));
    int *v = (int *)malloc((k - mid) * sizeof(int));
    
    // แบ่งข้อมูลออกเป็น 2 ส่วน
    for (int i = 0; i < mid; i++) {
        u[i] = t[i];
    }
    for (int i = mid; i < k; i++) {
        v[i - mid] = t[i];
    }
    
    // เรียกตัวเองเพื่อ sort ครึ่งซ้ายและครึ่งขวา
    mergesort(u, mid);
    mergesort(v, k - mid);
    
    // รวมสองส่วนที่ sort แล้วกลับเข้า t
    merge(u, mid, v, k - mid, t);
    
    free(u);
    free(v);
}

int main() {
    int data[7] = {4, 6, 1, 2, 5, 1, 8};
    int n = 7;
    
    mergesort(data, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}