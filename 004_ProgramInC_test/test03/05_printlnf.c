#include <stdio.h>
#include <stdarg.h>

// 格式化打印内容
void PrintLnf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

// 格式化打印内容
// "Hello""World" == "HelloWorld"
// __VA_ARGS__ : 宏的变长参数
// ##__VA_ARGS__ : 前面带"##"，表明参数可传可不传
#define PRINT_LNF(format, ...) printf(format"\n", ##__VA_ARGS__)
// #value : 前面带"#"，会转成实际参数的名称
#define PRINT_INT(value) PRINT_LNF(#value":%d",value)

// 格式化打印内容
// 系统预定义的宏
// __FILE__ 所在的文件
// __LINE__ 所在的行数
// __FUNCTION__ 所在的函数
#define PRINT_LNF2(format, ...) printf("("__FILE__":%d) %s:"format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define PRINT_INT2(value) PRINT_LNF2(#value":%d",value)

// 实现 print_lnf
int main() {
    printf("main\n");
    PrintLnf("main");
    PRINT_LNF("main");

    int value = 10;
    printf("main:%d\n", value);
    PrintLnf("main:%d", value);
    PRINT_LNF("main:%d", value);

    int num = 100;
    PRINT_INT(num);

    int num2 = 200;
    PRINT_INT2(num2);
    return 0;
}
