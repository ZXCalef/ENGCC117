#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_WORDS 50

void explode(char str1[], char splitter, char str2[][MAX_LEN], int *count) {
    *count = 0;
    int word_index = 0;
    int len = strlen(str1);
    
    for (int i = 0; i <= len; i++) {
        if (str1[i] == splitter || str1[i] == '\0') {
            str2[*count][word_index] = '\0';
            (*count)++;
            word_index = 0;
        } else {
            str2[*count][word_index] = str1[i];
            word_index++;
        }
    }
}

int main() {
    char str1[] = "I/Love/You";
    char splitter = '/';
    char str2[MAX_WORDS][MAX_LEN];
    int count;
    
    explode(str1, splitter, str2, &count);
    
    printf("count = %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("str2[%d] = \"%s\"\n", i, str2[i]);
    }
    
    return 0;
}