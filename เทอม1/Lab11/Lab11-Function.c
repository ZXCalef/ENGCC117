#include <stdio.h>

int main() {
    int number, temp, digits = 0, sum = 0 ;

    printf( "Enter Number:\n" ) ;
    scanf( "%d", &number ) ;

    temp = number ;

    while ( temp > 0 ) {
        digits++ ;
        temp /= 10 ;
    }

    temp = number ;

    while ( temp > 0 ) { 
        int digit = temp % 10 ;
        int power = 1 ;

        for ( int i = 0 ; i < digits ; i++ )
            power *= digit ;

        sum += power ;
        temp /= 10 ;
    }

    printf( "%s\n" , ( sum == number ) ? "Pass." : "Not Pass.") ;

    return 0 ;
}
