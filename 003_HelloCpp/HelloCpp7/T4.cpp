// C++ SLT：标准模板库
// SLT = 容器（Containers）+ 算法（Algorithms）+ 迭代器（iterators）
// JAVA 中有集合框架；C++ 有 SLT 标准模板库

#include <iostream>
#include <queue>
#include <vector>

// SLT 中的容器
// 优先级队列：内部对 vector 有一定的封装
int main() {

    // 简易写法，默认从小到大排序
    // std::priority_queue<int> priorityQueue; 等价于 std::priority_queue<int, std::vector<int>, std::less<>> priorityQueue;
    // 声明从大到小排序
    std::priority_queue<int, std::vector<int>, std::greater<>> priorityQueue;
    priorityQueue.push(10);
    priorityQueue.push(20);
    priorityQueue.push(30);
    priorityQueue.push(40);

    while (!priorityQueue.empty()) {
        int num = priorityQueue.top();
        std::cout << num << std::endl;
        priorityQueue.pop();
    }

    return 0;
}
