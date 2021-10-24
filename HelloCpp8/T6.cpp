#include <iostream>

// 自定义预定义函数
template<typename T>
struct myPlus {
    T operator()(const T &x, const T &y) {
        return x + y;
    }
};

// C++预定义函数（C++内置函数）
int main() {
    // 计算："Clion" + "IDEA"，需要运算符重载
    // 简易方式：使用预定义函数
    std::plus<int> addFunc;
    int sum = addFunc(1, 2);
    std::cout << sum << std::endl;

    std::plus<std::string> addFunc2;
    std::string strSum = addFunc2("Clion", "IDEA");
    std::cout << strSum << std::endl;

    // 使用自定义预定义函数；若对象相加，则需要自定义仿函数
    myPlus<std::string> addFunc3;
    std::string addStr = addFunc3("Clion", "Java");
    std::cout << addStr << std::endl;
    return 0;
}