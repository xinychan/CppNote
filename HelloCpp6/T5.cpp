#include <iostream>

class Student {
public:
    int id;
    std::string name;
    int age;
};

// 全纯虚函数：类中所有的函数，都是纯虚函数；类就相当于 Java 中的接口
class IStudentDB {
public:
    virtual void insertStudent(Student student) = 0;

    virtual void deleteStudent(Student student) = 0;

    virtual void updateStudent(Student student) = 0;

    virtual void queryStudent(int id) = 0;
};

// 全纯虚函数的实现类
class StudentDBImpl : public IStudentDB {
    void insertStudent(Student student) {}

    void deleteStudent(Student student) {}

    void updateStudent(Student student) {}

    void queryStudent(int id) {}
};

// C++ 全纯虚函数；相当于 Java 的接口
int main() {
    StudentDBImpl studentDbImpl;
    return 0;
}
