// C++ SLT：标准模板库
// SLT = 容器（Containers）+ 算法（Algorithms）+ 迭代器（iterators）
// JAVA 中有集合框架；C++ 有 SLT 标准模板库

#include <iostream>
#include <set>

// SLT 中的容器
// set 容器：内部使用红黑树实现，会对数据进行排序，但不允许有重复数据
int main() {
    // set 初始化；默认排序，从小到大 less
    // std::set<int, std::less<>> setVar;
    std::set<int> setVar;
    setVar.insert(10);
    setVar.insert(20);
    setVar.insert(30);
    setVar.insert(40);
    // 重复插入，插入失败但不报错，返回值封装在 std::pair 中
    std::pair<std::set<int>::iterator, bool> result = setVar.insert(10);
    if (result.second) {
        std::cout << "insert succ" << std::endl;
    } else {
        std::cout << "insert fail" << std::endl;
    }
    // 迭代器，循环遍历
    for (std::set<int>::iterator iterator = setVar.begin(); iterator != setVar.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }
    return 0;
}
