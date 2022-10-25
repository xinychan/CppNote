#include <stdio.h>
#include "include/io_utils.h"

// 指针
int main() {
    int a = 10;
    // &a 为取出变量 a 的内存地址
    int *p = &a;
    // p 类型为指针 ==> int *
    PRINT_HEX(p);
    PRINT_HEX(&a);
    // *p 为取出指针中存放的值
    PRINT_INT(*p);
    PRINT_INT(a);
    PRINT_INT(sizeof(int *));
    return 0;
}
