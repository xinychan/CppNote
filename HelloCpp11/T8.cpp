#include <iostream>

class FuClass {
public:
    // 动态转换使用，父类必须使用虚函数
    virtual void show() {
        std::cout << "FuClass show" << std::endl;
    }
};

class ZiClass : public FuClass {
public:
    void show() {
        std::cout << "ZiClass show" << std::endl;
    }
};

// C++ 类型转换，动态转换；动态转换作用在运行期
// dynamic_cast:动态转换，必须使用虚函数
int main() {
    // 动态转换时，是在运行期，由于创建时是 new 的已经是父类对象，不能转换成子类
    // FuClass *fuClass = new FuClass;
    // 动态转换时，是在运行期，必须创建时是 new 的子类对象，才能转换成子类
    FuClass *fuClass = new ZiClass;
    ZiClass *ziClass = dynamic_cast<ZiClass *>(fuClass);
    // 动态转换有返回值，返回 null 则转换失败
    if (ziClass) {
        std::cout << "dynamic_cast succ" << std::endl;
        ziClass->show(); // 执行子类函数
    } else {
        std::cout << "dynamic_cast fail" << std::endl;
    }
    return 0;
}
