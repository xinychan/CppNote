#ifndef HELLOCPP11_MYPTR_H
#define HELLOCPP11_MYPTR_H

#pragma once

// 手写智能指针；实现和 shared_ptr 相同效果
template<typename T>
class Ptr {
private:
    T *object; // 智能指针管理的对象
    int *count; // 引用计数
public:
    // 构造函数
    Ptr() {
        count = new int(1);
        object = 0; // 空构造函数没有传对象，给 object 赋值为0
    }

    Ptr(T *t) : object(t) {
        count = new int(1);
    }

    // 析构函数
    ~Ptr() {
        // 引用计数减1，为0则释放object
        if (--(*count) == 0) {
            if (object) {
                delete object;
            }
            delete count;
            object = 0;
            count = 0;
        }
    }

    // 拷贝构造函数
    Ptr(const Ptr<T> &ptr) {
        // 拷贝时，引用+1
        ++(*ptr.count);
        object = ptr.object;
        count = ptr.count;
    }

    // 自定义=号运算符重载
    Ptr<T> &operator=(const Ptr<T> &ptr) {
        // 赋值时，引用+1
        ++(*ptr.count);

        // 赋值时，需要清空原来的智能指针数据，否则原来的指针数据变成了野指针数据
        if (--(*count) == 0) {
            if (object) {
                delete object;
            }
            delete count;
        }
        object = ptr.object;
        count = ptr.count;
        return *this;
    }

    // 返回引用计数
    int use_count() {
        return *this->count;
    }
};

#endif //HELLOCPP11_MYPTR_H
