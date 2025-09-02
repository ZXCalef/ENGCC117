#include <stdio.h>

int main() {
    int n, i, j ;

    printf( "Enter number: " ) ;
    scanf( "%d", &n) ;

    i = n ;
    do {
        j = 2 ;
        do {
            if ( i % j == 0 ) {
                break ;
            }
            j++ ;
        } while (j < i) ;

        if ( j == i ) {
            printf( "%d ", i ) ;
        }
        i-- ;
    } while ( i >= 2 ) ;

    printf( "\n" ) ;
    return 0 ;
}
