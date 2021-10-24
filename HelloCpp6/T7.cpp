#include <iostream>

// 普通函数，当函数名相同但参数不同时，需要重载
void addAction(int x, int y) {
    std::cout << "addAction int" << std::endl;
}

void addAction(float x, float y) {
    std::cout << "addAction float" << std::endl;
}

void addAction(double x, double y) {
    std::cout << "addAction double" << std::endl;
}

// 模板函数；使用 template 声明类型，调用时可传入任意类型
template<typename T>
void addAction(T x, T y) {
    std::cout << "addAction template<typename T>" << std::endl;
}

// C++ 模板函数；相当于 Java 的泛型
int main() {
    addAction(1, 1);
    addAction(1.0f, 1.0f);
    addAction(1.0, 1.0);
    addAction("", "");
    return 0;
}
