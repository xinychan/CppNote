#include <iostream>

using namespace std;

class Student {

public:
    // 无参构造函数
    Student() {
        cout << "Student public" << endl;
    }

    // 构造函数
    Student(char *name, int age) : name(name), age(age) {
        cout << "Student name + age" << endl;
    }

    // 析构函数；当对象被回收时调用，可以进行一些释放工作
    ~Student() {
        cout << "~Student" << endl;
    }

    // 拷贝构造函数：默认有拷贝构造函数，用于 (对象1 = 对象2) 赋值操作
    // 重写拷贝构造函数，会替换原有的拷贝构造函数，需要重写所有成员变量的赋值操作
    Student(const Student &student) {
        // 传来的 Student 是常量引用，只读不可修改
        cout << "Student copy" << endl;
        this->name = student.name;
        this->age = student.age + 100;
    }

// 私有属性
private:
    char *name;
    int age;

// 公开的其他函数
public:
    char *getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }

    void setName(char *name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }
};

// 拷贝构造函数
int main() {
    Student student1("CLion", 10);
    cout << "name:" << student1.getName() << ",age:" << student1.getAge() << endl;
    // 声明并直接赋值，会执行重写的拷贝构造函数
    Student student2 = student1;
    cout << "name:" << student2.getName() << ",age:" << student2.getAge() << endl;
    // 先声明，后再赋值，不执行重写的拷贝构造函数
    // 执行普通构造函数，以及默认的拷贝构造函数
    Student student3;
    student3 = student1;
    cout << "name:" << student3.getName() << ",age:" << student3.getAge() << endl;

    // 使用指针方式，不会执行拷贝构造函数，因为没有拷贝行为，只是指针的指向，不属于对象间的赋值
    Student *studentP = new Student("IDEA", 20);
    Student *studentP2 = studentP;
    cout << "name:" << studentP2->getName() << ",age:" << studentP2->getAge() << endl;
    delete studentP;
    delete studentP2;

    return 0;
}
