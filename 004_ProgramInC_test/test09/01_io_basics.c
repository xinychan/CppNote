#include <stdio.h>
#include "include/io_utils.h"
#include <errno.h>
#include <string.h>

// 输入输出流
int main() {
    // 读取文件
    // 传入的相对路径，所以项目的路径要配置到项目的编译配置中
    // Edit Configurations -- Working directory 添加： $ProjectFileDir$
    FILE *file = fopen("CMakeLists.txt", "r");
    // 判断文件是否存在/读取成功
    if (file) {
        puts("fopen succ");
        // 文件读取过程发生错误，ferror() 获取错误码；非0则发生错误
        int err = ferror(file);
        PRINT_INT(err);
        // 文件读取是否结束，feof() 判断是否结束；非0则结束
        int eof = feof(file);
        PRINT_INT(eof);
        // 最后要关闭文件
        fclose(file);
    } else {
        PRINT_INT(errno);
        puts(strerror(errno));
        perror("fopen");
    }

    // errno 错误信息
//    for (int i = 0; i < 10; ++i) {
//        PRINT_INT(i);
//        puts(strerror(i));
//    }
    return 0;
}
