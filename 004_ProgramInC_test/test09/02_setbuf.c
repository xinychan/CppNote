#include <stdio.h>
#include "include/io_utils.h"
#include <errno.h>
#include <string.h>

// 文件流的缓冲，生命周期要不能小于文件本身
// 使用全局变量，缓冲区生命周期大于文件本身
char std_buf[BUFSIZ];

// 文件流缓冲
int main() {
    // std_buf 缓冲区，生命周期要大于 stdout 标准输出流
    setbuf(stdout, std_buf);

    // 读取文件
    FILE *file = fopen("CMakeLists.txt", "r");

    // 使用 setbuf() 设置缓冲区；setbuf() 设置的缓冲区大小固定为 BUFSIZ
    // char buf[BUFSIZ];
    // setbuf(file,buf);

    // 文件流的缓冲，生命周期要不能小于文件本身
    // buf 缓冲区，生命周期要大于 file 文件
    char buf[8192];

    // 判断文件是否存在/读取成功
    if (file) {
        // 使用 setvbuf() 设置缓冲区；setvbuf() 可以自定义缓冲区的大小
        setvbuf(file, buf, _IOLBF, 8192);
        puts("fopen succ");
        // 文件读取过程发生错误，ferror() 获取错误码；非0则发生错误
        int err = ferror(file);
        PRINT_INT(err);
        // 文件读取是否结束，feof() 判断是否结束；非0则结束
        int eof = feof(file);
        PRINT_INT(eof);
        // 清空缓冲区
        fflush(stdout);
        // 最后要关闭文件
        fclose(file);
    } else {
        PRINT_INT(errno);
        puts(strerror(errno));
        perror("fopen");
    }
    return 0;
}
