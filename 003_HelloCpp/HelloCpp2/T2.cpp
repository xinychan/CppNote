#include <iostream>

using namespace std;

class Student {

// 构造函数
public:
    // 无参构造函数
    Student() {
        cout << "Student public" << endl;
    }

    // 构造函数
    Student(char *name) {
        cout << "Student name" << endl;
        this->name = name;
    }

    // 构造函数简易写法； : name(name) 等价于 this->name = name
//    Student(char *name) : name(name) {
//        cout << "Student name" << endl;
//    }

    // 构造函数
    Student(char *name, int age) {
        cout << "Student name + age" << endl;
        this->name = name;
        this->age = age;
    }

    // 析构函数；当对象被回收时调用，可以进行一些释放工作
    // delete 调用时，析构函数会执行；C语言中的 free 函数调用，不会执行析构函数
    // 函数出栈时，析构函数会执行
    ~Student() {
        // Java 中 finalize() 函数类似析构函数作用，finalize 方法在 GC（垃圾回收器）决定回收一个不被其他对象引用的对象时调用
        cout << "~Student" << endl;
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

// 构造函数与析构函数
int main() {
    // 栈区创建对象
    Student student;
    student.setName("CLion");
    student.setAge(10);
    cout << "name:" << student.getName() << ",age:" << student.getAge() << endl;

    Student student1("IDEA", 20);
    cout << "name:" << student1.getName() << ",age:" << student1.getAge() << endl;

    // 堆区创建对象；需要手动释放内存
    Student *student2 = new Student("CLion2", 18);
    cout << "name:" << student2->getName() << ",age:" << student2->getAge() << endl;
    delete student2;

    return 0;
}
