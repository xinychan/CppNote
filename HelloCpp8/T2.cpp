#include <iostream>
#include <map>

// multimap 容器：key可以重复，且key重复的数据可以分组
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::multimap<int, std::string> multimapVar;
    // 插入数据
    multimapVar.insert(std::make_pair(10, "101"));
    multimapVar.insert(std::make_pair(10, "102"));
    multimapVar.insert(std::make_pair(10, "103"));

    multimapVar.insert(std::make_pair(20, "201"));
    multimapVar.insert(std::make_pair(20, "202"));
    multimapVar.insert(std::make_pair(20, "203"));

    multimapVar.insert(std::make_pair(30, "301"));
    multimapVar.insert(std::make_pair(30, "302"));
    multimapVar.insert(std::make_pair(30, "303"));

    // 迭代器，循环遍历
    for (std::multimap<int, std::string>::iterator iterator = multimapVar.begin();
         iterator != multimapVar.end(); iterator++) {
        std::cout << iterator->first << ":" << iterator->second << std::endl;
    }
    std::cout << "===" << std::endl;

    // 分组功能
    std::multimap<int, std::string>::iterator iterator = multimapVar.find(20);
    while (iterator != multimapVar.end()) {
        std::cout << iterator->first << ":" << iterator->second << std::endl;
        iterator++;
        if (iterator->first != 20) {
            break;
        }
    }
    return 0;
}
