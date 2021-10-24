# pragma once

#include <iostream>
#include "safe_queue_tool.h"

SafeQueueClass<int> safeQueue;

// 消费者函数
void *getFunc(void *pVoid) {
    while (true) {
        std::cout << "getFunc" << std::endl;
        int value;
        // 消费数据
        safeQueue.get(value);
        std::cout << "getFunc value:" << value << std::endl;
        // 结束循环；停止消费
        if (value == -1) {
            std::cout << "getFunc break" << std::endl;
            break;
        }
    }
    return nullptr;
}

// 生产者函数
void *setFunc(void *pVoid) {
    while (true) {
        std::cout << "setFunc" << std::endl;
        int value;
        std::cout << "input number:" << std::endl;
        std::cin >> value;
        // 结束循环；停止生产
        if (value == -1) {
            safeQueue.add(value);
            std::cout << "setFunc break" << std::endl;
            break;
        }
        // 生产数据
        safeQueue.add(value);
    }
    return nullptr;
}

// C++ 条件变量+互斥锁 == Java 的 (notify 与 wait)
int main() {
    std::cout << "main start" << std::endl;
    // 消费者线程
    pthread_t pthreadGet;
    pthread_create(&pthreadGet, 0, getFunc, 0);
    // 生产者线程
    pthread_t pthreadSet;
    pthread_create(&pthreadSet, 0, setFunc, 0);
    // 等待生产者/消费者线程执行完毕
    pthread_join(pthreadGet, 0);
    pthread_join(pthreadSet, 0);
    std::cout << "main end" << std::endl;
    return 0;
}
