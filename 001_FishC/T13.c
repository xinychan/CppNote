#include <stdio.h>

// void 指针和 NULL 指针
int main() {

    // void 指针 = 通用指针；可以指向任何类型的指针
    int num = 100;
    int *pInt = &num;
    char *pChar = "Hello";
    void *pVoid;

    // void 指针转换成任意类型指针
    pVoid = pInt;
    printf("pVoid:%p , pInt:%p\n", pVoid, pInt);
    printf("*pVoid:%d\n", *((int *) pVoid));
    pVoid = pChar;
    printf("pVoid:%p , pChar:%p\n", pVoid, pChar);
    printf("*pVoid:%s\n", (char *) pVoid);

    // NULL 指针：指针指向 NULL
    int *p1; // 野指针
    int *p2 = NULL; // NULL 指针；建议：对指针初始化为NULL，使用时做NULL判断
    printf("*p1:%d\n", *p1);
    if (p2 != NULL) { // 检查是否 NULL 指针；NULL 指针不允许使用*解引用，否则运行报错
        printf("*p2:%d\n", *p2);
    }

    return 0;
}
