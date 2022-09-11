#include <stdio.h>

// 位域的使用：使用位域能有效节省内存空间
// 结构体成员后面使用(:)和数字表示该成员所占的位数
// C标准规定只有 unsigned int/signed int 支持位域
// 其他类型是否支持位域以编译器具体实现为准
// 内存的基本单位是字节，而位域是字节的一部分，所以位域不可以取址运算
struct Test {
    // Test 结构体占4位，拆分给不同变量使用
    unsigned int a: 1; // 占用1位；只能表示0和1
    unsigned int b: 1; // 占用1位；只能表示0和1
    unsigned int c: 2; // 占用2位；能表示0和1和2和3
};

// 位域
// 一个字节8位，通过指定位域，可以将8位拆分给不同变量使用
int main() {
    struct Test test;
    test.a = 0;
    test.b = 1;
    test.c = 2;
    printf("a:%d b:%d c:%d\n", test.a, test.b, test.c);
    printf("sizeof Test:%d\n", sizeof(struct Test)); // 4
    return 0;
}
