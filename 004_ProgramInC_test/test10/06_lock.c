#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

int count = 0;

// 定义锁
mtx_t mutex;

int Counter(void *arg) {
    PRINTLNF("Counter:");
    for (int i = 0; i < 100000; ++i) {
        // 使用时加锁
        mtx_lock(&mutex);
        count++;
        // 完成时解锁
        mtx_unlock(&mutex);
    }
    return 0;
}

// 定义锁
// mtx_t mutex;
// 初始化锁
// mtx_init(&mutex, mtx_plain);
// 使用时加锁
// mtx_lock(&mutex);
// 完成时解锁
// mtx_unlock(&mutex);
// 结束时销毁锁
// mtx_destroy(&mutex);
int main(void) {
    // 初始化锁
    mtx_init(&mutex, mtx_plain);

    thrd_t thrd1;
    thrd_t thrd2;
    thrd_create(&thrd1, Counter, NULL);
    thrd_create(&thrd2, Counter, NULL);
    thrd_join(thrd1, NULL);
    thrd_join(thrd2, NULL);
    PRINT_INT(count);

    // 结束时销毁锁
    mtx_destroy(&mutex);
    return 0;

}