#include <stdio.h>
#include "include/io_utils.h"

// 只读指针变量与只读变量指针
int main() {
    int a = 10;
    int b = 100;

    // 只读指针变量；指针地址只读，变量的值可读写
    // 指针指向地址不可修改，地址的值可以修改
    // const 修饰指针，指针不可变
    int *const cp = &a;
    // cp = &b;
    *cp = 20;

    // 只读变量指针；变量的值只读，指针地址可读写
    // 地址的值不可以修改，指针指向地址可修改
    // const 修饰 int，int 值不可变
    int const *cp2 = &a;
    cp2 = &b;
    // *cp2 = 20;

    // 指向只读变量的只读指针
    // const 修饰指针，指针不可变
    // const 修饰 int，int 值不可变
    int const *const cp3 = &a;
    // cp3 = &b;
    // *cp3 = 20;
    return 0;
}
