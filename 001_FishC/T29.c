#include <stdio.h>

union Test {
    int index;
    double socre;
    long num;
};

// 共用体/联合体
// 共用体与结构体区别：共用体所有成员共享一个内存地址
int main() {
    union Test test;
    test.index = 100;
    test.socre = 9.5;
    test.num = 1000;
    // 共用体成员内存地址相同
    printf("test.index:%p\n", &test.index);
    printf("test.socre:%p\n", &test.socre);
    printf("test.num:%p\n", &test.num);
    // 共用体成员只有最后赋值的成员的值是完全准确的
    printf("test.index:%d\n", test.index);
    printf("test.socre:%lf\n", test.socre);
    printf("test.num:%d\n", test.num);
    return 0;
}
