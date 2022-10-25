#include <stdio.h>
#include "include/io_utils.h"

// 定义结构体
struct Person {
    char *name;
    int age;
    char *id;
};

// 给结构体定义类型别名，简化结构体调用
typedef struct Person Person;

// 在定义结构体时，同时定义类型别名，更进一步简化结构体调用
typedef struct People {
    char *name;
    int age;
    char *id;
} People;

// 复杂类型结构体
typedef struct Company {
    char *name;
    char *id;
} Company;

typedef struct MyPerson {
    char *name;
    int age;
    char *id;
    // 嵌套结构体指针
    Company *company1;
    // 嵌套结构体
    Company company2;
    // 嵌套结构体
    struct {
        char *extra_str;
    } extra_value;
    // 嵌套自身结构体
    struct MyPerson *other;
} MyPerson;

// 结构体
int main() {

    // 结构体初始化；初始化列表
    struct Person person = {"name", 0, "123456"};
    // 结构体成员选择运算符，调用结构体成员
    PRINT_INT(person.age);
    person.age = 10;
    PRINT_INT(person.age);

    // 结构体也是指向一个内存地址，首地址就是第一个成员的地址
    // 性质类比数组；数组首地址就是第一个元素的地址
    // 数组可以直接作为指针使用，结构体也可以直接作为指针使用
    PRINT_HEX(&person);

    // 结构体指针
    struct Person *person_ptr = &person;
    // 结构体指针成员选择运算符，调用结构体成员
    PRINT_INT(person_ptr->age);
    person_ptr->age = 20;
    PRINT_INT(person_ptr->age);

    // 结构体占用内存大小
    PRINT_INT(sizeof(struct Person));

    // 简化结构体调用
    Person person1 = {"name1", 10, "654321"};
    PRINT_INT(person1.age);

    // 更进一步简化结构体调用
    People people = {"people", 20, "123456"};
    PRINT_INT(people.age);

    // 复杂结构体调用
    Company company = {.name="company1", .id="666"};
    MyPerson myPerson = {.name="myPerson", .age=15, .id="123465", &company,
            .company2={"company2", "777"}, .extra_value="value"};
    myPerson.company1->name = "aaa";
    myPerson.company2.name = "bbb";
    myPerson.extra_value.extra_str = "extra_str";
    PRINT_STRING(myPerson.company1->name);
    PRINT_STRING(myPerson.company2.name);
    PRINT_STRING(myPerson.extra_value.extra_str);
    PRINT_INT(myPerson.age);

    return 0;
}
