#include <iostream>
#include "T2.h"

int main() {
// 是否定义宏 RELEASE
#ifdef RELEASE
    std::cout << "RELEASE environment" << std::endl;
#endif

// 是否定义宏 DEBUG
#ifdef DEBUG
    std::cout << "DEBUG environment" << std::endl;
#endif
    return 0;
}
