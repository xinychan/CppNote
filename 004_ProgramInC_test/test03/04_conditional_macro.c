#include <stdio.h>

/*
 * 条件编译
 * 1. #ifdef 如果定义了
 * 2. #ifndef 如果没定义
 * 3. #if 如果 ...
 *
 * #endif
 *
 *  #if defined(MACRO) == #ifdef MACRO
 */

// 定义 DEBUG 环境
#define DEBUG
// 是否显示 log
#define SHOW_LOG 1

void dump(char *msg) {
#ifdef DEBUG
    // 当 debug 环境才打印
    printf(msg);
    printf("\n");
#endif
#if SHOW_LOG > 0
    // 当 SHOW_LOG 时才打印
    printf("log");
    printf("\n");
#endif
}

// 判断编译环境使用的 C 版本
void ShowVersion() {
#if __STDC_VERSION__ >= 201112
    printf("C11");
#elif __STDC_VERSION__ >= 199901
    printf("C99");
#else
    printf("C90");
#endif
}

// 条件编译
int main() {

    dump("start");
    printf("running...\n");
    dump("end");

    ShowVersion();
    return 0;
}
