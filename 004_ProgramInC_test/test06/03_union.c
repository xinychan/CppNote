#include <stdio.h>
#include "include/io_utils.h"

// 结构体的每个字段都有自己独立的内存空间
// 联合体的内存由所有字段共享
union Test {
    // Test 联合体总计占用 8 byte
    int int_test; // 4 byte
    double double_test; // 8 byte
    char *string_test; // 8 byte
};

// 在定义联合体时，同时定义类型别名，简化联合体调用
typedef union Test2 {
    // Test2 联合体总计占用 8 byte
    int int_test; // 4 byte
    double double_test; // 8 byte
    char *string_test; // 8 byte
} Test2;

// 联合体
int main() {
    PRINT_INT(sizeof(union Test)); // 8
    PRINT_INT(sizeof(Test2)); // 8

    Test2 test2;
    test2.int_test = 1;
    test2.double_test = 2.0;
    // int_test 值被 double_test 覆盖；只有 double_test 赋值有效
    PRINT_INT(test2.int_test); // 0
    PRINT_DOUBLE(test2.double_test); // 2
    return 0;
}
