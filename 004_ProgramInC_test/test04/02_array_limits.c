#include <stdio.h>
#include "include/io_utils.h"

// 数组
int main() {
    int array[3] = {0, 1, 2};
    // 数组越界了，不会报错，但会获取到错误的值
    PRINT_INT(array[5]);
    return 0;
}
