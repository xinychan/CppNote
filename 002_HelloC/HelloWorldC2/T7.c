#include <stdio.h>

void add(int x, int y) {
    int result = x + y;
    printf("add result = %d\n", result);
}

void sub(int x, int y) {
    int result = x - y;
    printf("sub result = %d\n", result);
}

/**
 * 回调加法/减法
 * void(*func)(int, int) 声明函数指针
 * void 表示回调函数返回值
 * (*func) 表示回调函数名称
 * (int, int) 表示回调的函数所需参数
 * @param func 传入函数指针
 * @param x 传入回调的函数所需参数
 * @param y 传入回调的函数所需参数
 */
void operate(void(*func)(int, int), int x, int y) {
    // 使用 func 与 (*func) 是等价的
    //(*func)(x, y);
    func(x, y);
    printf("operate *func = %p\n", func);
}

// 函数指针；相当于Java的接口回调
// 函数指针可将函数做参数传入
int mainT7() {
    // 函数同数组一样，函数的地址 == 函数本身 (&add == add)
    operate(add, 10, 5);
    operate(&add, 10, 5);
    printf("main add = %p\n", add);
    printf("main &add = %p\n", &add);

    operate(sub, 10, 5);
    operate(&sub, 10, 5);
    printf("main sub = %p\n", sub);
    printf("main &sub = %p\n", &sub);

    return 0;
}