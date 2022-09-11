#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 文件的复制
int main() {

    // 源文件，和目标文件
    char *fileName = "D:\\test\\test.txt";
    char *fileNameCopy = "D:\\test\\test_copy.txt";

    // rb 读取二进制数据
    FILE *file = fopen(fileName, "rb");
    // wb 写入二进制数据
    FILE *file_copy = fopen(fileNameCopy, "wb");

    if (!fileName || !fileNameCopy) {
        printf("open fail");
        exit(0); // 退出程序
    }

    // 读取后写入数据
    int buffer[512];
    int len;
    // size_t __cdecl fread(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File)
    /* void * __restrict__ _DstBuf:容器buffer
     * size_t _ElementSize:每次偏移量
     * size_t _Count:容器总大小
     * FILE * __restrict__ _File:读取的文件
     */
    while ((len = fread(buffer, sizeof(int), sizeof(buffer) / sizeof(int), file)) != 0) {
        fwrite(buffer, sizeof(int), len, file_copy);
    }

    // 关闭文件
    fclose(file);
    fclose(file_copy);

    return 0;
}
