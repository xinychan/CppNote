#define __STDC_WANT_LIB_EXT1__ 1

#include "include/io_utils.h"
#include <string.h>
#include <stdlib.h>

// C11 安全版本函数
// MSVC/MinGW 支持安全函数；Ubuntu 不支持安全函数
// 通过宏 __STDC_LIB_EXT1__ 判断编译环境是否支持安全函数
int main() {

#ifdef __STDC_LIB_EXT1__
    puts("support C11 safe version.");
#else
    puts("No support for C11 safe version.");
#endif

    // strcpy() 不做安全检查
    // strcpy_s() 有安全检查
    // 有安全检查的函数，返回值都是 errno_t；可以通过返回值判断函数调用是否符合预期
    char dst[2];
    int error_no = strcpy_s(dst, 2, "Too long");
    PRINT_INT(error_no); // error_no: 34
    if (error_no) {
        perror("strcpy_s returns: ");
        // strcpy_s returns: : Result too large
    }
    return 0;
}
