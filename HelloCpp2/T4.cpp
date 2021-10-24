#include <iostream>

using namespace std;

// 指针常量/常量指针/常量指针常量
int main() {

    int num1 = 10;
    int num2 = 20;

    // 常量指针
    const int *numP1 = &num1;
    // *numP1 = 100; // 不可以修改【常量指针】指向地址的值
    numP1 = &num2; // 可以修改【常量指针】的指向地址

    // 指针常量
    int *const numP2 = &num1;
    *numP2 = 200; // 可以修改【指针常量】指向地址的值
    // numP2 = &num1; // 不可以修改【指针常量】的指向地址

    // 常量指针常量
    const int *const numP3 = &num1;
    // *numP3 = 100; // 不可以修改【常量指针常量】指向地址的值
    // numP3 = &num2; // 不可以修改【常量指针常量】的指向地址
    return 0;
}
