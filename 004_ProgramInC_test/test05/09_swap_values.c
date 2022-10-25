#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/io_utils.h"

// 此处函数的形参都是自动类型变量，生命周期仅在函数栈中有效
// 即参数传来时，在函数栈中会新创建内存空间，存放这两边变量进行计算
// 函数执行完后，这两个变量的内存空间被释放，对调用者实际传来的实参没有任何影响
void SwapInt(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 要交换两参数的值，需要将参数的指针传入
void SwapInt2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 交换参数值，通用写法
// 传入要交换值的参数的指针，以及参数类型的长度
void Swap(void *x, void *y, size_t size) {
    void *temp = malloc(size);
    if (temp) {
        memcpy(temp, x, size);
        memcpy(x, y, size);
        memcpy(y, temp, size);
        free(temp);
    }
}

// 交换参数值，宏写法
#define SWAP(x, y, type){ type temp = x; x = y; y = temp;}
// 此写法适用于将宏作为判断条件嵌套在代码中执行
// 这样嵌套在代码中语法不会报错，且只执行一次
#define SWAP2(x, y, type) do { type temp = x; x = y; y = temp;} while (0)

// 交换两个变量的值
int main() {
    int a = 10;
    int b = 20;

    SwapInt2(&a, &b);
    PRINT_INT(a);
    PRINT_INT(b);

    double x = 3.0;
    double y = 5.0;

    Swap(&x, &y, sizeof(double));
    PRINT_DOUBLE(x);
    PRINT_DOUBLE(y);

    SWAP(a, b, int);
    PRINT_INT(a);
    PRINT_INT(b);

    SWAP(x, y, double);
    PRINT_DOUBLE(x);
    PRINT_DOUBLE(y);

    return 0;
}
