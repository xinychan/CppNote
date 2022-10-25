#include "include/io_utils.h"
#include <string.h>

// 字符串的长度和比较
int main() {
    // 字符串的长度
    char *msg = "Hello";
    // 解析整个字符串，不论字符串有多长
    PRINT_INT(strlen(msg));
    // (msg, 100):字符串，解析的最大长度
    PRINT_INT(strnlen(msg, 100));
    PRINT_INT(strnlen_s(msg, 100));

    // 字符串的比较
    char *left = "abcde";
    char *right = "abcde123";
    // 比较整个字符串
    PRINT_INT(strcmp(left, right));
    // 比较字符串的前5位
    PRINT_INT(strncmp(left, right, 5));
    return 0;
}
