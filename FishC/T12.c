#include <stdio.h>

// 指针数组与数组指针
int main() {

    // 指针数组
    int a = 1;
    int a2 = 2;
    int a3 = 3;
    int a4 = 4;
    int a5 = 5;
    int *p1[5] = {&a, &a2, &a3, &a4, &a5}; // 存储5个 (int *)
    int i;
    for (i = 0; i < 5; i++) {
        printf("int:%d\n", *p1[i]);
    }

    char *p2[5] = {"Hello", "World", "Clion", "Java", "Python"};
    for (i = 0; i < 5; i++) {
        printf("char:%s\n", p2[i]);
    }

    // 数组指针：一个指针指向了数组，即为数组指针
    int temp[5] = {1, 2, 3, 4, 5};
    int *p3 = temp;
    int (*p4)[5] = &temp;
    for (i = 0; i < 5; i++) {
        printf("temp:%d\n", *(p3 + i));
        printf("temp2:%d\n", *(*p4 + i));
    }
    return 0;
}
