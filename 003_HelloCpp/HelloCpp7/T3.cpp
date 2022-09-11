// C++ SLT：标准模板库
// SLT = 容器（Containers）+ 算法（Algorithms）+ 迭代器（iterators）
// JAVA 中有集合框架；C++ 有 SLT 标准模板库

#include <iostream>
#include <queue>

// SLT 中的容器
// queue 队列：先进先出
int main() {
    std::queue<int> queueVar;
    // push 入队/添加元素
    queueVar.push(10);
    queueVar.push(20);
    queueVar.push(30);
    queueVar.push(40);
    // pop 出队/删除元素
    while (!queueVar.empty()) {
        int num = queueVar.front();
        std::cout << num << std::endl;
        queueVar.pop();
    }
    return 0;
}
