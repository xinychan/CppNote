#include <stdio.h>

// 变量
int main() {
    int value;
    int value_init = 1;
    value = 2;
    printf("value:%d\n", sizeof(value));
    // 打印变量内存地址，16进制显示
    printf("address:%#x\n", &value);
    return 0;
}
