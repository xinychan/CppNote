#include <iostream>

using namespace std;

// 定义包含友元类的普通类
class ImageView {
private:
    int viewSize;

    // 定义友元类；友元类可以访问私有成员
    friend class MyClass;
};

// Java 每个类都有一个 Class，此 Class 可以通过反射获取私有成员
// 可借助友元类达到此效果
class MyClass {
public:
    ImageView imageView;

    void changeViewSize(int size) {
        imageView.viewSize = size;
    }

    int getViewSize() {
        return imageView.viewSize;
    }
};

// 友元类
int main() {
    return 0;
}
