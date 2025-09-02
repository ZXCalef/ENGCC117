#include <stdio.h>

int main() {
    // จำนวนสินค้า
    int latte, americano, coke, greenDrink;
    int tuaPab, sunflower, jinSom;

    // ราคาสินค้า
    int priceLatte = 35;
    int priceAmericano = 30;
    int priceCoke = 10;
    int priceGreenDrink = 12;
    int priceTuaPab = 20;
    int priceSunflower = 13;
    int priceJinSom = 15;

    // รับจำนวนสินค้าที่ลูกค้าซื้อ
    printf("=== ใส่จำนวนสินค้า ===\n");

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
    int total = (latte * priceLatte) + (americano * priceAmericano) +
                (coke * priceCoke) + (greenDrink * priceGreenDrink) +
                (tuaPab * priceTuaPab) + (sunflower * priceSunflower) +
                (jinSom * priceJinSom);

    // แสดงผลราคารวม + รายการสินค้า
    printf("\n=== สรุปการซื้อ ===\n");
    if (latte > 0) printf("ลาเต้ x %d = %d บาท\n", latte, latte * priceLatte);
    if (americano > 0) printf("อเมริกาโน x %d = %d บาท\n", americano, americano * priceAmericano);
    if (coke > 0) printf("โค้ก x %d = %d บาท\n", coke, coke * priceCoke);
    if (greenDrink > 0) printf("น้ำเขียว x %d = %d บาท\n", greenDrink, greenDrink * priceGreenDrink);
    if (tuaPab > 0) printf("ถั่วแปบ x %d = %d บาท\n", tuaPab, tuaPab * priceTuaPab);
    if (sunflower > 0) printf("เมล็ดทานตะวัน x %d = %d บาท\n", sunflower, sunflower * priceSunflower);
    if (jinSom > 0) printf("จิ้นส้มหมก x %d = %d บาท\n", jinSom, jinSom * priceJinSom);

    printf("------------------------\n");
    printf("ราคารวมทั้งหมด = %d บาท\n", total);

    // รับเงินจากลูกค้า
    int money;
    printf("\nกรุณาใส่จำนวนเงินที่จ่าย: ");
    scanf("%d", &money);

    // ตรวจสอบเงิน
    if (money < total) {
        printf("เงินไม่พอ! กรุณาจ่ายเพิ่ม\n");
    } else {
        int change = money - total;
        printf("ชำระเงินแล้ว: %d บาท\n", money);
        printf("เงินทอน = %d บาท\n", change);
    }

    printf("\n=== ขอบคุณที่ใช้บริการ ===\n");

    return 0;
}

