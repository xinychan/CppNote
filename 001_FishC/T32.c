#include <stdio.h>

// 位运算
int main() {
    // 逻辑位运算符

    // 按位取反 ~
    // 若 x=1,则 ~x=0;
    // 若 x=0,则 ~x=1;

    // 按位与 &
    // 若 x 和 y 都等于1,则 x&y=1;
    // 若 x 和 y 任意一个等于0,则 x&y=0;

    // 按位异或 ^
    // 若 x 和 y 不同,则 x^y=1;
    // 若 x 和 y 相同,则 x^y=0;

    // 按位或 |
    // 若 x 和 y 任意一个等于1,则 x|y=1;
    // 若 x 和 y 都等于0,则 x|y=0;

    // 移位运算符

    // 左移运算符
    // 11001010 << 2 == 00101000

    // 右移运算符
    // 11001010 >> 2 == 00110010

    int value = 1;
    while (value < 1024) {
        value = value << 1;
        printf("value:%d\n", value);
    }
    printf("---value---\n");
    while (value > 0) {
        value = value >> 2;
        printf("value:%d\n", value);
    }
    return 0;
}
