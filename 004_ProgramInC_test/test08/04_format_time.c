#include "include/io_utils.h"
#include "include/time_utils.h"
#include <time.h>

// 格式化时间
int main() {
    // 先获取当前时间戳
    time_t current_time;
    time(&current_time);
    PRINT_INT(current_time);
    // 通过 localtime 将当前时间转换成日历时间
    struct tm *local_time = localtime(&current_time);
    // 格式化时间
    // Wed Sep 14 00:00:00 2022
    puts(asctime(local_time));
    puts(ctime(&current_time));
    // 格式化时间
    // 2022-09-14 00:00:00
    char strf_time[20];
    size_t size = strftime(strf_time, 20, "%Y-%m-%d %H:%M:%S", local_time);
    PRINT_INT(size);
    puts(strf_time);
    // 20220914000000
    size_t size2 = strftime(strf_time, 20, "%Y%m%d%H%M%S", local_time);
    PRINT_INT(size2);
    puts(strf_time);

    // 格式化时间到毫秒值
    long_time_t current_time_ms = TimeInMillisecond();
    int time_ms = current_time_ms % 1000;
    size_t size3 = strftime(strf_time, 20, "%Y%m%d%H%M%S", local_time);
    // 字符串拼接；将 time_ms 内容拼接到 strf_time
    sprintf(strf_time + 14, "%03d", time_ms);
    PRINT_INT(size3);
    puts(strf_time);
    return 0;
}
