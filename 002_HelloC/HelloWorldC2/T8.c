#include <stdio.h>

void callBackFunc(char *fileName, int current, int total) {
    printf("%s progress : %d / %d \n", fileName, current, total);
}

// 压缩方法
// 定义函数指针：返回值（*函数名）（函数参数）
void compress(void(*callBackP)(char *, int, int), char *fileName, int current, int total) {
    // 使用 callBackP 与 (*callBackP) 是等价的
    //callBackP(fileName, current, total); // 回调给外界，压缩的进度情况
    (*callBackP)(fileName, current, total); // 回调给外界，压缩的进度情况
}

// 函数指针2；函数的结果回调
// 可将函数赋值给函数指针，然后函数指针作为参数传入
int main() {
    // 不规范写法：函数指针未声明直接赋值；Linux环境下会报错
    void (*call)(char *, int, int) = callBackFunc;
    compress(call, "CLion.png", 5, 100);

    // 规范写法：函数指针先声明，再赋值
    void (*call2)(char *, int, int);
    call2 = callBackFunc;
    compress(call2, "CLion2.png", 10, 100);

    // 直接使用回调函数
    compress(callBackFunc, "CLion3.png", 20, 100);

    return 0;
}

