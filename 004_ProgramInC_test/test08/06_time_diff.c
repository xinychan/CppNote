#include "include/io_utils.h"
#include "include/time_utils.h"
#include <time.h>

#define PI 3.1415926

// 模拟耗时工作
void DoHardWork() {
    double sum = 0;
    for (int i = 0; i < 10000000; ++i) {
        sum += i * i / PI;
    }
    PRINT_DOUBLE(sum);
}

// 计算时间差
int main() {
    // 获取当前时间；秒单位
    time_t start_time = time(NULL);
    DoHardWork();
    time_t end_time = time(NULL);
    // 计算时间差，结果为秒单位
    double diff = difftime(start_time, end_time);
    PRINT_DOUBLE(diff);

    // 获取当前时间；毫秒单位
    // 自定义获取毫秒时间函数
    long_time_t start_time_ms = TimeInMillisecond();
    DoHardWork();
    long_time_t end_time_ms = TimeInMillisecond();
    // 计算时间差，结果为毫秒单位
    PRINT_LLONG(end_time_ms - start_time_ms);

    // 获取处理器时间
    // clock() 返回处理器消耗的时间，更真实反映程序运行的耗时
    // time() 返回系统的时间，更适合描述真实世界的时间变化
    clock_t start_time_c = clock();
    DoHardWork();
    clock_t end_time_c = clock();
    // 计算时间差，结果为毫秒单位
    PRINT_LONG(end_time_c - start_time_c);
    // 计算时间差，结果换算为秒单位
    PRINT_DOUBLE((end_time_c - start_time_c) * 1.0 / CLOCKS_PER_SEC);
    return 0;
}
