#include <iostream>

using namespace std;

// 父类
class Person {
public:
    char *name;
    int age;
public:
    Person(char *name, int age) : name(name), age(age) {
        cout << "Person(char *name, int age)" << endl;
    }

    void showInfo() {
        cout << this->name << ":" << this->age << endl;
    }
};

// 子类继承父类；C++默认私有继承(private Person)
// 私有继承，只能在子类内部调用父类中的公开变量与函数
// 必须公开继承，才能在子类外部调用父类中的公开变量与函数
class Student : public Person {
public:
    // 子类构造函数，必须调用父类构造函数
    Student(char *name, int age) : Person(name, age) {
        cout << "Student(char *name, int age)" << endl;
    }

    void show() {
        showInfo();
    }
};

// C++ 对象继承
int main() {
    Student student("CLion", 10);
    // 公开继承，子类在外部才能调用父类中的公开变量与函数
    student.age;
    student.showInfo();
    return 0;
}
