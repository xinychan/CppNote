#include <stdio.h>
#include <stdarg.h>

int sum(int n, ...);

// 可变参数使用；... 表明参数个数不明确
int sum(int n, ...) {
    int i = 0;
    int sum = 0;
    va_list vap; // 定义参数列表
    va_start(vap, n); // 有多少个参数
    for (i = 0; i < n; i++) {
        sum = sum + va_arg(vap, int); // 获取每个参数的类型
    }
    va_end(vap); // 参数列表结束
    return sum;
}

// 可变参数
int main() {

    int result = 0;
    result = sum(3, 6, 6, 6);
    printf("sum:%d\n", result);

    return 0;
}
