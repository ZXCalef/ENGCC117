#include <stdio.h>

int main() {
    int n, i, j ;

    printf( "Enter number: " ) ;
    scanf( "%d", &n) ;

    for ( i = n; i >= 2; i-- ) {
        for ( j = 2; j < i; j++ ) {
            if ( i % j == 0 ) {

                j = i;
            }
        }
        if ( j == i ) {
            printf( "%d ", i ) ;
        }
    }

    printf( "\n" ) ;
    return 0;
}
