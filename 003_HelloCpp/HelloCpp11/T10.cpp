#include <iostream>

void show(int *pInt) {
    std::cout << "show(int *pInt)" << std::endl;
}

void show(int i) {
    std::cout << "show(int i)" << std::endl;
}

// nullptr 的使用
// C++11 特性，替代 NULL，也可以用来作为指针传递
int main() {
    show(100);
    show(nullptr);
    return 0;
}
