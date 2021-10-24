#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct Cat {
    char *name;
    int age;
};

// 结构体指针和动态内存开辟
int main() {

    // 结构体
    struct Cat cat = {"Cat1", 2};
    printf("name:%s - age:%d \n", cat.name, cat.age);
    // 结构体指针
    //  VS 写法：Cat *catp = &cat;
    struct Cat *catp = &cat;
    catp->name = "catp";
    catp->age = 3;
    printf("name:%s - age:%d \n", catp->name, catp->age);

    return 0;
}
