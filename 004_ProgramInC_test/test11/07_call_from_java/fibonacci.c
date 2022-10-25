#include "fibonacci.h"

// fibonacci.h 头文件 Fibonacci 函数的具体实现
unsigned int Fibonacci(unsigned int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

// fibonacci.h 头文件 JNI 函数的具体实现；供Java调用
JNIEXPORT jint
JNICALL Java_com_test_jni_JniMain_fibonacci
        (JNIEnv *env, jclass cls, jint num) {
    // 调用 C 文件的 Fibonacci 函数
    return Fibonacci(num);
}