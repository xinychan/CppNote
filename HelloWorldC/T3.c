#include <stdio.h>

// 常用基本类型的占用字节数;sizeof 获取字节数
int mainT3() {

    printf("int sizeof == %d\n", sizeof(int)); // sizeof = 4
    printf("double sizeof == %d\n", sizeof(double)); // sizeof = 8
    printf("float sizeof == %d\n", sizeof(float)); // sizeof = 4
    printf("long sizeof == %d\n", sizeof(long)); // sizeof = 4
    printf("short sizeof == %d\n", sizeof(short)); // sizeof = 2
    printf("char sizeof == %d\n", sizeof(char)); // sizeof = 1

    return NULL; // NULL == 0
}

