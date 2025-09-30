    #include <stdio.h>
    
    int main() {
        int number, temp, digits = 0, sum = 0 ; //sum ผลรวมของเลขยกกำลังจำนวนหลัก   

        printf( "Enter Number:\n" ) ; //ตัวเลขที่ผู้ใช้กรอก
        scanf( "%d", &number ) ;

        temp = number ;

        while ( temp > 0 ) { //ตัวแปรชั่วคราวใช้คำนวณ ////ใช้ลูปหาร 10 จนถึง 0 เพื่อหาจำนวนหลัก
            digits++ ; //จำนวนหลักของตัวเลข
            temp /= 10 ;
        }
    ///////////////////////////////////////////////////////////////////////////////////
        temp = number ;

        while ( temp > 0 ) { 
            int digit = temp % 10 ; //digit = temp % 10 → ดึงหลักสุดท้าย
            int power = 1 ;

            for ( int i = 0 ; i < digits ; i++ )
                power *= digit ;

            sum += power ;
            temp /= 10 ; //ตัดหลักสุดท้ายออก (temp /= 10)
        }

        printf( "%s\n" , ( sum == number ) ? "Pass." : "Not Pass.") ; //ถ้า sum == number → แสดง "Pass." ถ้าไม่เท่ากัน → แสดง "Not Pass."

        return 0 ;
    }
