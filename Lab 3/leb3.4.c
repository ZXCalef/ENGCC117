#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

void GetStudent(struct student child[][10], int *room);

int main() {
    struct student children[20][10];
    int group;
    GetStudent(children, &group);
    return 0;
}

void GetStudent(struct student child[][10], int *room) {
    printf("Enter number of rooms: ");
    scanf("%d", room);
    
    for(int i = 0; i < *room; i++) {
        printf("\nRoom %d (10 students):\n", i+1);
        for(int j = 0; j < 10; j++) {
            printf("Student %d:\n", j+1);
            
            printf("Name: ");
            scanf("%s", child[i][j].name);
            
            printf("Age: ");
            scanf("%d", &child[i][j].age);
            
            printf("Sex (M/F): ");
            scanf(" %c", &child[i][j].sex);
            
            printf("GPA: ");
            scanf("%f", &child[i][j].gpa);
        }
    }
}