#include <stdio.h>
#include <string.h>

typedef struct { int id; char title[100], author[100]; int year; } Book;
#define MAX 100

void addBook(Book b[], int *c) {
    printf("Enter Book ID: "); scanf("%d", &b[*c].id); getchar();
    printf("Enter Title: "); fgets(b[*c].title,100,stdin); b[*c].title[strcspn(b[*c].title,"\n")]=0;
    printf("Enter Author: "); fgets(b[*c].author,100,stdin); b[*c].author[strcspn(b[*c].author,"\n")]=0;
    printf("Enter Year: "); scanf("%d",&b[*c].year); (*c)++;
    printf("Book added successfully!\n");
}

void searchBook(Book b[], int c, char t[]) {
    for(int i=0;i<c;i++) if(!strcmp(b[i].title,t)){
        printf("Book ID: %d\nTitle: %s\nAuthor: %s\nYear: %d\n",b[i].id,b[i].title,b[i].author,b[i].year);
        return;
    }
    printf("Book not found.\n");
}

void displayBooks(Book b[], int c) {
    if(!c){printf("No books.\n"); return;}
    for(int i=0;i<c;i++)
        printf("\nBook ID: %d\nTitle: %s\nAuthor: %s\nYear: %d\n",b[i].id,b[i].title,b[i].author,b[i].year);
}

int main() {
    Book books[MAX]; int count=0,choice; char title[100];
    do {
        printf("\n1.Add 2.Search 3.Display 4.Exit\nChoose: "); scanf("%d",&choice); getchar();
        if(choice==1) addBook(books,&count);
        else if(choice==2){ printf("Enter Title: "); fgets(title,100,stdin); title[strcspn(title,"\n")]=0; searchBook(books,count,title);}
        else if(choice==3) displayBooks(books,count);
    } while(choice!=4);
}
