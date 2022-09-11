#include <iostream>

using namespace std;

class Test {
private:
    int x;
    int y;
public:
    // 构造函数
    Test(int x, int y) : x(x), y(y) {}

    // set/get函数
    void setX(int x) {
        this->x = x;
    }

    int getX() {
        return this->x;
    }

    void setY(int y) {
        this->y = y;
    }

    int getY() {
        return this->y;
    }

    // 类内运算符重载
    // 简易写法
//    Test operator+(Test newTest) {
//        int x = this->getX() + newTest.getX();
//        int y = this->getY() + newTest.getY();
//        return Test(x, y);
//    }
    // 源码写法
    // 使用常量引用，不允许修改对象的值，只能读取值，更安全
    // 使用引用，提高性能；引用时不会创新的内存地址
    Test operator+(const Test &newTest) {
        int x = this->getX() + newTest.x;
        int y = this->getY() + newTest.y;
        return Test(x, y);
    }

    Test operator-(const Test &newTest) {
        int x = this->getX() - newTest.x;
        int y = this->getY() - newTest.y;
        return Test(x, y);
    }

    // ++对象 运算符重载
    void operator++() {
        this->x = this->x + 1;
        this->y = this->y + 1;
    }

    // 对象++ 运算符重载
    void operator++(int) {
        this->x = this->x + 1;
        this->y = this->y + 1;
    }
};

// 类外运算符重载
//Test operator+(Test test1, Test test2) {
//    int x = test1.getX() + test2.getX();
//    int y = test1.getY() + test2.getY();
//    Test test(x, y);
//    return test;
//}

// 运算符重载
int main() {
    Test test1(10, 20);
    Test test2(30, 40);
    // 运算符重载
    Test test3 = test1 + test2;
    cout << test3.getX() << ":" << test3.getY() << endl;
    test3++;
    cout << test3.getX() << ":" << test3.getY() << endl;
    ++test3;
    cout << test3.getX() << ":" << test3.getY() << endl;
    return 0;
}
