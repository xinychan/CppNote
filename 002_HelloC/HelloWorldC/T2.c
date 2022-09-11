#include <stdio.h>

// 基本数据类型
int mainT2() {
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

    // C 语言中 boolean：NULL == 0 == false,非0 == true
    int bool = 0;
    if (bool) {
        printf("false \n");
    } else {
        printf("true \n");
    }
    bool = (int) NULL;
    if (!bool) {
        printf("true \n");
    } else {
        printf("false \n");
    }

    return 0;
}
