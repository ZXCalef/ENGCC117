#include <stdio.h>

int main() {
    int position, years, projects ;
    int baseSalary = 0 ; //baseSalary เงินเดือนฐาน (เริ่มค่าเป็น 0) 
    float expBonus = 0, specialBonus = 0, netSalary = 0 ; //expBonus โบนัสตามประสบการณ์  //specialBonus โบนัสพิเศษ  

    printf( "Enter Position ( 1=Junior, 2=Mid-Level, 3=Senior ): " ) ; 
    scanf( "%d" , &position ) ; //position เก็บตำแหน่งงาน (1=Junior, 2=Mid-Level, 3=Senior)

    printf( "Enter Years of Experience: "  ) ;
    scanf( "%d" , &years ) ; //years เก็บจำนวนปีที่ทำงาน

    printf( "Enter Number of Projects Completed this Year: " ) ;
    scanf( "%d" , &projects ) ; //projects เก็บจำนวนโปรเจกต์ที่ทำสำเร็จ

///////////////////////////////////////////////////////////////////////////////////

        switch ( position ) { //เริ่ม คำสั่ง switch เพื่อเลือกกรณีตามค่า position
            case 1: baseSalary = 20000 ; break ; //เงินตั้งฐานแต่ละ case
            case 2: baseSalary = 35000 ; break ; 
            case 3: baseSalary = 50000 ; break ; 
            default: //break; ใช้เพื่อ ออกจาก switch หลังทำงานเสร็จ
                printf( "Invalid position!\n" ) ; //ถ้า position ไม่ใช่ 1, 2 หรือ 3 → แสดงข้อความ Invalid position!
                return 1 ; //return 1; ทำให้โปรแกรม หยุดทำงาน เพราะค่าตำแหน่งไม่ถูกต้อง
        } 
//////////////////////////////////////////////////////////////////////////////////

    if ( years < 1 ) {
        expBonus = 0 ; //ถ้าประสบการณ์น้อยกว่า 1 ปี → ไม่มีโบนัสประสบการณ์
    } else if ( years <= 3 ) {
        expBonus = baseSalary * 0.10 ; // ถ้าประสบการณ์ 1–3 ปี → โบนัส = 10% ของเงินเดือนฐาน
    } else if ( years <= 5 ) {
        expBonus = baseSalary * 0.15 ;//ถ้าประสบการณ์ 4–5 ปี → โบนัส = 15% ของเงินเดือนฐาน
        expBonus = baseSalary * 0.20 ; //ถ้าประสบการณ์มากกว่า 5 ปี → โบนัส = 20% ของเงินเดือนฐาน
    }

    if ( projects > 5 ) {
        specialBonus = baseSalary * 0.05 ;
    } //นอกจากนี้ยังมีโบนัสพิเศษหากโปรแกรมเมอร์ทำโปรเจคได้สำเร็จมากกว่า 5 โปรเจค โดยจะได้รับโบนัสเพิ่มอีก 5% ของเงินเดือน
///////////////////////////////////////////////////////////////////////////////////

    netSalary = baseSalary + expBonus + specialBonus ; //รวมเงินเดือนฐาน + โบนัสตามประสบการณ์ + โบนัสพิเศษ

    printf( "\nBase Salary: %d THB\n", baseSalary ) ; //แสดง เงินเดือนฐาน
    printf( "Experience Bonus: %.0f THB\n", expBonus ) ; //แสดง โบนัสตามประสบการณ์    
    printf( "Special Bonus: %.0f THB\n", specialBonus ) ; //แสดง โบนัสพิเศษ
    printf( "Net Salary: %.0f THB\n", netSalary ) ; //แสดง เงินเดือนสุทธิรวมทั้งหมด

    return 0 ;
}
