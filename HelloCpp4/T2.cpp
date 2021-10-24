#include <iostream>

using namespace std;

class Student {
public:
    char *name;
    int age;

    // 静态变量，先声明，再实现
    static int id;

    // 静态函数；通过 Student:: 调用
    static void staticUpdateId() {
        id = 100;
        // 静态函数不可以调用非静态变量和非静态函数
        // age = 10;
        // updateId();
    }

    // 普通函数
    void updateId() {
        id = 200;
    }

    // 函数中默认持有隐式的this【Student * const this】
    // 隐式的this是【指针常量】，只能修改指向地址的值，不能修改指向的地址
    void showInfo() {
        this->age = 20; // this【指针常量】，只能修改指向地址的值
        // this = 0x666666; // this【指针常量】，不能修改指向的地址
    }

    // 函数中默认持有隐式的this【Student * const this】
    // 函数使用 const 修饰后，原来的this变成了【const Student * const this】
    // 隐式的this变成了【常量指针常量】，不能修改指向地址的值，也不能修改指向的地址
    // const 函数中的 this 信息，只能读取，不能修改
    void showInfoConst() const {
        // this->age = 20; // this【常量指针常量】，不能修改指向地址的值
        // this = 0x666666; // this【常量指针常量】，不能修改指向的地址
    }
};

// 静态变量的实现
int Student::id = 10;

// 静态关键字 static
/*
 * 1-静态变量和静态函数，通过【类名::静态成员】调用
 * 2-静态变量必须先声明，再实现
 * 3-静态函数只能调用静态变量和静态函数
 */
int main() {
    Student student;
    cout << Student::id << endl;
    student.updateId();
    cout << Student::id << endl;
    // 静态函数的调用
    Student::staticUpdateId();
    cout << Student::id << endl;
    return 0;
}
