#include <stdio.h>

#include "fibonacci/fibonacci.h"
#include "factorial/factorial.h"

// 使用 CMake 完成库的编译和链接
// 参考 factorial/fibonacci 中的 CMakeLists.txt
// 以及项目中引用到 factorial/fibonacci 的 CMakeLists.txt
// CMakeLists.txt 编写完成后，直接运行本文件无效
// 需要先 Build-Install 进行安装，生成的链接库在 install 目录
// 然后进入 /cmake-build-debug/install/bin 目录，运行程序
// ./04_library_with_cmake.c.exe
// Fibonacci(5): 8
// Factorial(5): 120
int main(void) {

    printf("Fibonacci(5): %d\n", Fibonacci(5));
    printf("Factorial(5): %d\n", Factorial(5));

    return 0;
}