#include <stdio.h>

// 获取字符串长度
int getStrLen(char *string) {
    int count = 0;
    while (*string) { // *string != ‘\0’ 就一直循环
        string++;
        count++;
    }
    return count;
}

// C/C++ 编译器，当数组作为参数传递，会把数组优化成指针（为了提高效率）
// 所以在函数中 sizeof(arrInt) = 4 or 8（在不同的操作系统及编译环境中，指针类型占用的字节数是不同的）
int getIntLen(int arrInt[]) {
    // 数组作为参数传递，就不能正确获取数组的大小
    int count = sizeof(arrInt) / sizeof(int); // count = 2
    printf("getIntLen = %d\n", count);
}

// resultLen 为返回值
int getIntLen2(int *resultLen, int arrInt[]) {
    // 指针挪动计算长度
    int count = 0;
    // 指针挪动时，数组要遇到 0 or '\0 才会停止指针；所以若数组中有 0 会干扰指针挪动结果
    while (*arrInt) {
        arrInt++;
        count++;
    }
    *resultLen = count;
}

// 指针挪动获取字符串信息
int main() {

    // 计算字符串长度
    char str[] = {'a', 'b', 'c', '\0'};
    int strlen = getStrLen(str);
    printf("strlen = %d\n", strlen); // strlen = 3

    // 计算数组长度
    int arrInt[] = {1, 2, 0, 4, '\0'}; // 指针挪动时，数组也要遇到 0 or '\0 才会停止指针
    int count = sizeof(arrInt) / sizeof(int);
    printf("arrInt = %d\n", count); // count = 5
    getIntLen(arrInt); // 当数组作为参数传递时，会被优化成指针

    // 计算数组长度2
    int result;
    getIntLen2(&result, arrInt);
    // int arrInt[] = {1, 2, 3, 4, '\0'} 时 result = 4
    // int arrInt[] = {1, 2, 0, 4, '\0'} 时 result = 2
    printf("result = %d\n", result);


    return 0;
}
