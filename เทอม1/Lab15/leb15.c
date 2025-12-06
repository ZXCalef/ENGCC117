#include <stdio.h>
#include <ctype.h>  // สำหรับ isspace() และ ispunct()

// ฟังก์ชันตรวจสอบว่าตัวอักษรเป็นตัวแบ่งคำหรือไม่
int isSeparator(char c) {
    return isspace(c) || ispunct(c);
}

// ฟังก์ชันนับจำนวนคำในไฟล์
int countWordsInFile(char filename[]) {
    FILE *fp;
    char c;
    int inWord = 0, count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (isSeparator(c)) {
            if (inWord) {
                count++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    if (inWord) count++; // กรณีคำสุดท้ายไม่มีตัวแบ่ง

    fclose(fp);
    return count;
}

int main() {
    char name[50];
    printf("Enter file name: ");
    scanf("%s", name);

    int total = countWordsInFile(name);
    if (total != -1)
        printf("Total number of words in '%s' : %d words\n", name, total);

    return 0;
}
