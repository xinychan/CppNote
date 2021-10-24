#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct People {
    char *name;
    int age;
};

// 结构体定义别名
// VS 写法：typedef People;
typedef struct People People;

// 结构体指针定义别名
typedef struct People *PeopleP;

// 结构体与结构体指针，结构体别名
int main() {

    // 结构体定义别名后，VS/CLion 兼容写法
    People p1 = {"name1", 1};
    printf("name:%s - age:%d \n", p1.name, p1.age);
    // 结构体指针定义别名后，VS/CLion 兼容写法
    PeopleP pp = &p1;
    printf("name:%s - age:%d \n", pp->name, pp->age);
    PeopleP pp2 = malloc(sizeof(People));
    pp2->name = "name2";
    pp2->age = 2;
    printf("name:%s - age:%d \n", pp2->name, pp2->age);
    free(pp2);
    pp2 = NULL;

    return 0;
}
