#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"
#include <stdatomic.h>

atomic_flag resume_flag = ATOMIC_FLAG_INIT;

int PrintNum(void *arg) {
    int num = 0;
    // 标志位没有清空，则会一直运行 while 循环
    while (atomic_flag_test_and_set(&resume_flag)) {
        num++;
        PRINT_INT(num);
        thrd_sleep(&(struct timespec) {.tv_sec=1}, NULL);
    }
    return num;
}

// atomic_flag
// 可用于不同线程都可以访问到的标志位
int main(void) {
    // 初始化标志位
    atomic_flag_test_and_set(&resume_flag);

    thrd_t thrd;
    thrd_create(&thrd, PrintNum, NULL);

    thrd_sleep(&(struct timespec) {.tv_sec=5}, NULL);

    // 清空标志位
    atomic_flag_clear(&resume_flag);
    int last_num;
    thrd_join(thrd, &last_num);
    PRINT_INT(last_num);
    return 0;
}