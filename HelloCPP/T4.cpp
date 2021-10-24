#include <iostream>

using namespace std;

// 定义结构体
typedef struct {
    char name[20];
    int age;
} Student;

// 常量引用：传入的数据不允许修改
// 插入数据库
void insertStudent(const Student &student) {
    // 未使用常量引用，可以修改数据
    // student.age = 10;
    // 使用常量引用，数据仅可读
    cout << student.age << endl;
}

// C++ 的常量引用
int main() {
    Student student = {"Clion", 20};
    insertStudent(student);
    return 0;
}