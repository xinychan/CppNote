#include <stdio.h>

// 循环时给数组赋值
int mainT4() {

    // 定义数组
    int arr[4];

    int *arrP = arr;
    int i = 0;
    for (i = 0; i < 4; ++i) {
        // 通过指针给变量赋值
        *(arrP + i) = 100 + i;
    }

    // 打印数组中的值
    int j = 0;
    for (j = 0; j < 4; ++j) {
        printf("arr[%d] = %d\n", j, arr[j]);
    }

    return 0;
}
