#include <stdio.h>
#include "include/io_utils.h"

int *point;

void ErrorPoint() {
    int num = 100;
    point = &num;
    // 全局变量使用完，释放指针
    point = NULL;
}

// 指针的特殊使用
int main() {
    // 不可将指针硬编码指向固定地址
//    int *p = 100;
//    PRINT_INT(p);
//    PRINT_INT(*p);
//    PRINT_HEX(&p);

    // 对指针初始化
    int *p = NULL;
    int num = 10;
    p = &num;
    if (p) {
        // 指针有赋值时，执行操作
        PRINT_INT(*p);
    }

    ErrorPoint();
    if (point) {
        PRINT_INT(*point);
    }
    return 0;
}
