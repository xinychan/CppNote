#include <stdio.h>

void showNum(int);

void showPNum(int *);

void showArray(int[]);

// 值传递；传入的参数会使用新的内存地址做运算
void showNum(int x) {
    // showNum 中的 x 和 main 中的 x 不是同一个地址
    x = 10;
    printf("showNum:x = %d\n", x); // 10
}

// 地址传递；传入的参数使用同一个内存地址做运算
void showPNum(int *y) {
    // showPNum 中的 y 和 main 中的 y 同一个地址
    *y = 10;
    printf("showPNum:y = %d\n", *y); // 10
}

// 传数组参数；数组参数会被优化成指针
void showArray(int arr[5]) {
    // showArray:arr sizeof = 8
    printf("showArray:arr sizeof = %d\n", sizeof(arr));
}

// 函数与指针
int main() {
    // 传值和传地址
    int x = 100;
    showNum(x); // 传给 showNum 中的 x 和 main 中的 x 不是同一个地址
    printf("main:x = %d\n", x); // 100
    int y = 100;
    showPNum(&y); // 传给 showPNum 中的 y 和 main 中的 y 同一个地址
    printf("main:y = %d\n", y); // 10

    // 传数组参数
    int arr[5] = {1, 2, 3, 4, 5};
    // main:arr sizeof = 20
    printf("main:arr sizeof = %d\n", sizeof(arr));
    showArray(arr);

    return 0;
}
