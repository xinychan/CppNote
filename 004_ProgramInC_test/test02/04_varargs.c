#include <stdio.h>
#include <stdarg.h>

/**
 * 变长参数示例
 * @param arg_count 参数个数
 * @param ... 具体参数
 */
void HandleVarargs(int arg_count, ...) {
    // va_list 获取变长参数
    va_list args;
    // 开始遍历 args
    va_start(args, arg_count);
    for (int i = 0; i < arg_count; ++i) {
        // 获取对应参数
        int arg = va_arg(args, int);
        printf("%d:%d\n", i, arg);
    }
    // 结束遍历 args
    va_end(args);
}

// 变长参数
int main() {
    HandleVarargs(3, 1, 2, 3);
    return 0;
}
