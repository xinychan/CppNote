#include <iostream>
#include <algorithm>
#include <vector>

// for_each 调用的仿函数
class ForeachFunc {
public:
    void operator()(const int content) {
        std::cout << "ForeachFunc:" << content << std::endl;
    }
};

// transform 调用的仿函数
class TransformFunc {
public:
    int operator()(const int content) {
        return content + 100;
    }
};

// find_if 调用的仿函数
class FindifFunc {
public:
    int number;

    FindifFunc(int number) : number(number) {}

    bool operator()(const int content) {
        return number == content;
    }
};

// 算法包常用函数，以及其仿函数
int main() {
    // 初始化数据
    std::vector<int> vectorVar;
    vectorVar.insert(vectorVar.begin(), 10);
    vectorVar.insert(vectorVar.begin(), 20);
    vectorVar.insert(vectorVar.begin(), 30);
    vectorVar.insert(vectorVar.begin(), 40);
    vectorVar.insert(vectorVar.begin(), 50);
    vectorVar.insert(vectorVar.begin(), 60);
    vectorVar.insert(vectorVar.begin(), 10);

    // for_each 遍历
    std::for_each(vectorVar.begin(), vectorVar.end(), ForeachFunc());

    // transform 转换
    std::vector<int> vectorTransform;
    vectorTransform.resize(vectorVar.size());
    std::transform(vectorVar.begin(), vectorVar.end(), vectorTransform.begin(), TransformFunc());
    for (auto iterator = vectorTransform.begin(); iterator != vectorTransform.end(); iterator++) {
        std::cout << "transform:" << *iterator << std::endl;
    }

    // find 查找，find 不需要自定义仿函数
    auto findIterator = std::find(vectorVar.begin(), vectorVar.end(), 60);
    if (findIterator != vectorVar.end()) {
        std::cout << "findIterator succ" << std::endl;
    } else {
        std::cout << "findIterator fail" << std::endl;
    }

    // find_if 查找；需要自定义仿函数
    auto findifIterator = std::find_if(vectorVar.begin(), vectorVar.end(), FindifFunc(20));
    if (findifIterator != vectorVar.end()) {
        std::cout << "findifIterator succ" << std::endl;
    } else {
        std::cout << "findifIterator fail" << std::endl;
    }

    // count 统计元素个数；不需要自定义仿函数
    int countResult = std::count(vectorVar.begin(), vectorVar.end(), 10);
    std::cout << "countResult:" << countResult << std::endl;

    // count_if 统计元素个数；需要自定义仿函数；也可使用系统自带的仿函数，来统计大于小于等于某条件的元素个数
    int countifResultLess = std::count_if(vectorVar.begin(), vectorVar.end(), std::bind2nd(std::less<int>(), 50));
    std::cout << "countifResultLess:" << countifResultLess << std::endl;
    int countifResultGreater = std::count_if(vectorVar.begin(), vectorVar.end(), std::bind2nd(std::greater<int>(), 50));
    std::cout << "countifResultGreater:" << countifResultGreater << std::endl;
    int countifResultEqual = std::count_if(vectorVar.begin(), vectorVar.end(), std::bind2nd(std::equal_to<int>(), 10));
    std::cout << "countifResultEqual:" << countifResultEqual << std::endl;

    // merge 合并；合并成一个容器
    std::vector<int> vectorVar2;
    vectorVar.insert(vectorVar.begin(), 1000);
    vectorVar.insert(vectorVar.begin(), 2000);
    vectorVar.insert(vectorVar.begin(), 3000);
    std::vector<int> vectorMerge;
    vectorMerge.resize(vectorVar.size() + vectorVar2.size());
    std::merge(vectorVar.begin(), vectorVar.end(),
               vectorVar2.begin(), vectorVar2.end(),
               vectorMerge.begin());
    for (auto iterator = vectorMerge.begin(); iterator != vectorMerge.end(); iterator++) {
        std::cout << "vectorMerge:" << *iterator << std::endl;
    }

    // sort 排序；需要自定义仿函数；也可使用系统自带的仿函数
    // 从大到小排序
    std::sort(vectorVar.begin(), vectorVar.end(), std::greater<int>());
    for (auto iterator = vectorVar.begin(); iterator != vectorVar.end(); iterator++) {
        std::cout << "greater sort:" << *iterator << std::endl;
    }
    // 默认排序；从小到大排序
    std::sort(vectorVar.begin(), vectorVar.end());
    for (auto iterator = vectorVar.begin(); iterator != vectorVar.end(); iterator++) {
        std::cout << "default sort:" << *iterator << std::endl;
    }
    // 从小到大排序
    std::sort(vectorVar.begin(), vectorVar.end(), std::less<int>());
    for (auto iterator = vectorVar.begin(); iterator != vectorVar.end(); iterator++) {
        std::cout << "less sort:" << *iterator << std::endl;
    }

    // random_shuffle 打乱顺序
    std::random_shuffle(vectorVar.begin(), vectorVar.end());
    for (auto iterator = vectorVar.begin(); iterator != vectorVar.end(); iterator++) {
        std::cout << "random_shuffle:" << *iterator << std::endl;
    }

    // copy 拷贝；拷贝容器数据到另一个容器
    std::vector<int> vectorCopy;
    vectorCopy.resize(vectorVar.size());
    std::copy(vectorVar.begin(), vectorVar.end(), vectorCopy.begin());
    for (auto iterator = vectorCopy.begin(); iterator != vectorCopy.end(); iterator++) {
        std::cout << "vectorCopy:" << *iterator << std::endl;
    }

    // replace 替换
    std::replace(vectorVar.begin(), vectorVar.end(), 10, 11);
    for (auto iterator = vectorVar.begin(); iterator != vectorVar.end(); iterator++) {
        std::cout << "replace:" << *iterator << std::endl;
    }
    return 0;
}
