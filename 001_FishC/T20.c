#include <stdio.h>

void addFunc();

void addFunc2();

void addFunc3();

void addIndex();

// 全局变量；若全局变量未初始化，自动初始化为0
int count = 0;

void addFunc() {
    count++;
}

void addFunc2() {
    count++;
}

void addFunc3() {
    count++;
}

// 使用 extern 关键字；告诉编译器变量在函数之后有声明，或者在其他文件中有声明
void addIndex() {
    // extern 可实现跨函数，或者跨文件使用同一变量
    extern int indexNum;
    indexNum++;
}

// 变量声明在函数调用之后，使用 extern 关键字
int indexNum = 10;

// 局部变量和全局变量
int main() {
    addFunc();
    addFunc2();
    addFunc3();
    printf("count1:%d\n", count);
    for (int count = 0; count < 10; count++) {
        // 局部变量与全局变量同名时，作用域内只影响局部变量
        printf("for count:%d\n", count);
    }
    printf("count2:%d\n", count);

    // extern 关键字使用
    addIndex();
    printf("indexNum:%d\n", indexNum);
    return 0;
}