#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"
#include <stdatomic.h>

// 原子类型 int
atomic_int count = 0;

int Counter(void *arg) {
    PRINTLNF("Counter:");
    for (int i = 0; i < 100000; ++i) {
        count++;
    }
    return 0;
}

// 原子类型
int main(void) {
    thrd_t thrd1;
    thrd_t thrd2;
    thrd_create(&thrd1, Counter, NULL);
    thrd_create(&thrd2, Counter, NULL);
    thrd_join(thrd1, NULL);
    thrd_join(thrd2, NULL);
    PRINT_INT(count);
    return 0;
}