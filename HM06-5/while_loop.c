#include <stdio.h>

int main() {
    int n, i, j ;

    printf( "Enter number: " ) ;
    scanf( "%d", &n) ;

    i = n ;
    while ( i >= 2 ) {
        j = 2 ;
        while ( j < i ) {
            if ( i % j == 0 ) {
                break ;         //break ทำให้ loop ตรวจตัวหารหยุดทันทีเมื่อเจอเลขที่หารลงตัว
            }
            j++ ;
        }

        if ( j == i ) {
            printf( "%d ", i) ;
        }
        i-- ;
    }

    printf( "\n" ) ;
    return 0 ;
}
