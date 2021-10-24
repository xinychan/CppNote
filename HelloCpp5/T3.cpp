#include <iostream>

using namespace std;

class BaseActivity1 {
public:
    void onCreat() {
        cout << "BaseActivity1 onCreat" << endl;
    }

    void onStart() {
        cout << "BaseActivity1 onStart" << endl;
    }
};

class BaseActivity2 {
public:
    void onCreat() {
        cout << "BaseActivity2 onCreat" << endl;
    }

    void onStart() {
        cout << "BaseActivity2 onStart" << endl;
    }
};

class BaseActivity3 {
public:
    void onCreat() {
        cout << "BaseActivity3 onCreat" << endl;
    }

    void onStart() {
        cout << "BaseActivity3 onStart" << endl;
    }
};

// 子类继承多个父类
class MainActivity : public BaseActivity1, public BaseActivity2, public BaseActivity3 {
public:
    void onCreat() {
        cout << "MainActivity onCreat" << endl;
    }
};

// C++ 多继承
int main() {
    MainActivity mainActivity;
    // 调用子类自己重写的函数
    mainActivity.onCreat();
    // 调用指定父类的函数
    mainActivity.BaseActivity1::onStart();
    return 0;
}
