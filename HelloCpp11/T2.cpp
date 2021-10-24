#include <iostream>
#include <memory>

class Person2;

// Person1 和 Person2 互相依赖
class Person1 {
public:
    // 持有 Person2 的智能指针
    std::shared_ptr<Person2> person2;

    Person1() {
        std::cout << "Person1()" << std::endl;
    }

    ~Person1() {
        std::cout << "~Person1()" << std::endl;
    }
};

class Person2 {
public:
    // 持有 Person1 的智能指针
    std::shared_ptr<Person1> person1;

    Person2() {
        std::cout << "Person2()" << std::endl;
    }

    ~Person2() {
        std::cout << "~Person2()" << std::endl;
    }
};

// C++ 智能指针的循环依赖问题
int main() {
    std::cout << "main start" << std::endl;
    Person1 *p1 = new Person1();
    Person2 *p2 = new Person2();
    std::shared_ptr<Person1> sharedPtr1(p1);
    std::shared_ptr<Person2> sharedPtr2(p2);
    // 统计引用计数；use_count = 1
    std::cout << "A-sharedPtr1 use_count:" << sharedPtr1.use_count() << std::endl;
    std::cout << "A-sharedPtr2 use_count:" << sharedPtr2.use_count() << std::endl;
    // 给各自的智能指针赋值；引用计数再+1，不会减1清零，导致不会释放对象
    p1->person2 = sharedPtr2;
    p2->person1 = sharedPtr1;
    // 再统计引用计数；use_count = 2
    std::cout << "B-sharedPtr1 use_count:" << sharedPtr1.use_count() << std::endl;
    std::cout << "B-sharedPtr2 use_count:" << sharedPtr2.use_count() << std::endl;
    std::cout << "main end" << std::endl;
    return 0;
}
