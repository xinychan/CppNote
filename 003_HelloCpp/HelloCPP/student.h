// 头文件，只写声明，不写实现
class student {
private: // 私有属性；外部不可访问
    char *name;
    int age;

public: // 公开属性；外部可访问
    void setAge(int age);

    void setName(char *name);

    int getAge();

    char *getName();
};