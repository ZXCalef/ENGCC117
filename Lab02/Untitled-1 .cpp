#include <stdio.h>

int main() 
{

    // ราคาสินค้า

    int priceLatte = 35;
    int priceAmericano = 30;
    int priceCoke = 10;
    int priceGreenDrink = 12;
    int priceTuaPab = 20;
    int priceSunflower = 15;
    int priceJinSom = 13;

    // ตัวแปรเก็บจำนวนที่ลูกค้าซื้อ
    int latte, americano, coke, greenDrink, tuaPab, sunflower, jinSom;

    // รับจำนวนสินค้า
    printf("=== ใส่จำนวนสินค้าที่ต้องการซื้อ ===\n");

    printf("ลาเต้ : ");
    scanf("%d", &latte);

    printf("อเมริกาโน : ");
    scanf("%d", &americano);

    printf("โค้ก : ");
    scanf("%d", &coke);

    printf("น้ำเขียว : ");
    scanf("%d", &greenDrink);

    printf("ถั่วแปบ : ");
    scanf("%d", &tuaPab);

    printf("เมล็ดทานตะวัน : ");
    scanf("%d", &sunflower);

    printf("จิ้นส้มหมก : ");
    scanf("%d", &jinSom);

    // คำนวณราคารวม

    int total = (latte * priceLatte) + 
                (americano * priceAmericano) + 
                (coke * priceCoke) +
                (greenDrink * priceGreenDrink) +
                (tuaPab * priceTuaPab) +
                (sunflower * priceSunflower) +
                (jinSom * priceJinSom);

    // แสดงผลสรุป

    printf("\n=== สรุปรายการ ===\n");
    printf("ลาเต้ %d แก้ว = %d บาท\n", latte, latte * priceLatte);
    printf("อเมริกาโน %d แก้ว = %d บาท\n", americano, americano * priceAmericano);
    printf("โค้ก %d กระป๋อง = %d บาท\n", coke, coke * priceCoke);
    printf("น้ำเขียว %d ขวด = %d บาท\n", greenDrink, greenDrink * priceGreenDrink);
    printf("ถั่วแปบ %d ชิ้น = %d บาท\n", tuaPab, tuaPab * priceTuaPab);
    printf("เมล็ดทานตะวัน %d ห่อ = %d บาท\n", sunflower, sunflower * priceSunflower);
    printf("จิ้นส้มหมก %d ห่อ = %d บาท\n", jinSom, jinSom * priceJinSom);

    printf("\nรวมทั้งหมด = %d บาท\n", total);

    // รับเงินจากลูกค้า

    int money, change;
    printf("\nลูกค้าชำระเงิน: ");
    scanf("%d", &money);

    // ตรวจสอบเงินทอน
    if (money < total) {
        
        printf(" เงินไม่พอ! กรุณาชำระเพิ่ม %d บาท\n", total - money);
    } else {
        change = money - total;
        printf(" ชำระแล้ว %d บาท\n", money);
        printf(" เงินทอน = %d บาท\n", change);
    }

    return 0;
}
