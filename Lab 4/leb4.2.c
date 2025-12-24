#include <stdio.h>
#include <stdlib.h>

void go(int ***p, int **z);

int main() {
    int *b = (int*)malloc(sizeof(int));
    *b = 10;
    
    int *c = (int*)malloc(sizeof(int));
    *c = 20;
    
    int **a = NULL;
    
    printf("Initial values:\n");
    printf("b points to address: %p, value: %d\n", (void*)b, *b);
    printf("c points to address: %p, value: %d\n", (void*)c, *c);
    printf("a (double pointer) address: %p\n\n", (void*)&a);
    
    go(&a, &b);
    printf("After go(&a, &b):\n");
    printf("**a = %d (value)\n", **a);
    printf("*a = %p (points to same as b)\n", (void*)*a);
    printf("a = %p (value of a)\n", (void*)a);
    printf("&a = %p (address of a)\n\n", (void*)&a);
    
    go(&a, &c);
    printf("After go(&a, &c):\n");
    printf("**a = %d (value)\n", **a);
    printf("*a = %p (points to same as c)\n", (void*)*a);
    printf("a = %p (value of a)\n", (void*)a);
    printf("&a = %p (address of a)\n", (void*)&a);
    
    free(b);
    free(c);
    
    return 0;
}

void go(int ***p, int **z) {
    *p = *z;
    
    printf("Inside go function:\n");
    printf("  **z = %d\n", **z);
    printf("  *z = %p\n", (void*)*z);
}