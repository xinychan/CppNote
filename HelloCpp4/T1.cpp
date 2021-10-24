#include <iostream>
#include <cstdarg> // 可变参数支持库

using namespace std;

// C++ 可变参数
void sum(int count, ...) {
    va_list vaList; // 可变参数列表
    // va_start：开始可变参数
    va_start(vaList, count);
    // va_arg：访问下一个可变函数实参
    int i;
    for (i = 0; i < count; i++) {
        int number = va_arg(vaList, int);
        cout << number << endl;
    }
    // va_end：结束对可变函数实参的遍历
    va_end(vaList);
}

// 可变参数
int main() {

    sum(4, 1, 2, 3, 4);

    return 0;
}
