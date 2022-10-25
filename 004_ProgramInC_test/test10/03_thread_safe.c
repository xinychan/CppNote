#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

int count = 0;

int Counter(void *arg) {
    PRINTLNF("Counter:");
    for (int i = 0; i < 100000; ++i) {
        count++;
    }
    return 0;
}

// 资源的线程安全问题
// 1-对共享资源进行非原子的并发访问
// 2-不同线程之间代码可见性问题
// 3-线程内部代码编译时的重排序问题
int main(void) {
    thrd_t thrd1;
    thrd_t thrd2;
    thrd_create(&thrd1, Counter, NULL);
    thrd_create(&thrd2, Counter, NULL);
    thrd_join(thrd1, NULL);
    thrd_join(thrd2, NULL);
    PRINT_INT(count);
}