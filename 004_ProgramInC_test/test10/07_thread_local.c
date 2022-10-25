#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

// 线程存储期变量；每个线程都有一个副本 int count
_Thread_local int count = 0;

int Counter(int *arg) {
    for (int i = 0; i < 100000; ++i) {
        count += *arg;
    }
    PRINT_INT(count);
    return 0;
}

// Thread Local
// 每个线程都有的独立副本变量，没有共享变量导致的线程问题
int main(void) {

    thrd_t thrd1;
    thrd_t thrd2;
    int arg1 = 1;
    int arg2 = 2;
    thrd_create(&thrd1, Counter, &arg1);
    thrd_create(&thrd2, Counter, &arg2);
    thrd_join(thrd1, NULL);
    thrd_join(thrd2, NULL);
    PRINT_INT(count);

    return 0;
}