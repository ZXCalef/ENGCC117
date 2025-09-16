#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int command ;
    int number, guess ;
    int score ;
    int lower, upper ;

    srand( time( NULL ) ) ; 

    while ( 1 ) {
        printf( "Do you want to play game (1=play,-1=exit) :\n" ) ;
        if ( scanf ( "%d" , &command ) != 1 ) {

            while ( getchar() != '\n' ) ;
            printf( "\nPlease enter only 1 or -1.\n\n" ) ;
            continue ;
        }

        if ( command == -1 ) {
            printf( "\nSee you again.\n" ) ;
            break;
        } else if ( command == 1 ) {
            score = 100 ;
            number = rand() % 100 + 1 ;
            lower = 1 ;
            upper = 100 ;

            printf( "\n(Score=100)\n" ) ;

            while ( 1 ) {
                printf( "\nGuess the winning number ( %d-%d ) :\n" , lower, upper ) ;
                scanf( "%d" , &guess ) ;

                if ( guess == number ) {
                    printf( "\nThat is correct! The winning number is %d.\n" , number ) ;
                    printf( "\nScore this game: %d\n" , score ) ;
                    break ;
                } else {
                    score -= 10 ;
                    if ( guess < number ) {
                        if ( guess + 1 > lower ) lower = guess + 1 ;
                        printf( "\nSorry, the winning number is HIGHER than %d. ( Score=%d )\n" , guess, score ) ;
                    } else {
                        if ( guess - 1 < upper ) upper = guess - 1 ;
                        printf( "\nSorry, the winning number is LOWER than %d. (Score=%d)\n" , guess, score) ;
                    }
                }
            }
        } else {
            printf( "\nPlease enter only 1 or -1.\n\n" ) ;
        }
    }

    return 0;
}
