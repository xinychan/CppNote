#include <stdio.h>
#include "include/io_utils.h"

// 指针的运算
int main() {
    // 指针的移动
    int array[] = {0, 1, 2, 3, 4};
    int *p = array;
    PRINT_INT(array[3]);
    PRINT_INT(p[3]);
    PRINT_INT(*(array + 3));
    PRINT_INT(*(p + 3));
    // 指针的比较
    PRINT_BOOL(p + 3 > p + 1);
    return 0;
}
