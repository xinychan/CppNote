#include <iostream>

using namespace std;

// 1级父类
class BaseContext {
public:
    int index;

    void show() {
        cout << "BaseContext show" << endl;
    }
};

// 2级父类虚继承
class BaseActivity1 : virtual public BaseContext {
};

// 2级父类虚继承
class BaseActivity2 : virtual public BaseContext {
};

// 子类继承多个2级父类
class MainActivity : public BaseActivity1, public BaseActivity2 {
};

// C++ 虚继承
// 普通继承，会让2级父类拥有1级父类的变量和函数，子类若不重写，直接调用2级父类的变量和函数，会导致二义性
// 虚继承，会让所有直接或间接子类都持有1级父类的变量和函数，子类不需要重写，调用的都是自己类的变量和函数，没有二义性
int main() {
    BaseContext baseContext;
    BaseActivity1 baseActivity1;
    BaseActivity2 baseActivity2;
    MainActivity mainActivity;
    baseContext.index = 10;
    baseActivity1.index = 20;
    baseActivity2.index = 30;
    mainActivity.index = 40;
    mainActivity.show();
    return 0;
}
