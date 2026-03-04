#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[]);

int main() {
    char text[50];
    char out[50];
    
    printf("Enter string: ");
    fgets(text, 50, stdin);
    
    int len = strlen(text);
    if (len > 0 && text[len-1] == '\n') {
        text[len-1] = '\0';
    }
    
    reverse(text, out);
    printf("Original: %s\n", text);
    printf("Reversed: %s\n", out);
    
    return 0;
}

void reverse(char str1[], char str2[]) {
    int length = strlen(str1);
    int i;
    
    for (i = 0; i < length; i++) {
        str2[i] = str1[length - 1 - i];
    }
    
    str2[length] = '\0';
}