#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// 结构体；相当于Java中的类
struct Person {
    // 成员变量
    char name[10];
    int age;
    char sex;
}; // 结尾必须;

// 结构体的定义与使用1
int main() {
    struct Person person; // 未初始化，默认没有值，未赋值时打印的是系统值
    printf("name:%s - age:%d - sex:%c \n", person.name, person.age, person.sex);

    // 赋值操作
    // person.name = "Clion"; // 对字符串数组赋值要用 strcpy
    strcpy(person.name, "Clion");
    person.age = 10;
    person.sex = 'M';
    printf("name:%s - age:%d - sex:%c \n", person.name, person.age, person.sex);
    return 0;
}
