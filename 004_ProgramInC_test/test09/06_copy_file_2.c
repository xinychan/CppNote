#include <stdio.h>
#include "include/io_utils.h"
#include "include/time_utils.h"
#include <locale.h>

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
    int result;
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

#define BUFFER_SIZE 512

/**
 * 复制文件
 * @param src 源文件
 * @param dest 目标文件
 * @return 复制结果
 */
int CopyFile2(char const *src, char const *dest) {
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
    char buffer[BUFFER_SIZE];
    char *next;
    while (1) {
        // 读取源文件内容；每次读取一行，512
        next = fgets(buffer, BUFFER_SIZE, src_file);
        // 判断读取源文件是否成功
        if (!next) {
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

// 复制文件2
int main() {
    // 文件名包含中文，设置本地 utf-8 格式，以成功打开文件
    // setlocale(LC_ALL, "zh_CN.utf-8");
    char *srcs[] = {"data/io_utils.h", "data/sanguo_utf8.txt"};
    char *dests[] = {"data_copy/io_utils.h", "data_copy/sanguo_utf8.txt"};

    // 打印 CopyFile/CopyFile2 两个函数的拷贝时间
    for (int i = 0; i < 2; ++i) {
        TimeCost(NULL);
        CopyFile(srcs[i], dests[i]);
        TimeCost(srcs[i]);
        PRINT_IF_ERROR("CopyFile:%s", srcs[i])
    }

    for (int i = 0; i < 2; ++i) {
        TimeCost(NULL);
        CopyFile2(srcs[i], dests[i]);
        TimeCost(srcs[i]);
        PRINT_IF_ERROR("CopyFile2:%s", srcs[i])
    }

    return 0;
}
