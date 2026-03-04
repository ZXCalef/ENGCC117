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

class LinkedList {
protected:
    struct studentNode *start, **now;

public:
    LinkedList() {
        start = NULL;
        now = &start;
    }

    ~LinkedList() {
        struct studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            free(temp);
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        
        newNode->next = *now;
        *now = newNode;
    }

    void DelNode() {
        if (now == NULL || *now == NULL) return;
        
        struct studentNode *temp = *now;
        *now = (*now)->next;
        free(temp);
    }

    void GoNext() {
        if (now == NULL || *now == NULL) return;
        now = &(*now)->next;
    }

    void GoFirst() {
        now = &start;
    }

    void GoLast() {
        if (start == NULL) {
            now = &start;
            return;
        }
        
        struct studentNode *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        now = &temp->next;
    }

    void ShowAll() {
        struct studentNode *temp = start;
        while (temp != NULL) {
            printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", 
                   temp->name, temp->age, temp->sex, temp->gpa);
            temp = temp->next;
        }
    }

    int FindNode(char n[]) {
        struct studentNode *temp = start;
        int pos = 1;
        
        while (temp != NULL) {
            if (strcmp(temp->name, n) == 0) {
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return 0;
    }

    struct studentNode *NowNode() {
        return *now;
    }

    void EditNode(char n[], int a, char s, float g) {
        if (*now == NULL) return;
        
        strcpy((*now)->name, n);
        (*now)->age = a;
        (*now)->sex = s;
        (*now)->gpa = g;
    }
};

void EditData(LinkedList *ll) {
    char name[20];
    int age;
    char sex;
    float gpa;
    
    printf("Enter new name: ");
    scanf("%s", name);
    printf("Enter new age: ");
    scanf("%d", &age);
    printf("Enter new sex (M/F): ");
    scanf(" %c", &sex);
    printf("Enter new GPA: ");
    scanf("%f", &gpa);
    
    ll->EditNode(name, age, sex, gpa);
}

void AddData(LinkedList *ll) {
    char name[20];
    int age;
    char sex;
    float gpa;
    
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter sex (M/F): ");
    scanf(" %c", &sex);
    printf("Enter GPA: ");
    scanf("%f", &gpa);
    
    ll->InsNode(name, age, sex, gpa);
}

void FindData(LinkedList *ll) {
    char name[20];
    printf("Enter name to find: ");
    scanf("%s", name);
    
    int pos = ll->FindNode(name);
    if (pos > 0) {
        printf("Found %s at position %d\n", name, pos);
        
        // Go to the found node
        ll->GoFirst();
        for (int i = 1; i < pos; i++) {
            ll->GoNext();
        }
        
        struct studentNode *node = ll->NowNode();
        if (node != NULL) {
            printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", 
                   node->name, node->age, node->sex, node->gpa);
        }
    } else {
        printf("Not found\n");
    }
}

void readfile(LinkedList *ll) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No existing data file.\n");
        return;
    }
    
    char name[20];
    int age;
    char sex;
    float gpa;
    
    while (fscanf(fp, "%s %d %c %f", name, &age, &sex, &gpa) == 4) {
        ll->GoLast();  // Go to end to insert in order
        ll->InsNode(name, age, sex, gpa);
    }
    
    fclose(fp);
    printf("Data loaded from file.\n");
    ll->GoFirst();  // Reset to beginning
}

void writefile(LinkedList *ll) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    ll->GoFirst();
    struct studentNode *node = ll->NowNode();
    
    while (node != NULL) {
        fprintf(fp, "%s %d %c %.2f\n", 
                node->name, node->age, node->sex, node->gpa);
        ll->GoNext();
        node = ll->NowNode();
    }
    
    fclose(fp);
    printf("Data saved to file.\n");
}

int main() {
    LinkedList listA;
    int menu;
    
    readfile(&listA);
    
    printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit: ");
    scanf("%d", &menu);
    
    while (menu != 0) {
        switch (menu) {
            case 1: 
                AddData(&listA); 
                break;
            case 2: 
                EditData(&listA); 
                break;
            case 3: 
                listA.DelNode(); 
                break;
            case 4: 
                FindData(&listA); 
                break;
            case 5: 
                listA.ShowAll(); 
                break;
        }
        printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit: ");
        scanf("%d", &menu);
    }
    
    writefile(&listA);
    
    return 0;
}