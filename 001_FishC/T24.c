#include <stdio.h>

// 普通宏定义
#define NUM 100
#define SOC 200

// 宏的嵌套使用
#define COUNT NUM + SOC

// 带参数的宏定义
#define MAX(x, y) (((x)>(y))?(x):(y))

// # 将参数转为字符串处理
#define STR(str) # str

// ## 记号链接运算符；将两个参数连接到一起
#define TAB(x, y) x##y

// 可变参数；(...)表示可变参数；(#__VA_ARGS__)在预处理中被实际参数集替换
#define SHOWLIST(...) printf(#__VA_ARGS__)

// 高级宏定义
int main() {
    printf("COUNT:%d\n", COUNT);
    printf("MAX:%d\n", MAX(10, 5));
    printf("STR:%s\n", STR(Clion));
    printf("TAB:%d\n", TAB(10, 10)); // 1010
    SHOWLIST(Clion, 666, 100); // Clion, 666, 100
    int n1 = 100 + NUM;
// 终止宏定义；在终止之后该宏无法使用
#undef NUM
    // int n2 = 100 + NUM; // 无法再使用 NUM
    return 0;
}
