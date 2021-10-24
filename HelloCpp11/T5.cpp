#include <iostream>
#include <memory>
#include "MyPtr.h"

class Person {
public:
    Person() {
        std::cout << "Person()" << std::endl;
    }

    ~Person() {
        std::cout << "~Person()" << std::endl;
    }
};

// C++ 内置智能指针
void actionSharedPtr() {
    Person *p1 = new Person();
    Person *p2 = new Person();
    // 智能指针第1种使用情况
    // std::shared_ptr<Person> sharedPtr1(p1);
    // std::shared_ptr<Person> sharedPtr2(p2);
    // 智能指针第2种使用情况
    // std::shared_ptr<Person> sharedPtr1(p1);
    // std::shared_ptr<Person> sharedPtr2 = sharedPtr1;
    // 智能指针第3种使用情况
    // std::shared_ptr<Person> sharedPtr1(p1);
    // std::shared_ptr<Person> sharedPtr2;
    // sharedPtr2 = sharedPtr1;
    // 智能指针第4种使用情况
    std::shared_ptr<Person> sharedPtr1(p1);
    std::shared_ptr<Person> sharedPtr2(p2);
    sharedPtr2 = sharedPtr1;
    std::cout << "actionSharedPtr sharedPtr1:" << sharedPtr1.use_count() << std::endl;
    std::cout << "actionSharedPtr sharedPtr2:" << sharedPtr2.use_count() << std::endl;
}

// 自定义智能指针
void actionMyPtr() {
    Person *p1 = new Person();
    Person *p2 = new Person();
    // 智能指针第1种使用情况
    // Ptr<Person> ptr1(p1);
    // Ptr<Person> ptr2(p2);
    // 智能指针第2种使用情况
    // Ptr<Person> ptr1(p1);
    // Ptr<Person> ptr2 = ptr1;
    // 智能指针第3种使用情况
    // Ptr<Person> ptr1(p1);
    // Ptr<Person> ptr2;
    // ptr2 = ptr1;
    // 智能指针第4种使用情况
    Ptr<Person> ptr1(p1);
    Ptr<Person> ptr2(p2);
    // 原来的 ptr2 已经有指向地址，现在指向新地址后，要把原来的指向数据删除
    // =号运算符重载中有处理
    ptr2 = ptr1;
    std::cout << "actionMyPtr ptr1:" << ptr1.use_count() << std::endl;
    std::cout << "actionMyPtr ptr2:" << ptr2.use_count() << std::endl;
}

// 手写智能指针，实现 shared_ptr 效果
int main() {
    std::cout << "main start" << std::endl;
    actionSharedPtr();
    std::cout << "======" << std::endl;
    actionMyPtr();
    std::cout << "main end" << std::endl;
    return 0;
}
