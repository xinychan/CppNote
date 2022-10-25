#include <stdio.h>
#include "include/io_utils.h"

// 左值与右值
int main() {

    // 左值代表内存的空间
    // 右值代表要存入的值
    int a;
    a = 10;

    int *p = &a;
    *p = 20; // (*p = 20) == (a = 20)

    int array[4] = {0};
    int *arrayP = array;
    *(arrayP + 1) = 2;
    PRINT_INT_ARRAY(array, 4);
    return 0;
}
