#include <stdio.h>
#include <string.h>

char* reverse(char str1[]);

int main() {
    char text[50] = "I Love You";
    char *out;
    
    printf("Input: %s\n", text);
    out = reverse(text);
    printf("Output: %s\n", out);
    
    char text2[50] = "Hello World";
    printf("\nInput: %s\n", text2);
    out = reverse(text2);
    printf("Output: %s\n", out);
    
    return 0;
}

char* reverse(char str1[]) {
    static char str2[50]; 
    int len = strlen(str1);
    
    for(int i = 0; i < len; i++) {
        str2[i] = str1[len - 1 - i];
    }
    str2[len] = '\0';
    
    return str2;
}