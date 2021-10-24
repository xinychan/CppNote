#include <iostream>
#include <set>
#include <algorithm>

// 函数适配器
int main() {
    std::set<std::string> setVar;
    setVar.insert("aaa");
    setVar.insert("bbb");
    setVar.insert("ccc");

    for (std::set<std::string>::iterator iterator = setVar.begin(); iterator != setVar.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }

    // find_if 查找数据
    // equal_to 比较数据函数，接受两个参数
    // bind1st 函数适配器；将传入的参数传给被适配的函数中第1个参数
    // bind2nd 函数适配器；将传入的参数传给被适配的函数中第2个参数
    std::set<std::string>::iterator findResult =
            std::find_if(setVar.begin(), setVar.end(), std::bind2nd(std::equal_to<std::string>(), "ccc"));
    if (findResult != setVar.end()) {
        std::cout << "find succ" << std::endl;
    } else {
        std::cout << "find fail" << std::endl;
    }
    return 0;
}
