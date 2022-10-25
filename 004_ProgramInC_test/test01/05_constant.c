#include <stdio.h>

#define COLOR_RED 0xFF0000

// 常量
int main() {
    // const 修饰的常量，只能赋值一次
    const int red = 0xFF0000;
    printf("red:%d\n", red);
    // red = 0;不可再次赋值

    // 通过指针可以修改 const 常量
    int *p_red = &red;
    *p_red = 0;
    printf("red:%d\n", red);

    // 定义宏，值无法修改
    printf("COLOR_RED:%d\n", COLOR_RED);

    // 取消宏定义，宏无法再使用
#undef COLOR_RED
    // printf("COLOR_RED:%d\n", COLOR_RED); // 宏无法再使用

    return 0;
}
