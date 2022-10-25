#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

int SayHello(char *name) {
    PRINTLNF("Run in new thread[%#x]: Hello, %s", thrd_current(), name);
    return 1;
}

// 线程的基本用法
int main(void) {
    thrd_t new_thread;
    // 创建线程
    int result = thrd_create(&new_thread, SayHello, "C lang");
    if (result == thrd_success) {
        // thrd_current() 获取当前线程
        PRINTLNF("Run in Main thread[%#x], created new_thread[%#x]", thrd_current(), new_thread);
    } else {
        PRINTLNF("Run in Main Thread[%#x], failed to create new_thread", thrd_current());
    }

    // 线程休眠；等子线程运行
    // struct _tthread_timespec duration = {.tv_sec=0, .tv_nsec=100000000};
    // thrd_sleep(&duration, NULL);

    // 指明等待 new_thread 运行结束，并获取线程执行结果；调用 thrd_join 后线程会释放资源
    int res;
    thrd_join(new_thread, &res);
    PRINTLNF("Run in Main Thread[%#x], result from thread[%#x]: %d", thrd_current(), new_thread, res);

    // 调用 thrd_detach 后线程会释放资源，不关注线程执行结果
    // thrd_detach(new_thread);
    return 0;
}