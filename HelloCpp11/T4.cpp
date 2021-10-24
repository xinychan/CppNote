#include <iostream>
#include <memory>

class Person {
};

// 使用 unique_ptr 智能指针
// unique_ptr 智能指针智能独占，不能被其他 unique_ptr 赋值
int main() {
    Person *p1 = new Person();
    Person *p2 = new Person();
    std::unique_ptr<Person> uniquePtr1(p1);
    // unique_ptr 不可以被其他 unique_ptr 赋值
    // std::unique_ptr<Person> uniquePtr2 = uniquePtr1;
    std::unique_ptr<Person> uniquePtr2(p2);
    // shared_ptr 可以被其他 shared_ptr 赋值
    std::shared_ptr<Person> sharedPtr1(p1);
    std::shared_ptr<Person> sharedPtr2 = sharedPtr1;
    return 0;
}
