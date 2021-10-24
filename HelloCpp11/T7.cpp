#include <iostream>

class FuClass {
public:
    void show() {
        std::cout << "FuClass show" << std::endl;
    }
};

class ZiClass : public FuClass {
public:
    void show() {
        std::cout << "ZiClass show" << std::endl;
    }
};

// C++ 类型转换，静态转换；静态转换作用在编译期
// static_cast:指针操作都可以用 static_cast 来转换
int main() {
    // 指针的转换
    int n = 100;
    void *pVoid = &n;
    int *number = static_cast<int *>(pVoid);
    std::cout << *number << std::endl;

    // 父类子类的转换
    FuClass *fuClass = new FuClass;
    fuClass->show(); // 执行父类函数
    ZiClass *ziClass = static_cast<ZiClass *>(fuClass);
    ziClass->show(); // 执行子类函数
    delete fuClass; // 回收规则：谁 new 就释放谁
    fuClass = nullptr;
    ziClass = nullptr;
    return 0;
}
