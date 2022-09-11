#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 文件的读取
int main() {

    /*
     * fopen 打开文件
     * FILE *__cdecl：返回值，结构体
     * const char * __restrict__ _Filename：文件路径
     * const char * __restrict__ _Mode：打开文件模式（r-读，w-写，rb-二进制读，wb-二进制写）
     */
    // FILE *__cdecl fopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode)
    char *fileName = "D:\\test\\test.txt";
    // 使用r读取文件，必须要有文件
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("open fail");
        exit(0); // 退出程序
    }
    // 读取文件
    char buffer[100]; // 定义缓存区
    while (fgets(buffer, 100, file)) {
        printf("content:%s\n", buffer);
    }
    // 关闭文件
    fclose(file);

    return 0;
}
