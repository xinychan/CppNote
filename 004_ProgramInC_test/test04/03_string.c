#include <stdio.h>
#include "include/io_utils.h"

// 字符串
int main() {
    // 字符串以 \0 结尾
    // 以下声明方式效果相同
    // char string[6] = "Hello"; // 声明字符串长度，默认自带 \0 结尾
    // char string[6] = "Hello\0"; // 声明字符串长度，手动 \0 结尾
    // char string[] = "Hello"; // 自动获取字符串长度，默认自带 \0 结尾
    char string[] = "Hello\0"; // 自动获取字符串长度，手动 \0 结尾
    for (int i = 0; i < 6; ++i) {
        PRINT_CHAR(string[i]);
    }
    PRINTLNF("%s", string);
    return 0;
}
