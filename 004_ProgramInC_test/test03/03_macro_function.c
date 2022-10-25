#include <stdio.h>

// 定义宏
#define TEN 10

// 宏只做内容替换；宏的参数与类型无关，可以传入任何类型，只要编译通过
// 当宏有复杂逻辑时，建议使用括号将参数和条件括起来，减少逻辑错误
#define MAX(a, b) (a>b)?(a):(b)

// 多行的宏；使用 "\" 换行
#define IS_TEM_NUM(num) \
(num >= 0) && (num <= 9)

// 宏定义；宏函数
int main() {
    printf("TEN:%d\n", TEN);
    // (2 > 3) ? (2) : (3)
    int max = MAX(2, 3);
    printf("max:%d\n", max);
    // (++max > 3) ? (++max) : (3)
    int max2 = MAX(++max, 3);
    printf("max2:%d\n", max2);
    // (5 >= 0) && (5 <= 9)
    printf("IS_TEM_NUM:%d\n", IS_TEM_NUM(5));
    return 0;
}
