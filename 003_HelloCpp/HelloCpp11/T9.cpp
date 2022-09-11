#include <iostream>

class MyData {
public:
    void show() {
        std::cout << "MyData show" << std::endl;
    }
};

// C++ 类型转换，强制转换
// reinterpret_cast:强制转换，static_cast 能做的，reinterpret_cast 都可以做
int main() {
    MyData *myData = new MyData;
    // 本地编译环境的原因，会报错：error: cast from 'MyData*' to 'long int' loses precision
    // 本地环境只能转成 long long，不能转成 long
    // long dataValue = reinterpret_cast<long>(myData);
    // 把对象变成数值
    long long dataValue = reinterpret_cast<long long>(myData);
    // 把数值还原成对象
    MyData *myData2 = reinterpret_cast<MyData *>(dataValue);
    myData2->show();

    // myData == myData2:指针指向相同的地址
    std::cout << "myData:" << myData << std::endl;
    std::cout << "myData2:" << myData2 << std::endl;

    // &myData != &myData2:指针自己的地址，不相同
    std::cout << "&myData:" << &myData << std::endl;
    std::cout << "&myData2:" << &myData2 << std::endl;
    return 0;
}
