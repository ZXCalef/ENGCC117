#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i = 0;
    int j = 0;
    int word = 0;
    
    *count = 0;
    
    while (str1[i] != '\0') {
        if (str1[i] == splitter || str1[i] == '\0') {
            str2[word][j] = '\0';
            
            if (j > 0) {
                word++;
            }
            
            j = 0;
        } 
        else {
            str2[word][j] = str1[i];
            j++;
            
            if (j >= 9) {
                str2[word][9] = '\0';
                j = 9;
            }
        }
        i++;
    }
    
    if (j > 0) {
        str2[word][j] = '\0';
        word++;
    }
    
    *count = word;
}

int main() {
    char out[20][10];
    int num;
    
    explode("I/Love/You", '/', out, &num);
    
    printf("count = %d\n", num);
    for (int i = 0; i < num; i++) {
        printf("out[%d] = \"%s\"\n", i, out[i]);
    }
    
    return 0;
}