#include <iostream>

void add(int x, int y) {
    std::cout << "add int" << std::endl;
}

void add(float x, float y) {
    std::cout << "add float" << std::endl;
}

void add(double x, double y) {
    std::cout << "add double" << std::endl;
}

// 静态多态，函数重载
int main() {
    add(1, 1);
    add(1.0f, 1.0f);
    add(2.0, 2.0);
    return 0;
}
