#include <iostream>
#include <set>
#include <algorithm>

// 自定义仿函数；仿函数扩展性较强，复杂逻辑使用仿函数
class ShowAction {
public:
    int count = 0;

    void showCount() {
        std::cout << "ShowAction showCount:" << count << std::endl;
    }

    // 重载括号运算符
    void operator()(int content) {
        std::cout << "ShowAction content:" << content << std::endl;
        count++;
    }
};

// 回调函数；回调函数功能简单，简单逻辑使用回调函数
void showActionFunc(int content) {
    std::cout << "showActionFunc content:" << content << std::endl;
}

// 仿函数，和回调函数
// 仿函数扩展性较强，复杂逻辑使用仿函数
// 回调函数功能简单，简单逻辑使用回调函数
int main() {
    // 通过仿函数，和回调函数，作为参数迭代遍历
    std::set<int> setVar;
    setVar.insert(10);
    setVar.insert(20);
    setVar.insert(30);
    setVar.insert(40);
    // 仿函数迭代遍历
    // 仿函数直接使用
    std::for_each(setVar.begin(), setVar.end(), ShowAction());
    // 仿函数复杂使用
    ShowAction showActionObj;
    showActionObj = std::for_each(setVar.begin(), setVar.end(), showActionObj);
    showActionObj.showCount();
    // 回调函数迭代遍历
    std::for_each(setVar.begin(), setVar.end(), showActionFunc);
    return 0;
}
