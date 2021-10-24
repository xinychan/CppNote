#include <iostream>
#include <string.h>

using namespace std;

class Student {
public:
    char *name;
    int age;

    // 构造函数
    Student() {
        cout << "Student()" << endl;
    };

    Student(char *name) : Student(name, 20) {
        cout << "Student(char *name)" << endl;
    };

    Student(char *name, int age) {
        cout << "Student(char *name, int age)" << endl;
        this->name = (char *) (malloc(sizeof(char *) * 10));
        strcpy(this->name, name);
        this->age = age;
    };

    // 析构函数
    ~Student() {
        cout << "~Student()" << endl;
        // 在浅拷贝下，在析构函数中释放变量地址，会导致重复释放；
        // 在 VS 环境中会报错，CLion 优化了报错
        free(this->name);
        this->name = NULL;
    }

    // 拷贝构造函数
    Student(const Student &student) {
        // C++默认的拷贝构造函数，是浅拷贝
        // 如果有堆区成员变量（如字符串），必须使用深拷贝，否则会重复 free 同一个变量地址，引发崩溃
        cout << "Student(const Student &student):" << &student << ",this:" << this << endl;
        // 浅拷贝；新地址name = 旧地址name
        // 浅拷贝；新地址name 和 旧地址name 指向同一个内存空间，会重复 free 同一个变量地址，引发崩溃
        // this->name = student.name;
        // this->age = student.age;

        // 深拷贝：新地址name 和 旧地址name 都有各自内存空间，不会重复 free 同一个变量地址，避免崩溃
        this->name = (char *) (malloc(sizeof(char *) * 10));
        this->age = student.age;
    }

};

Student getStudent(char *name) {
    Student student(name);
    cout << "getStudent():" << &student << endl;
    return student;
}

void showStudent(Student student) {
    cout << "showStudent():" << &student << endl;
}

// 深拷贝与浅拷贝及其原理
int main() {
    // 如下代码，只打印一次构造函数，赋值操作调用的是拷贝构造函数
    Student s1; // 无参构造函数
    Student s2 = s1; // 拷贝构造函数
    // Student(const Student &student):0x167c3ffde0,this:0x167c3ffdd0
    cout << &s1 << endl;
    cout << &s2 << endl;
    cout << "======" << endl;

    // 打印结果
//    Student(char *name, int age)
//    Student(char *name)
//    getStudent():0x167c3ffdc0
//    (VS环境上会执行拷贝构造函数) Student(const Student &student):0x******,this:0x******
//    main():0x167c3ffdc0 (VS环境上会执行拷贝构造函数，且 getStudent() 中地址与 main() 地址不同)
//    ~Student()
    Student student = getStudent("CLion");
    cout << "main():" << &student << endl;
    cout << "======" << endl;

    // 打印结果
//    Student(char *name, int age)
//    Student(const Student &student):0x27e9ffc10,this:0x27e9ffc50
//    showStudent():0x27e9ffc50
//    ~Student()
//    Student(const Student &student):0x27e9ffc10,this:0x27e9ffc60
//    showStudent():0x27e9ffc60
//    ~Student()
    Student student2("IDEA", 20);
    showStudent(student2);
    showStudent(student2);

    return 0;
}
