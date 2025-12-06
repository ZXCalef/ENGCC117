#include <stdio.h>

int main() {
    int n, i, j ;

    printf( "Enter number: " ) ;
    scanf( "%d", &n) ;

    i = n ;
    do {
<<<<<<< HEAD
        int j = 2;

        do {
            j++;
        } while (j < i && i % (j - 1) != 0);

        if (j == i) {
            printf("%d ", i);
=======
        j = 2 ;
        do {
            if ( i % j == 0 ) {
                break ;         //break ทำให้ loop ตรวจตัวหารหยุดทันทีเมื่อเจอเลขที่หารลงตัว
            }
            j++ ;
        } while (j < i) ;

        if ( j == i ) {
            printf( "%d ", i ) ;
>>>>>>> 15e934cc92e079f7e07d5749335fb9e7aad935a2
        }
        i-- ;
    } while ( i >= 2 ) ;

    printf( "\n" ) ;
    return 0 ;
}
