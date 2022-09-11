// C++ SLT：标准模板库
// SLT = 容器（Containers）+ 算法（Algorithms）+ 迭代器（iterators）
// JAVA 中有集合框架；C++ 有 SLT 标准模板库

#include <iostream>
#include <stack>

// SLT 中的容器
// stack 栈：先进后出
int main() {
    std::stack<int> stackVar;
    // push 压栈/添加元素
    stackVar.push(10);
    stackVar.push(20);
    stackVar.push(30);
    stackVar.push(40);
    // pop 出栈/删除元素
    while (!stackVar.empty()) {
        int num = stackVar.top();
        std::cout << num << std::endl;
        stackVar.pop();
    }
    return 0;
}
