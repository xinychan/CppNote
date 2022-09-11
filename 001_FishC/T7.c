#include <stdio.h>

// 循环结构
int main() {

    // while 循环
    int i;
    int sum;
    i = 0;
    sum = 0;
    while (i <= 100) {
        sum = sum + i;
        i++;
    }
    printf("while sum:%d\n", sum);

    // do while 循环
    i = 0;
    sum = 0;
    do {
        sum = sum + i;
        i++;
    } while (i <= 100);
    printf("do while sum:%d\n", sum);

    // for 循环
    i = 0;
    sum = 0;
    for (i = 0; i <= 100; ++i) {
        sum = sum + i;
    }
    printf("for sum:%d\n", sum);

    // break 语句
    for (i = 0; i < 10; ++i) {
        if (i == 5) {
            break;
        }
        printf("break:%d\n", i);
    }

    // continue 语句
    for (i = 0; i < 10; ++i) {
        if (i == 5) {
            continue;
        }
        printf("continue:%d\n", i);
    }

    return 0;
}
