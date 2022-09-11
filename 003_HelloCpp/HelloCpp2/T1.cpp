#include <iostream>

// C++自带命名空间
using namespace std;

// 自定义命名空间
namespace myspace {
    int age = 20;
    char *name = "CLion";

    void show() {
        cout << "myspace" << endl;
    }
}

using namespace myspace;

// 命名空间嵌套
namespace myspace2 {
    namespace myspaceInner {
        namespace myspaceInner2 {
            void action() {
                cout << "myspaceInner2" << endl;
            }
        }
    }
}

// 自定义命名空间
int main() {
    // 使用自定义命名空间
    int num1 = myspace::age;
    int num2 = age;
    myspace::show();
    show();

    // 命名空间嵌套
    myspace2::myspaceInner::myspaceInner2::action();
    return 0;
}
