#include <stdio.h>

// 数据类型 整型
int main() {
    // short == short int
    short int si = 0;
    short s = 0;
    // int 类型
    int i = 0;
    // long == long int
    long int li = 0;
    long l = 0;
    // long long == long long int
    long long int lli = 0;
    long long ll = 0;
    // 无符号整型；没有负号，值大于等于0，取值范围是 int 的两倍
    unsigned int unInt = 10;

    // 整型的长度（所占字节数）：2 ≤ short ≤ int ≤ long
    // 编译环境：Windows 10 64位 + MinGW
    // 不同编译环境会有不同结果
    printf("short int:%d\n", sizeof(short int)); // short int:2
    printf("short:%d\n", sizeof(short)); // short:2
    printf("int:%d\n", sizeof(int)); // int:4
    printf("long int:%d\n", sizeof(long int)); // long int:4
    printf("long:%d\n", sizeof(long)); // long:4
    printf("long long int:%d\n", sizeof(long long int)); // long long int:8
    printf("long long:%d\n", sizeof(long long)); // long long:8
    printf("unsigned int:%d\n", sizeof(unsigned int)); // unsigned int:4
    printf("unsigned int:%u\n", unInt); // {int unInt = -10} 4294967286
    return 0;
}
