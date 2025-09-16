#include <stdio.h>
#include <stdbool.h>

int main() {
    int N ;
    printf( "Enter N :\n" ) ;
    scanf( "%d" , &N ) ;

    int arr[ N ] ;
    for ( int i = 0; i < N; i++ ) {
        printf( "Enter value[%d] :\n", i ) ;
        scanf( "%d" , &arr[i] ) ;
    }

    printf( "Index:" ) ;
    for ( int i = 0 ; i < N ; i++ ) {
        printf( " %d" , i ) ;
    }
    printf( "\n" ) ;

    printf( "Array:" ) ;
    for ( int i = 0 ; i < N ; i++ ) {
        bool prime = true ;
        if ( arr[ i ] < 2 ) prime = false ;
        else {
            for ( int j = 2; j * j <= arr[ i ] ; j++ ) {
                if ( arr[ i ] % j == 0 ) {
                    prime = false ;
                    break ;
                }
            }
        }
        if ( prime ) printf( " %d" , arr[ i ] ) ;
        else printf( " #" ) ;
    }
    printf( "\n" ) ;

    return 0 ;
}
