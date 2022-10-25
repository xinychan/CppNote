#include <stdio.h>

// 循环表达式
int main() {

    // while 循环
    int n = 1;
    while (n < 5) {
        printf("n = %d\n", n);
        n++;
    }

    // do while 循环
    int m = 1;
    do {
        printf("m = %d\n", m);
        m++;
    } while (m < 5);

    // for 循环
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }

    // break
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            break;
        }
        printf("i = %d\n", i);
    }

    // continue
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            continue;
        }
        printf("i = %d\n", i);
    }

    // goto
    int j = 0;
    start:
    printf("j = %d\n", j);
    if (j < 5) {
        j++;
        goto start;
    }

    return 0;
}
