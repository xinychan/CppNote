#include <stdio.h>

// 变量
// 变量的命名不能使用C语言关键字
// C语言主要的使用的标准：C89/C99/C11
// C89(ANSI C)标准关键字32个
// C99标准关键字37个
// C11标准关键字44个
int main() {
    int i = 10;
    double d = 200;
    float f = 200;
    long l = 200;
    short s = 200;
    char c = 'a';
    // 字符串
    char *str = "abc";

    // 打印需要占位
    printf("i = %d \n", i); // %d == 整型
    printf("d = %lf \n", d); // %lf == long float
    printf("f = %f \n", f); // %f == float
    printf("l = %d \n", l); // long 使用 整型
    printf("s = %d \n", s); // short 使用 整型
    printf("c = %c \n", c); // %c == char
    printf("str = %s \n", str); // %s == String
    return 0;
}
