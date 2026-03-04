#include <stdio.h>

int BinSearch(int data[], int n, int find);

int main() {
    int data[6] = {1, 2, 3, 4, 5, 7};
    int n = 6, find = 5;
    int pos = BinSearch(data, n, find);
    
    printf("Found %d at position %d\n", find, pos);
    
    return 0;
}

int BinSearch(int data[], int n, int find) {
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        int mid = (left + right) / 2;
        
        if (data[mid] < find)
            left = mid + 1;
        else
            right = mid;
    }
    
    if (data[left] == find)
        return left;
    return -1;
}