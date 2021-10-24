#include <iostream>

class Person {
protected:
    // std::string 是对 char* 的封装
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name(name), age(age) {}
};

class Book {
private:
    std::string name;
public:
    Book(std::string name) : name(name) {}
};

class Student : public Person {
private:
    // 若定义了对象成员，必须要在构造函数中把对象成员初始化
    Book book;
public:
    // book(myBook) // 初始化 book，通过传入 book 对象进行赋值
    // book(bookName) // 初始化 book，通过传入 book 构造函数所需参数，调用 book 构造函数
    Student(std::string name, int age, Book myBook, std::string bookName)
            : Person(name, age), book(bookName) {}
};

// 源码中属性初始化的方式
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
