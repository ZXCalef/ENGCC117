#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

struct student (*GetStudent(int *room))[10];

int main() {
    struct student (*children)[10];
    int group;
    children = GetStudent(&group);
    return 0;
}

struct student (*GetStudent(int *room))[10] {
    printf("Enter number of rooms: ");
    scanf("%d", room);
    
    struct student (*children)[10] = malloc(sizeof(struct student[(*room)][10]));
    
    if (children == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    for (int i = 0; i < *room; i++) {
        printf("\nRoom %d (10 students):\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d:\n", j + 1);
            
            printf("  Name: ");
            scanf("%s", children[i][j].name);
            
            printf("  Age: ");
            scanf("%d", &children[i][j].age);
            
            printf("  Sex (M/F): ");
            scanf(" %c", &children[i][j].sex);
            
            printf("  GPA: ");
            scanf("%f", &children[i][j].gpa);
        }
    }
    
    return children;
}