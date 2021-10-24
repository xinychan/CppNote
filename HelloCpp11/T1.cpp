#include <iostream>
#include <memory>

class Person {
public:
    int age;

    Person() {
        std::cout << "Person()" << std::endl;
    }

    ~Person() {
        std::cout << "~Person()" << std::endl;
    }
};

// C++ 智能指针
int main() {
    std::cout << "main start" << std::endl;
    // 堆区开辟内存，必须释放
    Person *person = new Person();
    // 手动释放；会立即执行析构函数
    // delete person;
    // 通过智能指针释放堆区开辟的内存；会在对象没有再被引用时自动调用析构函数
    std::shared_ptr<Person> sharedPtr(person);
    person->age = 10;
    std::cout << "person age:" << person->age << std::endl;

    std::cout << "main end" << std::endl;
    return 0;
}
