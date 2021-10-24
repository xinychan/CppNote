#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 文件的写
int main() {

    /*
     * fopen 打开文件
     * FILE *__cdecl：返回值，结构体
     * const char * __restrict__ _Filename：文件路径
     * const char * __restrict__ _Mode：打开文件模式（r-读，w-写，rb-二进制读，wb-二进制写）
     */
    // FILE *__cdecl fopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode)
    char *fileName = "D:\\test\\test_w.txt";
    // 使用w读取文件，会自动创建文件
    FILE *file = fopen(fileName, "w");
    if (!file) {
        printf("open fail");
        exit(0); // 退出程序
    }
    // 写入文件
    fputs("test_w", file);
    // 关闭文件
    fclose(file);
    return 0;
}
