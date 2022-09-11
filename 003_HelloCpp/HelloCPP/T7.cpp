#include <iostream>
#include "student.h"

using namespace std;

// C++面向对象
// 规范写法，要有头文件 .h/.hpp 和实现文件.c/.cpp
int main() {
    // 栈空间创建对象；main函数执行完自动回收内存
    student student1;
    student1.setName("Clion");
    student1.setAge(10);
    cout << "name:" << student1.getName() << ",age:" << student1.getAge() << endl;

    // 堆空间创建对象；需手动回收内存
    student *student2 = new student();
    student2->setName("IDEA");
    student2->setAge(20);
    cout << "name:" << student2->getName() << ",age:" << student2->getAge() << endl;
    // 必须手动释放内存
    delete student2;

    return 0;
}