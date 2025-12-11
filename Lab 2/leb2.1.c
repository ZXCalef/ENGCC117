#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[]);

int main() {
    char text[50];
    char out[50];
    
    // รับข้อมูลจากผู้ใช้
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    
    // ลบ newline (\n) ที่ติดมาจาก fgets
    text[strcspn(text, "\n")] = '\0';
    
    // เรียกใช้ฟังก์ชัน reverse
    reverse(text, out);
    
    // แสดงผลลัพธ์
    printf("\nInput: %s\n", text);
    printf("Output: %s\n", out);
    
    return 0;
}

void reverse(char str1[], char str2[]) {
    int len = strlen(str1);
    int i;
    
    for (i = 0; i < len; i++) {
        str2[i] = str1[len - 1 - i];
    }
    
    str2[i] = '\0';
}