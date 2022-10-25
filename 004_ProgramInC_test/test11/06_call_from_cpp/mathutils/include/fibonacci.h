#ifndef CHAPTER13_INCLUDE_FIBONACCI_H_
#define CHAPTER13_INCLUDE_FIBONACCI_H_

// 告诉编译器，这部分代码按C语言的格式进行编译，而不是C++的
// 这个头文件的具体实现是 fibonacci.c 文件
// 这个头文件同时被 fibonacci.c 和 cpp 文件引入
// 如果是C++文件引入这个头文件，则需要包含extern "C"
// 如果是C文件直接引入这个头文件，不需要包含extern "C"

#ifdef __cplusplus
extern "C" {
#endif

unsigned int Fibonacci(unsigned int n);

#ifdef __cplusplus
}
#endif
#endif //CHAPTER13_INCLUDE_FIBONACCI_H_
