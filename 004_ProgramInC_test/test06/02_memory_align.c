#include <stdio.h>
#include "include/io_utils.h"

// Test 结构体内存空间有浪费，对齐后占用 24 byte
// 对齐后计算内存：a+b=4;c=4;d=8;e=8;
typedef struct Test {
    char a; // 1 byte
    char b; // 1 byte
    int c; // 4 byte
    short d; // 2 byte
    double e; // 8 byte
} Test;

// Test2 结构体内存空间紧凑，对齐后占用 16 byte
// 对齐后计算内存：a+b+c=4;d=4;e=8;
// 内存优化规则：相同类型放到一起，占用内存小的优先放前面；
typedef struct Test2 {
    char a; // 1 byte
    char b; // 1 byte
    short c; // 2 byte
    int d; // 4 byte
    double e; // 8 byte
} Test2;

// 使用关键字，主动对齐
// pragma pack(2):按2byte为单位对齐，此关键字设置的对齐策略全局有效
#pragma pack(2)
typedef struct Test3 {
    char a; // 1 byte
    char b; // 1 byte
    int c; // 4 byte
    // 对单个属性设置对齐策略
    //__attribute((aligned(2))) int c; // gcc编译器有效
    // _Alignas(8) int c; // C11 标准的关键字
    short d; // 2 byte
    double e; // 8 byte
} Test3;

// 结构体的内存对齐
int main() {
    PRINT_INT(sizeof(struct Test)); // 24
    PRINT_INT(sizeof(struct Test2)); // 16
    PRINT_INT(sizeof(struct Test3)); // 16
    return 0;
}
