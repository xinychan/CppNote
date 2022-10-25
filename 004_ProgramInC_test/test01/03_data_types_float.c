#include <stdio.h>

// 数据类型 浮点类型
int main() {
    float f = 3.14f;
    printf("float:%d\n", sizeof(float)); // float:4
    double d = 3.14;
    printf("double:%d\n", sizeof(double)); // double:8
    return 0;
}
