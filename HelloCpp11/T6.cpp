#include <iostream>

class Person {
public:
    std::string name = "Person";
};

// C++ 类型转换，常量转换
// const_cast:const 修饰的都可以用 const_cast 来转换
int main() {
    const Person *p1 = new Person();
    // 常量指针，不允许修改值
    // p1->name = "CLion";
    // p1 为常量指针，将 p1 的地址赋值给 p2，并将 p2 转为非常量指针
    Person *p2 = const_cast<Person *>(p1);
    // 修改 p2 数据的值，同时也修改了 p1 的值
    p2->name = "CLion";
    std::cout << p1->name << std::endl;
    delete p1;
    p1 = nullptr;
    p2 = nullptr;
    return 0;
}
