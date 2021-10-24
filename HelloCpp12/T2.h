// 定义宏 HELLOCPP12_T2_H，用于防止重复定义宏和重复包含头文件
// 作用：预编译头文件保护符，保证即使文件被多次包含，头文件也只定义一次
#ifndef HELLOCPP12_T2_H
#define HELLOCPP12_T2_H

// 如果没有定义宏 isRelease，那么就定义宏 isRelease
#ifndef isRelease
#define isRelease 0

// 如果 isRelease 为真，则定义宏 RELEASE
#if isRelease == true
#define RELEASE

// 如果 isRelease 为假，则定义宏 DEBUG
#elif isRelease == false
#define DEBUG

// 定义了 #if 或 #ifdef/#ifndef，必须要结束if #endif
#endif // 结束 isRelease == true 定义
#endif // 结束 isRelease 定义

#endif //HELLOCPP12_T2_H
