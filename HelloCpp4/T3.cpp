#include <iostream>

using namespace std;

class Person {
private:
    int age = 0;

public:
    Person(int age) {
        this->age = age;
    }

    int getAge() {
        return this->age;
    }

    // 定义友元函数（先声明，后实现）
    friend void updateAgeByFriend(Person *person, int age);
};

// 友元函数，可以访问类中私有变量
void updateAgeByFriend(Person *person, int age) {
    person->age = age;
}

// 普通函数，无法访问类中私有变量
void updateAge(Person *person, int age) {
    // person->age = age;
}

// 友元函数
int main() {
    Person person = Person(10);
    updateAge(&person, 20);
    updateAgeByFriend(&person, 15);
    cout << person.getAge() << endl;
    return 0;
}
