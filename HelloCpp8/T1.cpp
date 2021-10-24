#include <iostream>
#include <map>

// map 容器
int main() {
    // map 初始化
    std::map<int, std::string> mapVar;
    // 添加数据
    // 用 insert 方式添加数据，如果key已经存在，则 insert 方式无效
    mapVar.insert(std::pair<int, std::string>(1, "001"));
    mapVar.insert(std::make_pair(2, "002"));
    mapVar.insert(std::map<int, std::string>::value_type(3, "003"));
    // key已经存在，再次 insert 无效
    mapVar.insert(std::map<int, std::string>::value_type(3, "0030"));
    // 用 map[key]=value 方式添加数据；如果key已经存在，新增的数据会替换原数据
    mapVar[4] = "004";
    mapVar[4] = "0040";
    // 迭代器，循环遍历
    for (std::map<int, std::string>::iterator iterator = mapVar.begin(); iterator != mapVar.end(); iterator++) {
        std::cout << iterator->first << ":" << iterator->second << std::endl;
    }
    // 插入结果判断
    std::pair<std::map<int, std::string>::iterator, bool> result = mapVar.insert(std::make_pair(3, "300"));
    if (result.second) {
        std::cout << "insert succ" << std::endl;
    } else {
        std::cout << "insert fail" << std::endl;
    }
    // 查找
    std::map<int, std::string>::iterator findResult = mapVar.find(4);
    if (findResult != mapVar.end()) {
        std::cout << findResult->first << ":" << findResult->second << std::endl;
    }
    return 0;
}
