#include <stdio.h>
#include "include/io_utils.h"

// 全局变量
int global_array[10];

// 数组
int main() {
    // 局部变量
    int array[10];
    for (int i = 0; i < 10; ++i) {
        // array[i] = i;
        // PRINT_INT(array[i]); // 局部变量，不赋初始值，会有野值
        PRINT_INT(global_array[i]); // 全局变量，有默认值为0
    }

    // 定义数组并初始化
    int array2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; ++i) {
        PRINT_INT(array2[i]);
    }

    // 指定数组某位置元素的值；C99 开始支持这个语法
    int array3[5] = {[2] = 10, 0, 1};
    for (int i = 0; i < 5; ++i) {
        PRINT_INT(array3[i]);
    }
    return 0;
}
