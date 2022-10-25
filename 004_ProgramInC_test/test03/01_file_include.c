// #include <stdio.h> 声明了 printf 函数原型
// 不通过 include，直接声明 printf 函数原型，直接编译执行 printf
int printf(const char *, ...);

int main() {
    printf("Hello, World!\n");
    return 0;
}
