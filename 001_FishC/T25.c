#include <stdio.h>

inline int square(int);

inline int square(int x) {
    return x * x;
}

// 内联函数；可以对编译器编译时进行优化
int main() {
//    int i = 0;
//    for (i = 0; i < 5; i++) {
//        printf("square:%d\n", square(i));
//    }
// 内联函数，要声明在头文件中；直接调用会报错
//    printf("square:%d\n", square(5));

    return 0;
}
