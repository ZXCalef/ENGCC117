#include <stdio.h>

struct Student {
    char Name[ 50 ] ; //ชื่อ ID 
    char ID[ 10 ] ;
    float ScoreSub1 ; // คะแนนแต่ละวิชา
    float ScoreSub2 ;
    float ScoreSub3 ;
    float ScoreSub4 ;
    float ScoreSub5 ;
} ;
typedef struct Student S ; //สามารถใช้ S แทน struct Student
///////////////////////////////////////////////////////////////////////////////////
int main() {
    S students[ 3 ] ;
    int i, j ;

    printf( "Enter the details of 3 students:\n" ) ; //ใช้ลูปรับข้อมูล 3 นักศึกษา

    for ( i = 0 ; i < 3 ; i++ ) {
        printf( "Student %d:\n" , i + 1 ) ;

        printf( "Name: \n" ) ;
        getchar() ;
        fgets( students[ i ].Name, sizeof( students[ i ].Name ), stdin ) ; //fgets รับชื่อที่มีช่องว่างได้
        for ( j = 0 ; students[ i ].Name[ j ] != '\0' ; j++ ) {
            if ( students[ i ].Name[ j ] == '\n' ) { //ลูปแก้ไข \n เป็น \0 เพื่อให้ชื่อไม่ขึ้นบรรทัดใหม่
                students[ i ].Name[ j ] = '\0' ;
                break ;
            }
        }
///////////////////////////////////////////////////////////////////////////////////
        printf( "ID: \n" ) ;
        scanf( "%s" , students[ i ].ID ) ;

        printf( "Scores in Subject 1: \n" ) ; scanf( "%f" , &students[ i ].ScoreSub1 ) ; //รับ รหัสนักศึกษา และ คะแนน 5 วิชา
        printf( "Scores in Subject 2: \n" ) ; scanf( "%f" , &students[ i ].ScoreSub2 ) ;
        printf( "Scores in Subject 3: \n" ) ; scanf( "%f" , &students[ i ].ScoreSub3) ;
        printf( "Scores in Subject 4: \n" ) ; scanf( "%f" , &students[ i ].ScoreSub4) ;
        printf( "Scores in Subject 5: \n" ) ; scanf( "%f" , &students[ i ].ScoreSub5) ;
    }

    printf( "\n" ) ;
///////////////////////////////////////////////////////////////////////////////////
    for ( i = 0 ; i < 3 ; i++ ) {
        float scores[ 5 ] = { students[ i ].ScoreSub1, students[ i ].ScoreSub2, //เก็บ คะแนนทั้ง 5 วิชา ในอาร์เรย์
                            students[ i ].ScoreSub3, students[ i ].ScoreSub4,
                            students[ i ].ScoreSub5 } ;
        float avg = 0;

        printf( "Student %d:\n" , i + 1 ) ; //แสดง ชื่อ, รหัส, คะแนน และ คำนวณ ผลรวมเพื่อใช้หาค่าเฉลี่ย
        printf( "Name: %s\n" , students[ i ].Name ) ;
        printf( "ID: %s\n" , students[ i ].ID ) ;
        printf( "Scores: " ) ;
        for ( j = 0 ; j < 5 ; j++ ) {
            printf( "%.0f " , scores[ j ] ) ;
            avg += scores[ j ] ;
        }
    ///////////////////////////////////////////////////////////////////////////////////    
        printf( "\nGrades: " ) ;
        for ( j = 0 ; j < 5 ; j++ ) {
            if ( scores[ j ] >= 80 ) printf( "A " ) ; //แปลงคะแนนแต่ละวิชาเป็น เกรด ตามเกณฑ์ แสดง ค่าเฉลี่ยคะแนน
            else if ( scores[ j ] >= 75 ) printf( "B+ " ) ;
            else if ( scores [ j ] >= 70 ) printf( "B " ) ;
            else if ( scores [ j ] >= 65 ) printf( "C+" ) ;
            else if ( scores [ j ] >= 60 ) printf( "C " ) ;
            else if ( scores [ j ] >= 55 ) printf( "D+ ") ;
            else if ( scores [ j ] >= 50 ) printf( "D " ) ;
            else printf( "F " ) ;
        }
        printf( "\nAverage Scores: %.1f\n\n" , avg / 5 ) ;
    }

    return 0 ;
}
