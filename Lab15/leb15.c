#include <stdio.h>
#include <ctype.h>

int countWords(char f[]) {
    FILE *fp = fopen(f, "r");
    if (!fp) return printf("ไม่พบไฟล์ %s\n", f), -1;
    int c, w = 0, in = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c) || ispunct(c)) in = 0;
        else if (!in) w++, in = 1;
    }
    fclose(fp);
    return w;
}

int main() {
    char name[50];
    printf("Enter file name:\n");
    scanf("%s", name);
    int t = countWords(name);
    if (t >= 0) printf("Total number of words in '%s' : %d words\n", name, t);
}
