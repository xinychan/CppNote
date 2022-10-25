#include <stdio.h>
#include "include/io_utils.h"
#include <locale.h>

// 输入输出流的位置
int main() {
    FILE *file = fopen("CMakeLists.txt", "rb");
    // 获取当前文件流位置；以二进制方式打开才有效，返回当前文件流位置所在字节数
    long position = ftell(file);
    PRINT_LONG(position);
    char buffer[128];
    // 读取到128的位置
    fread(buffer, 1, 128, file);
    PRINT_LONG(ftell(file));
    // 从文件开始位置偏移
    fseek(file, 10, SEEK_SET);
    PRINT_LONG(ftell(file));
    // 从文件当前位置偏移
    fseek(file, 10, SEEK_CUR);
    PRINT_LONG(ftell(file));
    // 从文件结尾位置偏移
    fseek(file, -10, SEEK_END);
    PRINT_LONG(ftell(file));
    fclose(file);
    return 0;
}
