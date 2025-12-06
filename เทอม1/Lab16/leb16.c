#include <stdio.h>

int main() {
    int a[] = {15,7,25,3,73,32,45}, n=7, i, j, t, pos;
    printf("Old Series : 15, 7, 25, 3, 73, 32, 45\n");
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j]) t=a[i],a[i]=a[j],a[j]=t;
    printf("New Series : ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i<n-1) printf(", ");
        if(a[i]==32) pos=i;
    }
    printf("\nPos of 32 : %d",pos);
}
