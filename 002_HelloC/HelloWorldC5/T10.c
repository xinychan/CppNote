#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// 枚举定义别名
typedef enum {
    ACTION_A,
    ACTION_B,
    ACTION_C
} ActionType;

// 枚举别名
int main() {

    // 枚举定义别名后，VS/CLion 兼容写法
    ActionType action1 = ACTION_A;
    ActionType action2 = ACTION_B;
    ActionType action3 = ACTION_C;
    printf("枚举别名：%d - %d - %d\n", action1, action2, action3);
    return 0;
}
