// C++ SLT：标准模板库
// SLT = 容器（Containers）+ 算法（Algorithms）+ 迭代器（iterators）
// JAVA 中有集合框架；C++ 有 SLT 标准模板库

#include <iostream>
#include <list>

// SLT 中的容器
// list 列表：内部使用链表实现
int main() {
    // list 初始化
    std::list<int> listVar;
    // 插入数据
    listVar.push_front(10);
    listVar.push_back(20);
    listVar.insert(listVar.begin(), 30);
    listVar.insert(listVar.end(), 40);
    // 使用迭代器，循环遍历
    for (std::list<int>::iterator iterator = listVar.begin(); iterator != listVar.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }
    std::cout << "===" << std::endl;
    // 修改数据
    listVar.front() = 100;
    listVar.back() = 200;
    for (auto iterator = listVar.begin(); iterator != listVar.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }
    std::cout << "===" << std::endl;
    // 删除数据
    listVar.erase(listVar.begin());
    // listVar.erase(listVar.end()); // 直接删除 listVar.end()，会越界报错
    auto end = listVar.end();
    end--;
    listVar.erase(end); // 删除最后一个元素
    for (auto iterator = listVar.begin(); iterator != listVar.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }
    return 0;
}
