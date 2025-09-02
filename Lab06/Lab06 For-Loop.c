 #include <stdio.h>

int main () {
    int N ;
    printf( "Enter value: " ) ;
    scanf( "%d" , &N ) ;

    if (N % 2 == 1) { // เลขคี่
        printf( "Series: " , N ) ;
        for ( int i = 1 ; i <= N ; i += 2 ) {
            printf( "%d ", i ) ;
        }// end for
        
    } else { // เลขคู่
        printf( "Series: ", N ) ;
        for ( int i = N ; i >= 0 ; i -= 2 ) {
            printf( "%d ", i ) ;
        }// end for
    }// end if

    return 0 ;
}//end function