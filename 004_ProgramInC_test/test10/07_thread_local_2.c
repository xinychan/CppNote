#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

// 定义线程副本变量key
tss_t count_key;

// 释放指针；用于销毁线程副本变量key
void MyFree(void *ptr) {
    PRINTLNF("Free %#x", ptr);
    free(ptr);
}

int Counter(int *arg) {
    // 定义真实变量，开辟内存空间
    int *count = malloc(sizeof(int));
    *count = 0;
    // tss_set(tss_t key, void *val)
    // 线程副本变量key，与真实变量绑定
    if (tss_set(count_key, count) == thrd_success) {
        for (int i = 0; i < 100000; ++i) {
            *count += *arg;
        }
    }
    // 直接打印 count
    PRINT_INT(*count);
    // 通过 tss_get 获取 count_key 变量所绑定的真实变量的值
    PRINT_INT(*((int *) tss_get(count_key)));
    return 0;
}

// tss_create(tss_t *key, tss_dtor_t dtor)
// 创建线程副本变量
// key==开辟内存的副本变量；dtor==线程退出时调用，用于销毁创建key的内存
// tss_delete(tss_t key)
// 主动销毁线程副本变量
// key==开辟内存的副本变量
int main(void) {
    // 创建 tss_t 变量，并定义线程退出时调用的销毁逻辑
    if (tss_create(&count_key, MyFree) == thrd_success) {
        thrd_t thrd1;
        thrd_t thrd2;
        int arg1 = 1;
        int arg2 = 2;
        thrd_create(&thrd1, Counter, &arg1);
        thrd_create(&thrd2, Counter, &arg2);
        thrd_join(thrd1, NULL);
        thrd_join(thrd2, NULL);
        puts("thrd1/thrd2 ended.");
        // 主动销毁 tss_t 变量；主动销毁后，tss_t 变量已经释放，线程结束时 tss_dtor_t 不再执行
        // tss_delete(count_key);
        PRINTLNF("count_key deleted.");
    }
}