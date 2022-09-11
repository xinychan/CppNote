#include <iostream>
#include <set>
#include <algorithm>

// 自定义仿函数
class TestFunc {
public:
    // 重载括号运算符
    void operator()() {
        std::cout << "TestFunc operator()" << std::endl;
    }
};

// 谓词 == 仿函数
int main() {
    // 仿函数；类的调用很想函数的调用
    TestFunc testFunc;
    testFunc();
    return 0;
}
