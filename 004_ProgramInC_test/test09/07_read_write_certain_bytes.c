#include <stdio.h>
#include "include/io_utils.h"
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 4

void Echo() {
    int buffer[BUFFER_SIZE];
    while (1) {
        // fread 读取字节；读取指定大小
        // fread(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
        // _DstBuf=读取目标流；_ElementSize=读取元素的大小；_Count=读取元素的个数；_File=读取的源文件流
        size_t bytes_read = fread(buffer, sizeof(buffer[0]), BUFFER_SIZE, stdin);
        if (bytes_read < BUFFER_SIZE) {
            if (feof(stdin)) {
                puts("EOF");
                fwrite(buffer, sizeof(buffer[0]), bytes_read, stdout);
            } else if (ferror(stdin)) {
                perror("Error read from stdin");
            }
            break;
        }
        // fwrite 写入字节
        // fwrite(const void * __restrict__ _Str,size_t _Size,size_t _Count,FILE * __restrict__ _File)
        // _Str=写入的源文件流；_Size=写入元素的大小；_Count=写入元素的个数；_File=写入的输出文件流
        fwrite(buffer, sizeof(buffer[0]), BUFFER_SIZE, stdout);
    }
}

// 读写指定大小的字节
int main() {
    // fread(); 读取指定大小字节
    // fwrite(); 写入指定大小字节
    Echo();
    return 0;
}
