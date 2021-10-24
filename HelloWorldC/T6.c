#include <stdio.h>

// 通过指针（地址）修改值
int mainT6() {

    int i = 100;
    // 取出地址，赋值给指针变量p
    int *p = &i;
    // 通过变量i赋值
    i = 200;
    printf("int i == %d\n", i);
    // 通过指针（地址）赋值
    *p = 300;
    printf("int i == %d\n", i);

    return 0;
}
