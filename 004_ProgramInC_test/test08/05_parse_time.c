#define _XOPEN_SOURCE

#include "include/io_utils.h"
#include <time.h>

// 解析时间
int main() {
    // Ubuntu 平台函数，需要启用 #define _XOPEN_SOURCE
    // strptime(); // 解析时间函数，MinGW和MSVC不支持

    // 时间字符串
    char *time = "2020-11-10 30:30:05.123";
    struct tm parsed_time;
    int millisecond;
    // 解析时间字符串，赋值给对应变量
    sscanf(time, "%4d-%2d-%2d %2d:%2d:%2d.%3d",
           &parsed_time.tm_year,
           &parsed_time.tm_mon,
           &parsed_time.tm_mday,
           &parsed_time.tm_hour,
           &parsed_time.tm_min,
           &parsed_time.tm_sec,
           &millisecond);
    // 时间转换，获取正确的时间
    parsed_time.tm_year -= 1900;
    parsed_time.tm_mon -= 1;
    // 格式化时间，防止时间传入非法，比如最大只有24小时，但传入30小时
    mktime(&parsed_time);
    // 打印时间
    PRINT_INT(parsed_time.tm_year);
    PRINT_INT(parsed_time.tm_mon);
    PRINT_INT(parsed_time.tm_mday);
    PRINT_INT(parsed_time.tm_hour);
    PRINT_INT(parsed_time.tm_min);
    PRINT_INT(parsed_time.tm_sec);
    PRINT_INT(millisecond);

    return 0;
}
