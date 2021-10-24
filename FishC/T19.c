#include <stdio.h>

char *getName(char);

int getResult(int);

int add(int, int);

int sub(int, int);

int calc(int (*)(int, int), int, int);

int (*getCalc(int))(int, int);

// 指针函数：使用指针变量作为函数返回值
char *getName(char tag) {
    char result[] = "AAA";
    switch (tag) {
        case 'A':
            // return result; // 不能返回局部变量的指针；局部变量仅当前函数生效
            return "AAA";
        case 'B':
            return "BBB";
        default:
            return "default";
    }
}

// 函数指针；指向函数的指针
int getResult(int num) {
    return num + num;
}

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

// 函数指针作为参数使用
int calc(int (*pFunc)(int, int), int x, int y) {
    return (*pFunc)(x, y);
}

// 函数指针作为返回值
int (*getCalc(int index))(int, int) {
    if (index >= 0) {
        return add;
    } else {
        return sub;
    }
}

// 指针函数与函数指针
int main() {
    // 指针函数使用
    char tag = 'A';
    printf("getName:tag A = %s\n", getName(tag));
    tag = 'B';
    printf("getName:tag B = %s\n", getName(tag));
    tag = 'C';
    printf("getName:tag C = %s\n", getName(tag));

    // 函数指针使用
    int (*pFunc)(int); // 函数指针
    pFunc = getResult; // 将指针指向对应的函数
    printf("pFunc:%d\n", (*pFunc)(10));

    // 函数指针作为参数使用
    int addRes = calc(add, 5, 3);
    printf("addRes:%d\n", addRes);
    int subRes = calc(sub, 5, 3);
    printf("subRes:%d\n", subRes);

    // 函数指针作为返回值
    int index = 1;
    int (*getCalcFunc)(int);
    getCalcFunc = (int (*)(int)) getCalc(index); // 返回值为函数指针
    int getCalcFuncAddResult = calc(getCalcFunc, 10, 10);
    printf("getCalcFunc:%d\n", getCalcFuncAddResult);

    int index2 = -1;
    int (*getCalcFunc2)(int);
    getCalcFunc2 = (int (*)(int)) getCalc(index2); // 返回值为函数指针
    int getCalcFuncSubResult = calc(getCalcFunc2, 10, 5);
    printf("getCalcFunc2:%d\n", getCalcFuncSubResult);
    return 0;
}
