#include <stdio.h>
#include "include/io_utils.h"

// 函数返回值，要经历2次拷贝
// 从当前调用栈，拷贝到寄存器：保存函数返回结果
// 从寄存器拷贝到调用方变量：函数返回结果赋值给调用方变量
int SumIntArray(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum;
}

// 将返回结果作为参数传入，只用拷贝1次
// 把函数结果直接赋值给变量的内存地址
void SumIntArray2(int array[], int length, int *sum) {
    *sum = 0;
    for (int i = 0; i < length; ++i) {
        *sum += array[i];
    }
}

// 指针参数作为返回值
// 1-避免函数返回值带来的开销
// 2-实现函数多个返回值的能力
int main() {
    int array[] = {0, 1, 2, 3, 4};
    int sum = SumIntArray(array, 5);

    int sum2;
    SumIntArray2(array, 5, &sum2);

    PRINT_INT(sum);
    PRINT_INT(sum2);
    return 0;
}
