#include <stdio.h>

// 指针：即内存地址
int main() {

    // * 用于定义指针变量
    int sum = 100;
    // & 用于取址运算符
    int *pInt = &sum;
    printf("pInt:%p\n", pInt);
    // * 用于取值运算符
    printf("*pInt:%d\n", *pInt);
    // 通过指针修改变量的值
    *pInt = 200;
    printf("sum:%d\n", sum);

    // 指针与数组
    int array[3] = {1, 2, 3};
    printf("&array:%p\n", &array);
    printf("array:%p\n", array);
    printf("&(array[0]):%p\n", &(array[0]));

    // 指针与数组的区别：数组名是一个地址，而指针是一个左值
    // 左值：定位一个存储位置的标识符，一个左值一定是表示了一个内存地址

    return 0;
}
