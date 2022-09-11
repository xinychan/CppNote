#include <iostream>

class BaseActivity {
private:
    // 普通函数
    void setContentView(std::string layoutId) {
        std::cout << "setContentView" << std::endl;
    }

public:
    // 普通函数
    void onCreate() {
        setContentView(getLayoutId());
        initView();
    }

    // 虚函数，子类可以不重写，也能实例化
    virtual std::string getTheme();

    // 纯虚函数/抽象函数；必须赋值为0才是纯虚函数，否则是虚函数
    // 纯虚函数，子类必须重写；否则子类相当于是抽象类
    virtual std::string getLayoutId() = 0;

    virtual void initView() = 0;
};

// 子类必须重写纯虚函数，否则子类相当于抽象类；抽象类不允许实例化
class MainActivity : public BaseActivity {
    std::string getLayoutId() {
        return "getLayoutId";
    }

    void initView() {}
};

// C++ 纯虚函数；相当于 Java 的抽象类
int main() {
    MainActivity mainActivity;
    return 0;
}
