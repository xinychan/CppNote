#include <iostream>

int main() {

// 没有定义这个宏 TEST，则定义宏 TEST
#ifndef TEST
#define TEST

// 如果定义了宏 TEST，则打印
#ifdef TEST
    std::cout << "ifdef TEST:I" << std::endl;
#ifdef TEST
    std::cout << "ifdef TEST:II" << std::endl;
// 取消宏 TEST 定义；取消后的代码，无法再使用这个宏
#undef TEST

// 判断是否有宏 TEST 定义
#ifdef TEST
    std::cout << "ifdef TEST:III" << std::endl;
#else
    std::cout << "undef TEST" << std::endl;

// 定义了 #if 或 #ifdef/#ifndef，必须要结束if #endif
#endif
#endif
#endif
#endif

    return 0;
}
