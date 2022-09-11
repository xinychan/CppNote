#include "student.h"

// 根据"student.h"头文件，完成具体实现
// cpp 实现文件必须在 CMake 中引用，否则无法编译
// h 头文件可以不在 CMake 中引用，不影响编译

void student::setAge(int age) {
    // C++对象指向指针，调用对象成员相当于指针调用
    this->age = age;
}

void student::setName(char *name) {
    this->name = name;
}

int student::getAge() {
    return this->age;
}

char *student::getName() {
    return this->name;
}