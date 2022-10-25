#include "include/io_utils.h"
#include <stdlib.h>
#include <errno.h>

// 字符串与其他数值类型的转换
int main() {
    // ASCII 码转 int
    PRINT_INT(atoi("1234")); // 1234
    PRINT_INT(atoi("-1234")); // -1234
    PRINT_INT(atoi("abc1234")); // 0
    PRINT_INT(atoi("0abc1234")); // 0
    PRINT_INT(atoi(" 1234abc")); // 1234
    PRINT_INT(atoi("0x10")); // 0

    // ASCII 码转 float
    PRINT_DOUBLE(atof("12.34")); // 12.34
    PRINT_DOUBLE(atof("-12.34")); // -12.34
    PRINT_DOUBLE(atof("12e34")); // 1.2e+35
    PRINT_DOUBLE(atof(" 12.34abc")); // 12.34
    PRINT_DOUBLE(atof("0x10")); // 0;MSVC下支持16进制，MinGW下不支持

    // 使用 strtoX 函数转换
    char const *const kInput = "1 200000000000000000000000000000 3 -4 5abcd bye";
    PRINTLNF("Parse:%s", kInput);
    char const *start = kInput;
    char *end;
    while (1) {
        errno = 0;
        // (start, &end, 10):起始位置，结束位置，进制
        const long i = strtol(start, &end, 10);
        if (start == end) {
            break;
        }
        printf("'%.*s'\t ==> %ld.", (int) (end - start), start, i);
        if (errno == ERANGE) {
            perror("");
        }
        putchar('\n');
        start = end;
    }
    PRINTLNF("Left: %s", end);
    return 0;
}
