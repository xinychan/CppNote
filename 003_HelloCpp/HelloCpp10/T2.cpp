#include <iostream>
#include <thread>
#include <unistd.h>

void runAction(int number) {
    for (int i = 0; i < 3; i++) {
        std::cout << "runAction number:" << number << std::endl;
        sleep(1);
    }
}

// C++11 标准库中自带的 thread
// C++11 后自带的 thread 是对 pthread 的封装，不常用，非重点
// C++线程的重点是 pthread
int main() {
    std::cout << "main start" << std::endl;

    // 使用 VS 开发环境，没有 pthread
    // CLion 使用 MinGW 环境，没有 pthread
    // CLion 使用 Cygwin 环境，才有 pthread
    // AndroidNDK 默认有 pthread
    // Linux 默认有 pthread
    // 没有 pthread 的环境，需要手动导入，可以解决
    /**
     * 本机实际测试结果：
     * CLion 使用 MinGW64 环境，有 thread，也有 pthread
     */
    std::thread thread(runAction, 100);
    thread.join(); // main函数线程，等待 thread 执行完再执行
    std::cout << "main end" << std::endl;
    return 0;
}
