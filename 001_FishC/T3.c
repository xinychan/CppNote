#include <stdio.h>

// 数据类型
int main() {
    /*基本类型*/
    // 整数类型 short/int
    // 浮点数类型 float/double
    // 字符类型 char
    // 布尔类型（C99标准新增） _Bool
    // 枚举类型 enum

    /*指针类型*/

    /*构造类型*/
    // 数组类型
    // 结构体类型
    // 联合体类型

    /*空类型*/

    // sizeof 运算符：获取数据类型的长度
    printf("sizeof _Bool:%d\n", sizeof(_Bool));

    // signed 带符号位，可以为负数
    // unsigned 不带符号位，只能为正数和0
    char char1 = 127; // -128~127
    unsigned char char2 = 255; // 0~255
    printf("char1 :%d\n", char1);
    printf("char2 :%d\n", char2);

    return 0;
}
