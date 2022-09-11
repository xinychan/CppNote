#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>

std::queue<int> queueData; // 全局队列，用于存储/获取数据

pthread_mutex_t mutex; // 定义互斥锁

// 线程任务
// void *(* func)(void *)
void *runTask(void *pVoid) {
    // pthread_mutex_lock(&mutex) == Java synchronize
    pthread_mutex_lock(&mutex); // 开启锁
    std::cout << "async-runTask：" << *static_cast<int *>(pVoid) << std::endl;
    if (!queueData.empty()) {
        std::cout << "async-queueData：" << queueData.front() << std::endl;
        queueData.pop();
    } else {
        std::cout << "async-queueData empty" << std::endl;
    }
    pthread_mutex_unlock(&mutex); // 释放锁
    return nullptr;
}

// Java 中多线程的操作安全，有内置锁 synchronize
// C++ 互斥锁 == Java 内置锁
int main() {
    std::cout << "main start" << std::endl;

    // 初始化互斥锁
    pthread_mutex_init(&mutex, NULL);

    // 添加数据
    for (int i = 100; i < 105; i++) {
        queueData.push(i);
    }

    // 创建多个线程任务
    int index = 10;
    pthread_t pthreadIdArray[index];
    for (int i = 0; i < index; i++) {
        pthread_create(&pthreadIdArray[i], 0, runTask, &i);
    }

    // main函数线程，等待子线程处理完毕
    sleep(3);
    // 销毁互斥锁
    pthread_mutex_destroy(&mutex);
    std::cout << "main end" << std::endl;
    return 0;
}
