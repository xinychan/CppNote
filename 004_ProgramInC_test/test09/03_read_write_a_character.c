#include <stdio.h>
#include "include/io_utils.h"
#include <errno.h>
#include <string.h>

void ReadFile() {
    FILE *file = fopen("CMakeLists.txt", "r");
    if (file) {
        // 从 file 中读取一个字符
        int next_char = getc(file);
        while (next_char != EOF) {
            // 把读取的内容写入到 stdout 输出流
            putchar(next_char);
            // 读取的字符没有结束，继续读取字符
            next_char = getc(file);
        }
        // 关闭流
        fclose(file);
    } else {
        PRINT_INT(errno);
        puts(strerror(errno));
        perror("fopen");
    }
}

// 读写字符串
int main() {

    // 从 stdin 当中读取一个字符
    // getchar();
    // 从指定的流中读取一个字符
    // getc(FILE *_File);
    // fgetc(FILE *_File);
    // getc(FILE *_File) == getchar()

    // 向 stdout 中写入一个字符
    // putchar(int _Ch);
    // 从指定的流中写入一个字符
    // fputc(int _Ch,FILE *_File);
    // putc(int _Ch,FILE *_File);
    // fputc(c) == putc(c,stdout)

//    while (1) {
//        // 读取字符
//        int next_input = getchar();
//        if (next_input == EOF) {
//            break;
//        } else if (next_input == '\n') {
//            continue;
//        }
//        // 写入字符
//        putchar(next_input);
//    }

    ReadFile();

    return 0;
}
