#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct Cat2 {
    char *name;
    int age;
};

// 结构体指针和动态内存开辟
int main() {

    // 结构体动态内存开辟
    // VS 写法：Cat2 *cat = (Cat2 *)malloc(sizeof(Cat2));
    struct Cat2 *cat = malloc(sizeof(struct Cat2));
    cat->name = "Cat2";
    cat->age = 5;
    printf("name:%s - age:%d \n", cat->name, cat->age);

    // 释放堆区内存
    free(cat);
    cat = NULL;

    return 0;
}
