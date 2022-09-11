#include <iostream>

// C++ 默认关闭多态，要开启多态，要使用虚函数 virtual
// 在父类的函数中，必须使用 virtual 修饰函数，子类才能体现多态
// 否则调用的都是父类中的函数，而不是子类自己重写的函数
class BaseActivity {
public:
    virtual void onStart() {
        std::cout << "BaseActivity onStart" << std::endl;
    }
};

class HomeActivity : public BaseActivity {
public:
    void onStart() {
        std::cout << "HomeActivity onStart" << std::endl;
    }
};

class LoginActivity : public BaseActivity {
public:
    void onStart() {
        std::cout << "LoginActivity onStart" << std::endl;
    }
};

// 多态的体现
void startToActivity(BaseActivity *baseActivity) {
    baseActivity->onStart();
}

// 动态多态（虚继承），函数重写
int main() {
    HomeActivity *homeActivity = new HomeActivity();
    LoginActivity *loginActivity = new LoginActivity();
    startToActivity(homeActivity);
    startToActivity(loginActivity);
    delete homeActivity;
    delete loginActivity;
    return 0;
}
