// 生产者/消费者-工具类

#ifndef HELLOCPP10_SAFE_QUEUE_TOOL_H
#define HELLOCPP10_SAFE_QUEUE_TOOL_H

#endif //HELLOCPP10_SAFE_QUEUE_TOOL_H

# pragma once // 控制 include 的次数，防止重复 include

#include <iostream>
#include <string>
#include <queue>
#include <pthread.h>

// 定义模板函数，处理不同传入的数据类型
template<typename T>
class SafeQueueClass {
private:
    std::queue<T> queue; // 队列存放数据
    pthread_mutex_t mutex; // 互斥锁
    pthread_cond_t cond; // 条件变量
public:
    SafeQueueClass() {
        // 初始化互斥锁+条件变量
        pthread_mutex_init(&mutex, 0);
        pthread_cond_init(&cond, 0);
    }

    ~SafeQueueClass() {
        // 销毁互斥锁+条件变量
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }

    // 使用互斥锁，安全添加数据
    void add(T t) {
        pthread_mutex_lock(&mutex);
        // 添加数据后，唤醒其他线程消费数据
        queue.push(t);
        // 相当 Java 中的 notify
        // pthread_cond_signal(&cond);
        // 相当 Java 中的 notifyAll
        pthread_cond_broadcast(&cond);
        std::cout << "pthread_cond_broadcast" << std::endl;
        pthread_mutex_unlock(&mutex);
    }

    // 安全的获取数据
    void get(T &t) {
        pthread_mutex_lock(&mutex);
        // 队列中没有数据了，则等待
        while (queue.empty()) {
            // 相当于 Java 中的 wait
            std::cout << "pthread_cond_wait" << std::endl;
            pthread_cond_wait(&cond, &mutex);
        }
        // 被唤醒了，队列中有数据时，获取元素并删除
        t = queue.front();
        queue.pop();
        pthread_mutex_unlock(&mutex);
    }
};
