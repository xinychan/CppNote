#include <istream>
#include "People.h"

using namespace std;

// 实现静态属性
int People::id = 100;

// 实现构造函数
People::People() {}

People::People(char *name) {}

People::People(char *name, int age) {}

// 实现析构函数
People::~People() {}

// 实现拷贝构造函数
People::People(const People &people) {}

// 实现普通函数
int People::getAge() {}

char *People::getName() {}

void People::setAge(int age) {}

void People::setName(char *name) {}

// 实现 const 函数
void People::showInfo() const {}

// 实现静态函数
void People::changeAgeByStatic(int age) {}

// 实现友元函数
void changeAgeByFriend(People *people, int age) {}
