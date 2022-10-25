#include <stdio.h>
#include "include/io_utils.h"

#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENTS -1
#define COPY_SRC_OPEN_ERROR -2
#define COPY_SRC_READ_ERROR -3
#define COPY_DEST_OPEN_ERROR -4
#define COPY_DEST_WRITE_ERROR -5
#define COPY_UNKNOWN_ERROR -100

/**
 * 复制文件
 * @param src 源文件
 * @param dest 目标文件
 * @return 复制结果
 */
int CopyFile(char const *src, char const *dest) {
    // 参数非法判断
    if (!src || !dest) {
        return COPY_ILLEGAL_ARGUMENTS;
    }
    // 打开源文件，读取方式
    FILE *src_file = fopen(src, "r");
    if (!src_file) {
        return COPY_SRC_OPEN_ERROR;
    }
    // 打开目标文件，写入方式
    FILE *dest_file = fopen(dest, "w");
    if (!dest_file) {
        // 打开目标文件失败，要关闭前面打开的源文件
        fclose(src_file);
        return COPY_DEST_OPEN_ERROR;
    }
    int result = COPY_SUCCESS;
    while (1) {
        // 读取源文件内容
        int next = fgetc(src_file);
        // 判断读取源文件是否成功
        if (next == EOF) {
            if (ferror(src_file)) {
                result = COPY_SRC_READ_ERROR;
            } else if (feof(src_file)) {
                result = COPY_SUCCESS;
            } else {
                result = COPY_UNKNOWN_ERROR;
            }
            break;
        }
        // 写入目标文件内容
        if (fputc(next, dest_file) == EOF) {
            result = COPY_DEST_WRITE_ERROR;
            break;
        }
    }
    // 释放打开的文件
    fclose(src_file);
    fclose(dest_file);
    return result;
}

// 复制文件
int main() {
    // 传入的相对路径，所以项目的路径要配置到项目的编译配置中
    // Edit Configurations -- Working directory 添加： $ProjectFileDir$
    int result = CopyFile("data/io_utils.h", "data_copy/io_utils.h");
    PRINT_INT(result);
    result = CopyFile("data/logo.bmp", "data_copy/logo.bmp");
    PRINT_INT(result);
    return 0;
}
