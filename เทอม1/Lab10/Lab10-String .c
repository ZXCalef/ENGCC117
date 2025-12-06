#include <stdio.h>

char to_lowercase( char c ) {
    if ( c >= 'A' && c <= 'Z' ) {
        return c + 32 ;
    }
    return c ;
}

int main( void ) {
    char word[ 100 ] ;
    int len = 0, i, j ;

    printf(" Enter word:\n" ) ;
    scanf( "%s" , word ) ;

    while ( word[ len ] != '\0' ) {
        len++ ;
    }

    for ( i = 0 , j = len - 1 ; i < j ; i++, j-- ) {
        if ( to_lowercase ( word[ i ] ) != to_lowercase ( word[ j ] ) ) {
            printf( "Not Pass.\n" ) ;
            return 0 ;
        }
    }

    printf( "Pass.\n" ) ;
    return 0 ;
}
