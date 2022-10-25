#include <stdio.h>

// 可执行程序的编译过程
// gcc -E main.c -o main.i
// gcc -S main.i -o main.s
// gcc -c main.s -o main.o
// gcc -v main.o -o main
// 查看 main 文件类型
// file main.exe
// main.exe: PE32+ executable (console) x86-64, for MS Windows
// 执行 main.exe
// ./main
// 输出打印结果
// Hello, World!
int main() {
    printf("Hello, World!\n");
    return 0;
}
