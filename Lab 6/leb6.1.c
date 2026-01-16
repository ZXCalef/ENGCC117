#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);

struct studentNode *AddNode(struct studentNode **start, char name[], int age, char sex, float gpa) {
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = NULL;
    
    if (*start == NULL) {
        *start = newNode;
    } else {
        struct studentNode *temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->back = temp;
    }
    return newNode;
}

void InsNode(struct studentNode *now, char name[], int age, char sex, float gpa) {
    if (now == NULL) return;
    
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    
    newNode->next = now;
    newNode->back = now->back;
    
    if (now->back != NULL) {
        now->back->next = newNode;
    }
    now->back = newNode;
}

void GoBack(struct studentNode **now) {
    if (*now != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}

void DelNode(struct studentNode *now) {
    if (now == NULL) return;
    
    if (now->back != NULL) {
        now->back->next = now->next;
    }
    
    if (now->next != NULL) {
        now->next->back = now->back;
        struct studentNode *temp = now;
        now = now->next;
        free(temp);
    } else if (now->back != NULL) {
        struct studentNode *temp = now;
        now = now->back;
        free(temp);
    } else {
        free(now);
        now = NULL;
    }
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

int main() {
    struct studentNode *start, *now;
    start = NULL;
    
    now = AddNode(&start, "one", 6, 'M', 3.11); ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22); ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33); ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44); ShowAll(start);
    
    GoBack(&now);
    DelNode(now); ShowAll(start);
    DelNode(now); ShowAll(start);
    DelNode(now); ShowAll(start);
    
    return 0;
}