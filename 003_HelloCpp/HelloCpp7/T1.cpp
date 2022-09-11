// C++ SLT：标准模板库
// SLT = 容器（Containers）+ 算法（Algorithms）+ 迭代器（iterators）
// JAVA 中有集合框架；C++ 有 SLT 标准模板库

#include <iostream>
#include <vector>

// SLT 中的容器
// vector 向量：内部实现，封装动态大小的数组
int main() {

    // vector 初始化
    std::vector<int> vector1;
    std::vector<int> vector2(10); // 指定10个空间大小
    std::vector<int> vector3(10, 0); // 指定10个空间大小，且都赋值为0

    std::vector<int> vector4;
    // insert 插入数据
    // vector4.begin() 迭代器，插入数据到前面
    // vector4.end() 迭代器，插入数据到后面
    vector4.insert(vector4.begin(), 10);
    vector4.insert(vector4.begin(), 20);
    vector4.insert(vector4.begin(), 30);
    vector4.insert(vector4.begin(), 40);
    // vector4.front() 获取第一个元素
    // vector4.back() 获取最后一个元素
    std::cout << vector4.front() << std::endl;
    std::cout << vector4.back() << std::endl;
    vector4.front() = 100;
    std::cout << vector4.front() << std::endl;
    // erase 移除数据
    vector4.erase(vector4.begin());
    // 普通for循环打印
    for (int i = 0; i < vector4.size(); i++) {
        std::cout << vector4[i] << std::endl;
    }
    // 迭代器循环打印
    // for (std::vector<int>::iterator iterator = vector4.begin(); iterator != vector4.end(); iterator++) {
    // 使用 auto 自动推断类型
    for (auto iterator = vector4.begin(); iterator != vector4.end(); iterator++) {
        // 取出迭代器读取地址的值
        std::cout << *iterator << std::endl;
    }
    return 0;
}
