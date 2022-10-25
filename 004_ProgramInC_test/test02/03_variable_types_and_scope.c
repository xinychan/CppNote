#include <stdio.h>

// 文件作用域；当前文件中都可以使用
int file_value = 1;

// 原型作用域；int size 变量只能在函数原型中使用
void Function(int size, int array[size]);

void FunctionStatic() {
    // 静态变量；static int
    // 全局作用域，内存不会因函数退出而销毁
    // 静态变量初始化时有默认值，int 默认为0
    static int value3;
    // 自动变量；int value
    // 函数作用域，内存随函数退出而销毁
    // 初始化时没有默认值；初始化需要主动赋值，否则获取野值
    auto int value4 = 0;
    printf("value3 = %d\n", value3++);
    printf("value4 = %d\n", value4++);
}

// 寄存器变量；值直接写在寄存器，不在内存开辟空间
void FunctionRegister(register int value) {
    printf("value = %d\n", value);
}

// 变量的类型和作用域；
// 自动变量 auto；静态变量 static；寄存器变量 register
// 函数作用域，块作用域，全局作用域，函数原型作用域，文件作用域
int main() {
    // 自动变量；int value == auto int value2
    // 变量的类型为 auto 自动变量；变量的数据类型为 int
    // auto 自动变量在函数中内存会自动分配，函数结束内存自动销毁
    int value = 0;
    auto int value2 = 0;

    {
        // 块作用域
        auto int num = 0;
        printf("num = %d\n", num);
    }

    if (file_value > 0) {
        // 本质上也是块作用域
        int test = 0;
        printf("test = %d\n", test);
    }

    FunctionStatic();
    FunctionStatic();
    FunctionStatic();
    return 0;
}
