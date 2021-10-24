#include <stdio.h>

void func(int x);

void func(int index) {
    printf("func");
}

int mainNum = 0;

// 作用域
int main() {
    // 代码块作用域
    // 在 { } 之间的代码，包括函数中()里面的形参
    printf("main");

    // 文件作用域
    // 代码块之外声明的标识符具有文件作用域
    // 作用范围：从声明位置开始，到文件结束
    mainNum++;

    // 原型作用域
    // 函数原型中声明的参数名
    func(10); // func 声明的参数 int 的名称 x

    // 函数作用域
    // 适用于 goto 语句的标签
    // 将 goto 语句的标签限制在同一个函数内部，防止出现重名标签

    return 0;
}
