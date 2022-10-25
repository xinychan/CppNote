#include <stdio.h>

#include "mathutils/include/fibonacci.h"
#include "mathutils/include/factorial.h"

// 动态链接库的构建和使用
// 先进入目录 mathutils，在目录中编译所在的源文件
// Linux 上把 factorial.c fibonacci.c 编译成动态链接库 libmathutils.so
// gcc -shared -fPIC factorial.c fibonacci.c -o libmathutils.so
// Windows 上把 factorial.c fibonacci.c 编译成动态链接库 libmathutils.dll
// gcc -shared -fPIC factorial.c fibonacci.c -o libmathutils.so
// 编译 03_shared_library.c 并带上mathutils中的动态链接库
// gcc 03_shared_library.c -Lmathutils -lmathutils -o 03_shared_library
// 运行时，需要先进入动态链接库所在目录 mathutils，在目录中执行 03_shared_library
// cd mathutils/
// ../03_shared_library
// Fibonacci(5): 8
// Factorial(5): 120

int main(void) {

    printf("Fibonacci(5): %d\n", Fibonacci(5));
    printf("Factorial(5): %d\n", Factorial(5));

    return 0;
}