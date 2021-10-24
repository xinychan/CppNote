#include <iostream>
#include <set>

class Person {
public:
    std::string name;
    int id;

    Person(std::string name, int id) : name(name), id(id) {}
};

// 自定义谓词，给 set 容器中的对象排序
struct doCompareLess {
    bool operator()(const Person &person1, const Person &person2) {
        return person1.id < person2.id;
    }
};

struct doCompareGreater {
    bool operator()(const Person &person1, const Person &person2) {
        return person1.id > person2.id;
    }
};

// C++ 谓词
int main() {
    // set 容器默认会排序，但系统源码的谓词，无法给对象排序，需要自定义谓词
    // std::set<Person, doCompareLess> setVar; // 从小到大排序
    std::set<Person, doCompareGreater> setVar; // 从大到小排序
    Person p1("Clion1", 1);
    Person p2("Clion2", 2);
    Person p3("Clion3", 3);
    Person p4("Clion4", 4);
    setVar.insert(p1);
    setVar.insert(p2);
    setVar.insert(p3);
    setVar.insert(p4);
    for (std::set<Person>::iterator iterator = setVar.begin(); iterator != setVar.end(); iterator++) {
        std::cout << iterator->id << std::endl;
        std::cout << iterator->name.c_str() << std::endl;
    }
    return 0;
}
