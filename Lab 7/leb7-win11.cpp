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
    struct studentNode *start, *now;
public:
    LinkedList() {
        start = NULL;
        now = NULL;
    }
    ~LinkedList() {
        struct studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            delete temp;
        }
    }
    void InsNode(char n[], int a, char s, float g) {
        struct studentNode *newNode = new studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = NULL;
        
        if (start == NULL) {
            start = newNode;
            now = start;
        } else {
            struct studentNode *temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void DelNode() {
        if (now == NULL) return;
        
        if (now == start) {
            start = now->next;
            delete now;
            now = start;
            return;
        }
        
        struct studentNode *prev = start;
        while (prev != NULL && prev->next != now) {
            prev = prev->next;
        }
        
        if (prev != NULL) {
            prev->next = now->next;
            delete now;
            now = prev->next;
        }
    }
    void GoNext() {
        if (now != NULL && now->next != NULL) {
            now = now->next;
        }
    }
    void GoBack() {
        if (now == NULL || now == start) return;
        
        struct studentNode *prev = start;
        while (prev != NULL && prev->next != now) {
            prev = prev->next;
        }
        
        if (prev != NULL) {
            now = prev;
        }
    }
    virtual void ShowNode() {
        if (now != NULL) {
            printf("%s %d %c %.2f\n", now->name, now->age, now->sex, now->gpa);
        }
    }
};

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = start;
    }
    void InsertNode(char n[], int a, char s, float g) {
        struct studentNode *newNode = new studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        
        if (start == NULL) {
            start = newNode;
            now = start;
            newNode->next = NULL;
            return;
        }
        
        if (now == NULL) {
            now = start;
        }
        
        if (now == start) {
            newNode->next = start;
            start = newNode;
            now = start;
        } else {
            struct studentNode *prev = start;
            while (prev != NULL && prev->next != now) {
                prev = prev->next;
            }
            if (prev != NULL) {
                prev->next = newNode;
                newNode->next = now;
            }
        }
    }
    virtual void ShowNode() {
        struct studentNode *temp = start;
        while (temp != NULL) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
};

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;
    
    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();  
    listA.ShowNode(); 
    
    listB.InsertNode("four", 4, 'D', 4.4);
    listB.InsertNode("five", 5, 'E', 5.5);
    listB.InsertNode("six", 6, 'F', 6.6);
    listB.GoNext();  
    listB.DelNode(); 
    listB.GoFirst(); 
    listB.ShowNode(); 
    
    listC = &listA;
    listC->GoBack();  
    listC->ShowNode(); 
    
    listC = &listB;
    listC->ShowNode(); 
    
    return 0;
}