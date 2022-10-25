#include <iostream>

#include "mathutils/include/factorial.h"
#include "mathutils/include/fibonacci.h"

// 使用 C++ 调用 C 函数
int main() {
    std::cout << Factorial(5) << std::endl;
    std::cout << Fibonacci(5) << std::endl;
    return 0;
}