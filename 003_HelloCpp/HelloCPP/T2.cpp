#include <iostream>

using namespace std;

// C与C++ 常量的区别
// C语言的常量，不是真的常量，可以通过指针的方式修改
// C++语言的常量，是真的常量，不可以修改
int main() {
    const int num = 100;
    int *pNum = const_cast<int *>(&num);
    *pNum = 10000; // 修改无效
    cout << "num:" << num << endl; // 仍是 100
    return 0;
}