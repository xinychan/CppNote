#include <stdio.h>
#include "include/io_utils.h"

/**
 * 数组求和
 * @param array 数组
 * @param length 数组长度
 * @return 数组之和
 */
int SumIntArray(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum;
}

// 函数的数组类型参数
// C 语言数组仅仅是数组首地址，不知道数组具体有多少个元素，需要调用方把数组长度传入
int main() {
    int array[5] = {1, 2, 3, 4, 5};
    PRINT_INT(SumIntArray(array, 5));
    int array2[6] = {1, 2, 3, 4, 5, 6};
    PRINT_INT(SumIntArray(array2, 6));
    return 0;
}
