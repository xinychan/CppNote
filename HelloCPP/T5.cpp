#include <iostream>

using namespace std;

// 函数重载1
int add(int num1, int num2) {
    return num1 + num2;
}

// 函数重载2
int add(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

// 默认形参赋值，不能与原重载函数的参数冲突，避免二义性
//int add(int num1, int num2, bool isOk = 0) {
//    if (isOk) {
//        return num1 + num2;
//    }
//    return 0;
//}

// 默认形参赋值
int add(int num1, bool isOk = 0) {
    if (isOk) {
        return num1;
    }
    return 0;
}

// C++的函数重载
// C语言不支持函数重载
int main() {
    add(10, 20);
    return 0;
}