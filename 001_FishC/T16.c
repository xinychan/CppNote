#include <stdio.h>

// 函数声明；函数需要先声明再使用
void printName();

// 函数具体实现；函数声明后的具体实现
void printName() {
    printf("CLion");
}

// 函数
int main() {
    // 函数调用
    printName();
    return 0;
}
