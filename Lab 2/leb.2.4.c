#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void explode(char *str1, char *splitter, char str2[][100], int *count);

int main() {
    printf("==============================\n");
    printf("  ตัวอย่างการใช้งานฟังก์ชัน explode()\n");
    printf("==============================\n\n");
    
    printf("ตัวอย่างที่ 1:\n");
    printf("-------------\n");
    char str1[] = "I/Love/You";
    char splitter1[] = "/";
    char str2[10][100];  // เก็บข้อความที่แยกได้
    int count1;
    
    // เรียกใช้ฟังก์ชัน explode
    explode(str1, splitter1, str2, &count1);
    
    printf("สตริงต้นฉบับ: \"%s\"\n", str1);
    printf("ตัวแบ่ง: \"%s\"\n", splitter1);
    printf("ผลลัพธ์ที่ได้:\n");
    
    for (int i = 0; i < count1; i++) {
        printf("  str2[%d] = \"%s\"\n", i, str2[i]);
    }
    printf("จำนวนข้อความทั้งหมด: %d\n\n", count1);
    
    // ตัวอย่างที่ 2
    printf("ตัวอย่างที่ 2:\n");
    printf("-------------\n");
    char str3[] = "สวัสดี,ชาวโลก,ภาษาC,การเขียนโปรแกรม";
    char splitter2[] = ",";
    char str4[10][100];
    int count2;
    
    explode(str3, splitter2, str4, &count2);
    
    printf("สตริงต้นฉบับ: \"%s\"\n", str3);
    printf("ตัวแบ่ง: \"%s\"\n", splitter2);
    printf("ผลลัพธ์ที่ได้:\n");
    
    for (int i = 0; i < count2; i++) {
        printf("  str4[%d] = \"%s\"\n", i, str4[i]);
    }
    printf("จำนวนข้อความทั้งหมด: %d\n\n", count2);
    
    // ตัวอย่างที่ 3
    printf("ตัวอย่างที่ 3:\n");
    printf("-------------\n");
    char str5[] = "apple::banana::cherry::date";
    char splitter3[] = "::";
    char str6[10][100];
    int count3;
    
    explode(str5, splitter3, str6, &count3);
    
    printf("สตริงต้นฉบับ: \"%s\"\n", str5);
    printf("ตัวแบ่ง: \"%s\"\n", splitter3);
    printf("ผลลัพธ์ที่ได้:\n");
    
    for (int i = 0; i < count3; i++) {
        printf("  str6[%d] = \"%s\"\n", i, str6[i]);
    }
    printf("จำนวนข้อความทั้งหมด: %d\n", count3);
    
    printf("\n==============================\n");
    printf("  สิ้นสุดการทดสอบฟังก์ชัน explode()\n");
    printf("==============================\n");
    
    return 0;
}

void explode(char *str1, char *splitter, char str2[][100], int *count) {
    *count = 0;      // เริ่มต้นนับจำนวนข้อความ
    int pos = 0;     // ตำแหน่งในข้อความปัจจุบัน
    int len = strlen(str1);
    int split_len = strlen(splitter);
    
    // กรณีสตริงว่างเปล่า
    if (len == 0) {
        str2[0][0] = '\0';
        *count = 1;
        return;
    }
    
    // วนลูปผ่านทุกตัวอักษรในสตริง
    for (int i = 0; i <= len; i++) {
        int is_splitter = 0;
        
        // ตรวจสอบว่าตำแหน่งปัจจุบันตรงกับตัวแบ่งหรือไม่
        if (i <= len - split_len) {
            is_splitter = 1;
            for (int j = 0; j < split_len; j++) {
                if (str1[i + j] != splitter[j]) {
                    is_splitter = 0;
                    break;
                }
            }
        }
        
        // ถ้าพบตัวแบ่งหรือสิ้นสุดสตริง
        if (is_splitter || str1[i] == '\0') {
            // เพิ่มเครื่องหมายจบสตริง
            str2[*count][pos] = '\0';
            
            // เพิ่มจำนวนนับถ้าข้อความไม่ว่างหรือนี่เป็นข้อความแรก
            if (pos > 0 || *count == 0) {
                (*count)++;
            }
            
            // รีเซ็ตตำแหน่งสำหรับข้อความใหม่
            pos = 0;
            
            // ข้ามตัวแบ่ง
            if (is_splitter) {
                i += split_len - 1;  // ลด 1 เพราะ for loop จะเพิ่ม i อีก 1
            }
        } else {
            // คัดลอกตัวอักษรไปยังอาร์เรย์ผลลัพธ์
            str2[*count][pos] = str1[i];
            pos++;
        }
    }
    
    // ลด count ลง 1 ถ้าเพิ่มเกินมาในลูป
    if (*count > 0 && str2[*count - 1][0] == '\0') {
        (*count)--;
    }
}