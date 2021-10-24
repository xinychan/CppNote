#include <stdio.h>

// 二维数组
int main() {

    // 二维数组定义
    int sum[3][3];

    // 二维数组初始化
    // int sum2[3][3] = {0}; // 元素全部初始化为0
    int sum2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum3[3][3] = {{10, 20, 30},
                      {40, 50, 60},
                      {70, 80, 90}};
    int i;
    int j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("sum2:%d\n", sum2[i][j]);
            printf("sum3:%d\n", sum3[i][j]);
        }
    }

    return 0;
}
