#include <iostream>

using namespace std;

// 无形参名：为了方便后面扩展功能，让调用方多传一个没有参数名的参数
// 后续修改函数时，可以直接修改函数源码，而不用修改调用方
void addFunc(int num1, int num2, int) {
}

// 无形参名的特殊写法
int main() {
    addFunc(1, 2, 3);
    return 0;
}