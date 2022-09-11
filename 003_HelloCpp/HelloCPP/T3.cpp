#include <iostream>

using namespace std;

// C/C++互换两个数的不同方式

// 通过地址的方式来互换；适用于C和C++
void numberChange(int *n1, int *n2) {
    int temp = 0;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

// 通过引用的方式来互换；仅适用C++
void numberChange2(int &n1, int &n2) {
    // 不使用引用，numberChange2 函数中与 main 函数中的 n1/n2 参数地址不同
    // 使用引用，numberChange2 函数中与 main 函数中的 n1/n2 参数地址相同
    int temp = 0;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

// C++ 的引用和引用的原理
int main() {
    int n1 = 10;
    int n2 = 20;
    // 通过地址的方式来互换
    //numberChange(&n1, &n2);
    // 通过引用的方式来互换
    numberChange2(n1, n2);
    cout << "n1:" << n1 << ",n2:" << n2 << endl;

    // 引用的原理
    // 不使用引用，仅仅是值传递，内存地址仍然不同；一个变量修改值，不影响其他变量
    int index1 = 100;
    int index2 = index1;
    cout << &index1 << "---" << &index2 << endl;
    index2 = 200;
    cout << index1 << "---" << index2 << endl;

    // 使用引用，变量共享内存地址；一个变量修改值，其余变量都修改
    int index3 = 100;
    int &index4 = index3;
    cout << &index3 << "===" << &index4 << endl;
    index4 = 200;
    cout << index3 << "===" << index4 << endl;
    return 0;
}