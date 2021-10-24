#include <stdio.h>

// 声明函数
void change(int i);

// C语言不支持函数重载，所以函数名不能重复；Java和C++支持函数重载
void changeValue(int *i);

// 通过函数，修改值
int mainT7() {
    int i = 100;
    change(i);
    printf("main i == %d\n", i); // 100
    printf("main &i == %p\n", &i);
    changeValue(&i);
    printf("main i == %d\n", i); // 200
    printf("main &i == %p\n", &i);
    return 0;
}

// C语言是从上往下执行，函数必须在main之前声明或定义
//void swapValue() {}

// 实现已经声明的函数
void change(int i) {
    i = 200;
    printf("swapValue i == %d\n", i); // 200
    printf("swapValue &i == %p\n", &i);
    // C/C++ 编译器构建的形参，是一个新的变量；
    // change函数中的i变量，与main函数中的i变量，不是同一个变量，内存地址不同
    // 在change中修改i变量的值，不影响main中的i变量
}

void changeValue(int *i) {
    // 通过指针修改变量的值
    *i = 200;
    printf("changeValue *i == %d\n", *i);
    printf("changeValue &i == %p\n", i);
};

