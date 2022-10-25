#include <stdio.h>
#include "include/io_utils.h"

/**
 * 数组求和
 * @param rows 2维数组的1层长度
 * @param columns 2维数组的2层长度
 * @param array 传入的2维数组
 * @param result 返回的结果数组
 */
void SumIntArray(int rows, int columns, int array[][columns], int result[]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i] += array[i][j];
        }
    }
}

// 2维数组
int main() {
    int array[3][2] = {
            {1, 1},
            {2, 2},
            {3, 3}
    };
    // 函数若需要返回数组结果，可以通过调用者传入一个数组作为结果
    int result[3] = {0};
    SumIntArray(3, 2, array, result);
    PRINT_INT_ARRAY(result, 3);
    return 0;
}
