#include <stdio.h>

// 多重指针
int main() {

    // 多重指针使用
    int num = 100;
    int *pNum = &num;
    int **ppNum = &pNum;
    // 获取地址
    printf("&num:%p\n", &num);
    printf("pNum:%p\n", pNum);
    printf("*ppNum:%p\n", *ppNum);
    // 地址的值
    printf("num:%d\n", num);
    printf("*pNum:%d\n", *pNum);
    printf("**ppNum:%d\n", **ppNum);

    // 多重指针数组
    char *langs[] = {"Cpp", "Java", "Kotlin", "Python"};
    char **pyName;
    char **langName[3];
    // 多重指针保存的是地址
    pyName = &langs[3];
    langName[0] = &langs[0];
    langName[1] = &langs[1];
    langName[2] = &langs[2];

    printf("*pyName:%s\n", *pyName);
    printf("*langName[0]:%s\n", *langName[0]);
    printf("*langName[1]:%s\n", *langName[1]);
    printf("*langName[2]:%s\n", *langName[2]);

    return 0;
}
