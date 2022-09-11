#include <stdio.h>

// 数组
int main() {
    // 定义数组
    int sum[10];
    int i = 0;
    for (i = 0; i < 10; i++) {
        sum[i] = i;
        printf("sum[i]:%d\n", sum[i]);
    }

    // 数组的初始化
    int sum2[10] = {0}; // 将数组所有元素初始化为0
    int sum3[10]; // 未初始化，元素值为系统的乱值
    for (i = 0; i < 10; i++) {
        printf("sum2[i]:%d\n", sum2[i]);
        printf("sum3[i]:%d\n", sum3[i]);
    }

    return 0;
}
