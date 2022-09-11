#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// 匿名结构体定义别名；系统源码写法
typedef struct {
    char *name;
    int age;
} Human;

// 匿名结构体定义别名
int main() {

    // 直接匿名结构体定义别名后，VS/CLION 统一写法
    Human human = {"human1", 1};
    printf("name:%s - age:%d \n", human.name, human.age);

    Human *humanp = malloc(sizeof(Human));
    humanp->name = "human2";
    humanp->age = 2;
    printf("name:%s - age:%d \n", humanp->name, humanp->age);
    free(humanp);
    humanp = NULL;
    return 0;
}
