#include "include/io_utils.h"
#include "include/time_utils.h"
#include <time.h>

// 获取日历时间
int main() {
    // 先获取当前时间戳
    time_t current_time;
    time(&current_time);
    PRINT_INT(current_time);
    // 通过 localtime 将当前时间转换成日历时间
    struct tm *local_time = localtime(&current_time);
    PRINT_INT(local_time->tm_year);
    PRINT_INT(local_time->tm_mon);
    PRINT_INT(local_time->tm_mday);
    PRINT_INT(local_time->tm_hour);
    PRINT_INT(local_time->tm_min);
    PRINT_INT(local_time->tm_sec);
    // 通过 mktime 将日历时间转换成时间戳
    time_t current_time2 = mktime(local_time);
    PRINT_INT(current_time2);
    // 通过 gmtime 将当前时间转换成格林威治时间
    struct tm *gmt_tim = gmtime(&current_time);
    PRINT_INT(gmt_tim->tm_year);
    PRINT_INT(gmt_tim->tm_mon);
    PRINT_INT(gmt_tim->tm_mday);
    PRINT_INT(gmt_tim->tm_hour);
    PRINT_INT(gmt_tim->tm_min);
    PRINT_INT(gmt_tim->tm_sec);
    return 0;
}
