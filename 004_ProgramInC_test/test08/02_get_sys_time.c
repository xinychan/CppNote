#include "include/io_utils.h"
#include "include/time_utils.h"
#include <time.h>

// 获取系统时间
int main() {

    // time() 获取当前时间
    time_t current_time;
    time(&current_time);
    PRINT_LONG(current_time);

    // time() 获取当前时间
    current_time = time(NULL);
    PRINT_LONG(current_time);

    // 自定义 time_utils.h，让不同编译环境下获取统一毫秒时间
    PRINT_LLONG(TimeInMillisecond());
    PRINT_LLONG(TimeInMillisecond());
    PRINT_LLONG(TimeInMillisecond());
    PRINT_LLONG(TimeInMillisecond());
    return 0;
}
