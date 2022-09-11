#include <iostream>

// 预处理器；预处理会完成文本替换的操作
// 预处理语法：#xxx
//#include == (导入头文件)
//#if == (if 判断)
//#elif == (else if 判断)
//#else == (else 判断)
//#endif == (结束 if 判断)
//#define == (定义一个宏)
//#ifdef == (如果已经定义这个宏)
//#ifndef == (如果没有定义这个宏)
//#undef == (取消宏定义)
//#pragma == (设定编译器状态)

#define NUM 60

int main() {
// 定义了 #if ，必须要结束if #endif
#if (NUM > 100)
    std::cout << "NUM > 100" << std::endl;
#elif (NUM > 50)
    std::cout << "NUM > 50" << std::endl;
#else
    std::cout << "NUM > 0" << std::endl;
#endif
    std::cout << "#endif" << std::endl;

    return 0;
}
