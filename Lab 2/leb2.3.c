#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    char out[20][10];
    int num;
    
    // ตัวอย่าง 1
    printf("=== Example 1 ===\n");
    explode("I/Love/You", '/', out, &num);
    printf("String: \"I/Love/You\"\n");
    printf("Splitter: '/'\n");
    printf("count = %d\n", num);
    for (int i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    printf("\n");
    
    // ตัวอย่าง 2
    printf("=== Example 2 ===\n");
    explode("apple,banana,orange,grape", ',', out, &num);
    printf("String: \"apple,banana,orange,grape\"\n");
    printf("Splitter: ','\n");
    printf("count = %d\n", num);
    for (int i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    printf("\n");
    
    // ตัวอย่าง 3
    printf("=== Example 3 ===\n");
    explode("Hello World C Programming", ' ', out, &num);
    printf("String: \"Hello World C Programming\"\n");
    printf("Splitter: ' '\n");
    printf("count = %d\n", num);
    for (int i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    
    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i = 0;
    int j = 0;
    int k = 0;
    int len = strlen(str1);
    
    *count = 0;
    
    for (i = 0; i <= len; i++) {
        if (str1[i] == splitter || str1[i] == '\0') {
            str2[j][k] = '\0';
            if (k > 0) {
                (*count)++;
                j++;
                k = 0;
            }
        } else {
            str2[j][k] = str1[i];
            k++;
            if (k >= 9) {
                str2[j][9] = '\0';
                k = 0;
                j++;
                (*count)++;
            }
        }
    }
}