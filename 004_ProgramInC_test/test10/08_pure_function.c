#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

int Counter(void *arg) {
    int local_count = 0;
    PRINTLNF("Counter:");
    for (int i = 0; i < 100000; ++i) {
        // 只对局部变量做操作，不产生影响全局变量的副作用
        local_count++;
    }
    return local_count;
}

// 副作用与纯函数
int main(void) {
    thrd_t thrd1;
    thrd_t thrd2;
    thrd_create(&thrd1, Counter, NULL);
    thrd_create(&thrd2, Counter, NULL);
    int count = 0;
    int result;
    thrd_join(thrd1, &result);
    count += result;
    thrd_join(thrd2, &result);
    count += result;
    PRINT_INT(count);
    return 0;
}