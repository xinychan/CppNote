#ifndef PEOPLE_H
#define PEOPLE_H

class People {
private:
    char *name;
    int age;

public:
    // 静态成员
    static int id;

    // 构造函数
    People();

    People(char *);

    People(char *, int);

    // 析构函数
    ~People();

    // 拷贝构造函数
    People(const People &people);

    int getAge();

    char *getName();

    void setAge(int);

    void setName(char *);

    // const 修饰的函数
    void showInfo() const;

    // 静态函数
    static void changeAgeByStatic(int);

    // 友元函数
    friend void changeAgeByFriend(People *, int);

};

#endif //PEOPLE_H
