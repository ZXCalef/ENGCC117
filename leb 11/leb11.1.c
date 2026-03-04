#include <stdio.h>

int BinSearch(int data[], int n, int find) {
    int low = 0;
    int high = n - 1;
    int mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (data[mid] == find) {
            return mid;  // พบข้อมูล คืนค่าตำแหน่ง
        }
        else if (data[mid] < find) {
            low = mid + 1;  // ค้นหาทางขวา
        }
        else {
            high = mid - 1;  // ค้นหาทางซ้าย
        }
    }
    
    return -1;  // ไม่พบข้อมูล
}

int main() {
    int data[6] = {1, 2, 3, 4, 5, 7};
    int n = 6;  // ต้องกำหนดค่า n ให้ถูกต้อง
    int find = 5;
    
    int pos = BinSearch(data, n, find);
    
    if (pos != -1) {
        printf("Found %d at %d\n", find, pos);
    } else {
        printf("Not found\n");
    }
    
    return 0;
}