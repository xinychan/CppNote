#include <stdio.h>
#include <stdbool.h>

// 条件表达式
int main() {
    // 布尔值 _Bool  bool
    _Bool is_enabled = false;
    bool is_enable2 = true;

    // if else
    if (is_enabled) {
        printf("is_enabled");
    } else if (is_enable2) {
        printf("is_enable2");
    } else {
        printf("false");
    }

    // 三元表达式
    int num = is_enabled ? 1 : 0;

    // switch case
    switch (num) {
        case 0:
            printf("case 0");
            break;
        case 1:
            printf("case 1");
            break;
        default:
            printf("default");
            break;
    }
    return 0;
}
