#include <stdio.h>
#include "include/io_utils.h"

// 判断是否是大端序
// 使用联合体共享内存特性，判断当前环境是大端序还是小端序
int IsBigEndian() {
    union {
        char c[2];
        short s;
    } value = {.s=0x100};
    // 如果首位char是1，说明是大端序，符合开发者阅读
    // 如果首位char是0，说明是小端序，符合机器阅读
    return value.c[0] == 1;
}

// 判断是否是大端序；使用指针
int IsBigEndian2() {
    short s = 0x100;
    char *p = (char *) &s;
    return p[0] == 1;
}

// 大端序小端序转换；使用联合体
int ToggleEndian(int original) {
    union {
        char c[4];
        int i;
    } value = {.i = original};
    char temp = value.c[0];
    value.c[0] = value.c[3];
    value.c[3] = temp;
    temp = value.c[1];
    value.c[1] = value.c[2];
    value.c[2] = temp;
    return value.i;
}

// 大端序小端序转换；使用指针
int ToggleEndian2(int original) {
    char *p = (char *) &original;
    char temp = p[0];
    p[0] = p[3];
    p[3] = temp;
    temp = p[1];
    p[1] = p[2];
    p[2] = temp;
    return original;
}

// 判断字节序
int main() {
    PRINT_INT(IsBigEndian());
    PRINT_INT(IsBigEndian2());
    int original = 0x12345678;
    PRINT_HEX(ToggleEndian(original)); // 0x78563412
    PRINT_HEX(ToggleEndian2(original)); // 0x78563412
    return 0;
}
