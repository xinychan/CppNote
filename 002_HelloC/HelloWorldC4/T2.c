#include <stdio.h>

// 字符串
int main() {

    // 声明字符串的方式1
    char str[] = {'m', 'a', 'i', 'n', '\0'};
    str[2] = 'z'; // 修改不会崩溃
    printf("str = %s\n", str); // printf 必须遇到 \0 才会结束

    // 声明字符串的方式2
    char *str2 = "main2"; // 隐式，结尾默认添加 \0
    // str2[2] = 'z'; // 修改会崩溃
    printf("str2 = %s\n", str2);

    // char str[] 修改值不会崩溃；char *str2 修改值会崩溃；为什么？
    // 不论是通过 char str[] 还是 char *str2 方式声明字符串，字符串都会在“全局区/静态区域”保存
    // char str[] 会把静态区域的字符串，拷贝到栈区；修改时是修改自己栈区的字符串，允许修改
    // char *str2 不会把静态区域的字符串拷贝到栈区，而是一个指针指向字符串所在的静态区域地址；静态区域的字符串是不允许修改的

    return 0;
}
