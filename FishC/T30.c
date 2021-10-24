#include <stdio.h>
#include <time.h>

// 枚举的定义
enum Week {
    // 枚举值默认从0开始，然后依次递增
    sun, mon, tue, wed, thu, fir, sat
};

// 枚举类型在本质上就是有命名的整数，属于整型的一种，在代码中是可以和整型互换的
// C语言中，枚举是一种类型，属于整型的范畴
// 整型除了short、int、long、long long外，还包括char、_Bool（C99标准新增）和enum
// 因此，枚举的使用和整数值其实没区别
enum Color {
    red, green, blue = 10, yellow
};

// 枚举类型
int main() {

    enum Week today;
    struct tm *p;
    time_t t;
    p = localtime(&t);
    today = p->tm_wday;
    switch (today) {
        case mon:
        case tue:
        case wed:
        case thu:
        case fir:
            printf("Work Day\n");
            break;
        case sat:
        case sun:
            printf("Life Day\n");
            break;
        default:
            printf("default Day\n");
            break;
    }

    // 枚举与整型
    enum Color rgb;
    printf("red = %d\n", red);
    printf("green = %d\n", green);
    printf("blue = %d\n", blue);
    printf("yellow = %d\n", yellow);

    int num = yellow;
    printf("num:%d\n", num);

    return 0;
}
