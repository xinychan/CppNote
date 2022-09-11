#include <iostream>
#include <pthread.h>
#include <unistd.h>

// void *(* func)(void *) 传给线程的函数指针
void *runTask(void *pVoid) { // 异步线程
    int num = *static_cast<int *>(pVoid);
    std::cout << "runTask:" << num << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "runTask-for:" << num << std::endl;
        sleep(1);
    }
    // 函数要有返回值
    return nullptr;
}

// C++ 线程 pthread
int main() {
    std::cout << "main start" << std::endl;
    int number = 100;
    // 线程id，每个线程都有线程id
    pthread_t pthreadID;
    /**
     * pthread_create(pthread_t *th, 线程id
     * const pthread_attr_t *attr, 线程属性
     * void *(* func)(void *), 函数指针的规则
     * void *arg);给函数指针传递的内容
     */
    pthread_create(&pthreadID, 0, runTask, &number);
    // 执行 pthread_join 后，main 函数线程，与 runTask 执行的线程，是非分离线程
    // 分离线程：各线程只执行自己的任务，不与其他线程有关联
    // 非分离线程：线程之间有协作，等其他线程完成后在执行自己的任务
    // pthread_join 会等待异步线程执行完毕
    pthread_join(pthreadID, 0);
    std::cout << "main end" << std::endl;
    return 0;
}
