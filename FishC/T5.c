#include <stdio.h>

// 算数运算符
int main() {

    // 常用算数运算符
    int num1 = 2 + 1;
    int num2 = 2 - 1;
    int num3 = 2 * 1;
    int num4 = 2 / 1;
    int num5 = 2 % 1; // 求余运算

    // 类型转换
    int n1 = 10;
    float n2 = 5.5f;
    float n3 = n1 + n2;
    printf("n3 :%f\n", n3); // n3 :15.500000
    // 强制类型转换
    int n4 = n1 + (int) n2;
    printf("n4 :%d\n", n4); // n4 :15

    return 0;
}
