#include <iostream>

// 宏变量
#define VALUE_INT 100
#define VALUE_STR "CLion"

// 宏函数
#define SHOW(TXT) std::cout << TXT << std::endl;
#define ADD(x, y) x+y

// 复杂宏函数
#define LOGIN(V) if(V==1){              \
std::cout << "LOGIN succ" << std::endl; \
} else {                                \
std::cout << "LOGIN fail" << std::endl; \
} // 结尾不需要加"\"

int main() {
    // 不论是宏变量，还是宏函数，在预处理阶段，宏会直接完成文本替换工作

    // 宏变量
    int num = VALUE_INT; // 等价于 int num = 100;
    std::string name = VALUE_STR; // 等价于 string name = "CLion";

    // 宏函数
    SHOW("CLion");
    int sum = ADD(10, 10);
    std::cout << "sum:" << sum << std::endl;

    // 复杂宏函数
    LOGIN(1);
    LOGIN(0);
    LOGIN(1);
    LOGIN(0);

    /**
     * 宏函数优点：
     * 直接文本替换，不会造成函数的调用开销
     * 普通函数需要开辟栈空间，形参先入栈，然后出栈释放形参
     * 宏函数缺点：
     * 直接文本替换，导致代码体积增大
     */
    return 0;
}
