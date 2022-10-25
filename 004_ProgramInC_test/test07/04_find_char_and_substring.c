#include "include/io_utils.h"
#include <string.h>

// 查找字符和子串
int main() {
    char *string = "Hello World";
    // 查找字符
    // 正序查找；如果查找到，返回这个包含这个字符之后的所有字符
    char *result = strchr(string, 'l');
    // 倒序查找
    char *result2 = strrchr(string, 'l');
    PRINT_STRING(result); // llo World
    PRINT_STRING(result2); // ld

    // 分隔字符串
    char *string2 = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";
    // 分隔条件，","或者";"
    char *break_set = ",;";
    int count = 0;
    char *p = string2;
    do {
        // 从原字符串中分隔子串
        // 每次调用只能分隔一次，需要重复调用才能把整个字符串分隔完成
        p = strpbrk(p, break_set);
        if (p) {
            puts(p);
            p++;
            count++;
        }

    } while (p);

    // 查找子串
    char *substring = strstr(string, "Wor");
    // 如果查找到，返回这个包含这个子串之后的所有字符
    PRINT_STRING(substring); // World
    // 子串相比原字符串的偏移量
    PRINT_INT(substring - string);

    return 0;
}
