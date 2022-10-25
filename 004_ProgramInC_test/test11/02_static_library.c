#include <stdio.h>

#include "mathutils/include/fibonacci.h"
#include "mathutils/include/factorial.h"

// 静态链接库的构建和使用
// 编译 .c 文件成为 .o 文件
// gcc -c factorial.c  fibonacci.c
// 编译 .o 文件打包成静态链接库 .a 文件
// ar rcs libmathutils.a factorial.o  fibonacci.o
// 显示静态链接库 .a 文件包含的内容
// ar t libmathutils.a
// 编译当前 02_static_library.c 文件，编译时带上动态链接库 libmathutils.a
// gcc 02_static_library.c mathutils/libmathutils.a -o 02_static_library
// 执行 02_static_library.exe
// ./02_static_library
int main(void) {

    printf("Fibonacci(5): %d\n", Fibonacci(5));
    printf("Factorial(5): %d\n", Factorial(5));

    return 0;
}