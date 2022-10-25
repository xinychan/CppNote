#include <stdio.h>
#include <ctype.h>
#include "include/io_utils.h"

// 判断字符是不是数字
int IsDigit(char msg) {
    return msg >= '0' && msg <= '9';
}

// 字符类型判断
int main() {
    // 使用自定义的函数
    PRINT_INT(IsDigit('5'));

    // 使用 ctype.h 中的函数
    // 字符串判断
    PRINT_INT(isdigit('5'));
    PRINT_INT(isspace(' '));
    PRINT_INT(isalpha('a'));
    PRINT_INT(isalnum('f'));
    PRINT_INT(isalnum('1'));
    PRINT_INT(ispunct(','));
    // 大小写转换
    PRINT_CHAR(tolower('A'));
    PRINT_CHAR(toupper('z'));
    return 0;
}
