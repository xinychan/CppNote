#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// 结构体；定义结构体时直接声明具体的结构体
struct Person {
    // 成员变量
    char *name;
    int age;
    char sex;
}
        person1 = {"P1", 10, 'M'},
        person2 = {"P2", 12, 'W'}, person3;

// 结构体的定义与使用2
int main() {
    printf("name:%s - age:%d - sex:%c \n", person1.name, person1.age, person1.sex);
    printf("name:%s - age:%d - sex:%c \n", person2.name, person2.age, person2.sex);

    // 给定义的结构体赋值
    person3.name = "P3";
    person3.age = 15;
    person3.sex = 'W';
    printf("name:%s - age:%d - sex:%c \n", person3.name, person3.age, person3.sex);
    return 0;
}
