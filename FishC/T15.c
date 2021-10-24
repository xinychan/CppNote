#include <stdio.h>

// 定义常量/宏定义
#define NUM 100

// 常量和指针
int main() {
    // #define 和 const 定义常量
    const int num = 100;
    printf("num:%d\n", num);
    // num = 99; // error: assignment of read-only variable 'num'
    int *pInt = &num;
    *pInt = 99;
    printf("*pInt:%d\n", *pInt);
    printf("num:%d\n", num); // 99；通过指针修改 const 常量的值

    int num1 = 200;
    const int num2 = 300;
    const int *pNum = &num2;
    // 常量指针，即指向常量的指针
    // 可以修改该指针的值
    // 然而，只能使用这样的指针来读取所指向的对象，但不能修改所指向的对象
    // 因此，指向常量的指针常常被称为只读指针（read-only pointer）
    // 所引用对象本身可以是常量，也可以不是常量
    pNum = &num1;
    // *pNum = 299; // error: assignment of read-only location '*pNum'
    printf("*pNum:%d\n", *pNum); // 200

    // 指针常量
    // 指针常量的值是指针，这个值因为是常量，所以不能被赋值。
    // 因为指针常量是一个常量，在声明的时候一定要给它赋初值。一旦赋值，以后这个常量再也不能指向别的地址
    int *const pNum2 = &num2;
    *pNum2 = 299;
    // pNum2 = &num1; // error: assignment of read-only variable 'pNum2'
    printf("*pNum2:%d\n", *pNum2); // 299
    printf("num2:%d\n", num2); // 299

    // 指向常量的常量指针
    // 不能修改指针的地址，也不能修改地址对应的值
    const int *const pNum3 = &num2;
    // pNum3 = &num1; //  error: assignment of read-only variable 'pNum3'
    // *pNum3 = 100; // error: assignment of read-only location '*pNum3'

    return 0;
}
