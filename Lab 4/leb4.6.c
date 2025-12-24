#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void SaveNode(struct studentNode *child, char n[], int a, char s, float g);
void GoNext2(struct studentNode ***walk);

int main() {
    struct studentNode *start, *now1, **now2;
    
    start = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(start, "one", 6, 'M', 3.11);
    
    start->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    
    start->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next, "three", 10, 'M', 3.33);
    
    start->next->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next->next, "four", 12, 'F', 3.44);
    
    start->next->next->next->next = NULL;
    
    now1 = start;
    now2 = &start;
    
    printf("Before GoNext2: now2 points to address %p\n", (void*)now2);
    printf("(*now2) points to address %p\n", (void*)(*now2));
    printf("(*now2)->name = %s\n\n", (*now2)->name);
    
    GoNext2(&now2);
    
    printf("\nAfter GoNext2: now2 points to address %p\n", (void*)now2);
    printf("(*now2) points to address %p\n", (void*)(*now2));
    printf("%s\n", (*now2)->name);
    
    struct studentNode *temp;
    while(start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }
    
    return 0;
}

void SaveNode(struct studentNode *child, char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
}

void GoNext2(struct studentNode ***walk) {
    if(*walk != NULL && **walk != NULL && (**walk)->next != NULL) {
        printf("In GoNext2: Moving to next node...\n");
        printf("Before: **walk points to address %p (node: %s)\n", 
               (void*)(**walk), (**walk)->name);
        
        *walk = &((**walk)->next);
        
        printf("After: **walk points to address %p (node: %s)\n", 
               (void*)(**walk), (**walk)->name);
        
        printf("\nData in the next node:\n");
        printf("Name: %s\n", (**walk)->name);
        printf("Age: %d\n", (**walk)->age);
        printf("Sex: %c\n", (**walk)->sex);
        printf("GPA: %.2f\n", (**walk)->gpa);
    } else {
        printf("No next node available.\n");
    }
}