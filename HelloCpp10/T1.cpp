#include <iostream>

// 通过指针，互换数据
void changeNumber(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

// 通过引用，互换数据
// 引用的本质就是指针
void changeNumber2(int &n1, int &n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

class Test {
private:
    std::string info = "Test-info";
public:
    // getInfo() 中的 (this->info) 和 (返回值string)，是值传递；地址是不同的
    // getInfo() 中的返回值修改了，不影响 (this->info)
    std::string getInfo() {
        return this->info;
    }

    // getInfoTrue() 中的 (this->info) 和 (返回值string)，是地址传递；地址是相同的
    // getInfo() 中的返回值修改了，(this->info)也会修改
    std::string &getInfoTrue() {
        return this->info;
    }
};

// 引用进阶
int main() {
    // 互换数据，通过指针和引用
    int n1 = 100;
    int n2 = 200;
    changeNumber(&n1, &n2);
    std::cout << n1 << ":" << n2 << std::endl;
    changeNumber2(n1, n2);
    std::cout << n1 << ":" << n2 << std::endl;

    // 函数返回值的引用传递
    Test test;
    test.getInfo() = "getInfo";
    std::string getInfoResult = test.getInfo();
    std::cout << "getInfoResult:" << getInfoResult << std::endl;
    test.getInfoTrue() = "getInfoTrue";
    std::string getInfoTrueResult = test.getInfoTrue();
    std::cout << "getInfoTrueResult:" << getInfoTrueResult << std::endl;
    return 0;
}
