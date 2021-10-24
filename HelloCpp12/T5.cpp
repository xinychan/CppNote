#include <iostream>
#include <exception>

// 抛出异常的函数；通过 throw 抛出异常
void exceptionMethod1() {
    // 抛出 const char * 类型异常
    throw "exceptionMethod1 error";
}

class Student {
public:
    char *showInfo() {
        return "showInfo";
    }
};

// 抛出异常的函数；通过 throw 抛出异常
void exceptionMethod2() {
    // 抛出自定义类
    Student student;
    throw student;
}

// 自定义异常类；继承 exception 类，重写 what() 函数
class MyException : public std::exception {
public:
    // what() 是异常类提供的一个公共方法，它已被所有子异常类重载，返回异常产生的原因
    const char *what() const noexcept override {
        return "MyException error";
    }
};

// 抛出异常的函数；抛出自定义异常
void exceptionMethod3() {
    throw MyException();
}


// C++ 异常
int main() {

    // 捕获异常
    try {
        exceptionMethod1();
    } catch (const char *msg) {
        std::cout << "catch1 :" << msg << std::endl;
    }

    // 捕获自定义类
    try {
        exceptionMethod2();
    } catch (Student &student) {
        std::cout << "catch2 :" << student.showInfo() << std::endl;
    }

    // 捕获自定义异常
    try {
        exceptionMethod3();
    } catch (MyException &myException) {
        std::cout << "catch3 :" << myException.what() << std::endl;
    }
    return 0;
}
