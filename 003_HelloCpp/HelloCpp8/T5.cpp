#include <iostream>
#include <set>

// 自定义仿函数
class CompareString {
public:
    bool operator()(const std::string &x, const std::string &y) const {
        return x > y;
    }
};

// 类型传递的仿函数
int main() {
    std::set<std::string, CompareString> setVar;
    setVar.insert("AAA");
    setVar.insert("BBB");
    setVar.insert("CCC");
    setVar.insert("DDD");

    for (std::set<std::string, CompareString>::iterator iterator = setVar.begin();
         iterator != setVar.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }
    return 0;
}
