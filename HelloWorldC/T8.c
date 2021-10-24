#include <stdio.h>

void swapValue(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 交换数据
int main() {
    int a = 100;
    int b = 200;
    printf("a = %d - b = %d\n", a, b);
    swapValue(&a, &b);
    printf("swapValue:a = %d - b = %d\n", a, b);

    return 0;
}

