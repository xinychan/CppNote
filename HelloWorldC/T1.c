#include <stdio.h>
// #include <stdio.h> 寻找系统的资源
// #include "stdio.h" 寻找自己写的资源
// .h .hpp(声明文件/头文件)
// .c .cpp(实现文件)

int mainT1() { // 函数的主入口；入口函数名称为 main；一个项目中只能有一个 main 函数作为入口
    printf("Hello, World!\n");
    printf("你好\n");

    // getchar(); // 阻塞程序
    return 0;
}
