#ifndef CHAPTER13_INCLUDE_FACTORIAL_H_
#define CHAPTER13_INCLUDE_FACTORIAL_H_

// 告诉编译器，这部分代码按C语言的格式进行编译，而不是C++的
// 这个头文件的具体实现是 factorial.cpp 文件
// 这个头文件仅仅被 cpp 文件引入
// 如果是C++文件直接引入这个头文件，不需要extern "C" 也可直接运行
// 如果是C文件引入这个头文件，C++头文件的函数需要extern "C"声明；并且C文件中用 extern 来声明这个函数，这样C文件就能引用C++的函数

extern "C" {
unsigned int Factorial(unsigned int n);
}
#endif //CHAPTER13_INCLUDE_FACTORIAL_H_
