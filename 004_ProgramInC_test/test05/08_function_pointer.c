#include <stdio.h>
#include <stdlib.h>
#include "include/io_utils.h"

void InitPointer2(int **ptr, int length, int default_value) {
    *ptr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        (*ptr)[i] = default_value;
    }
}

// f1 = 普通函数，参数为(int, int)，返回值为int*
int *f1(int, int);
// int *(f1(int, int));

// f2 = 函数指针，参数为(int, int)，返回值为int
int (*f2)(int, int);

// 定义类型别名；定义函数指针，参数为(int, int)，返回值为int
typedef int (*Func)(int, int);

int Add(int x, int y) {
    return x + y;
}

// 定义 Boolean 类型别名，实际类型为int
typedef int Boolean;

// 定义 Intptr 类型别名，实际类型为指针 int*
typedef int *Intptr;

// 函数指针与typedef
int main() {
    // 打印函数的地址
    PRINT_HEX(&main);
    PRINT_HEX(&InitPointer2);

    int *p;
    // 函数的类型；赋值给函数指针
    void (*func)(int **ptr, int length, int default_value) = &InitPointer2;
    // 函数指针的调用，等价于函数的调用；四种调用方式等价
    InitPointer2(&p, 10, 0);
    (*InitPointer2)(&p, 10, 0);
    func(&p, 10, 0);
    (*func)(&p, 10, 0);
    PRINT_INT_ARRAY(p, 10);

    // 使用类型别名调用函数
    Func func1 = Add;
    func1(1, 1);
    Add(1, 1);

    return 0;
}
