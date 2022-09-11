#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 动态内存管理
int main() {
    printf("main");
    // 动态内存管理常用函数；依赖 <stdlib.h>
    // malloc()
    // 申请动态内存空间
    // free()
    // 释放动态内存空间
    // calloc()
    // 申请并初始化一系列内存空间
    // realloc()
    // 重新分配内存空间

    // 内存泄漏常见情况
    // 申请的内存对象使用后没有及时free释放
    // 申请的内存对象丢失申请的内存地址（指向其他地址）

    // 初始化内存空间常用函数；依赖 <string.h>
    // memset()
    // 使用一个常量字节填充内存空间
    // memcpy()
    // 拷贝内存空间
    // memmove()
    // 拷贝内存空间
    // memcmp()
    // 比较内存空间
    // memchr()
    // 在内存空间中搜索一个字符

    return 0;
}
