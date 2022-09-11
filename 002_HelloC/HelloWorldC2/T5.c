#include <stdio.h>

// 数组指针操作的几种方式
int mainT5() {

    // 定义数组
    int arr[] = {1, 2, 3, 4};

    int *arrP = arr;

    int i = 0;
    for (i = 0; i < 4; ++i) {
        printf("arr[i] = %d\n", arrP[i]);
        printf("*(arr + i) = %d\n", *(arrP + i));
    }
    return 0;
}