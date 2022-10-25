#include <stdio.h>

// 函数的原型；只声明函数，不实现
// 1-函数名称
// 2-函数返回值类型，如果没写返回值，默认为 int
// 3-函数参数列表；如果没写，可以传任意参数；如果不需要传参，参数写 void
void Function();

// 默认返回 int；不需要传参
Function2(void);

// 函数的原型
int main() {
    Function();
    Function(1, 2, 3);
    Function2();
    return 0;
}

// 函数的实现
void Function() {
    printf("Function\n");
}

// 函数的实现
Function2(void) {
    printf("Function2\n");
    return 0;
}
