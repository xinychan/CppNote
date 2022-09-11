#include <stdio.h>

// Java 万物皆对象
// C/C++ 万物皆指针
// Linux 万物皆文件
int mainT4() {

    // 指针 == 内存地址；内存地址 == 指针
    // %p = 地址/指针输出的占位
    // &num1 = 取num1变量的地址
    // 变量，函数，对象，结构体等等都是地址

    int num1 = 100;
    printf("num1 address : %p\n", &num1);

    return 0;
}