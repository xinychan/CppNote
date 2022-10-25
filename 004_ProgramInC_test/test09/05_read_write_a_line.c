#include <stdio.h>
#include "include/io_utils.h"
#include <errno.h>
#include <string.h>

// 读取文件，每次读取 512
void ReadFile() {
    FILE *file = fopen("CMakeLists.txt", "r");
    if (file) {
        char buffer[BUFSIZ];
        // 每次读取 512，并打印一行
        while (fgets(buffer, BUFSIZ, file)) {
            printf(buffer);
        }
        fclose(file);
    } else {
        PRINT_INT(errno);
        puts(strerror(errno));
        perror("fopen");
    }
}

// 打印控制台
void Echo() {
    char buffer[4];
    while (1) {
        // 从标准输入流写入到 buffer
        if (!fgets(buffer, 4, stdin)) {
            break;
        }
        // 打印 buffer
        printf("%s", buffer);
    }
}

// 读写一行字符
int main() {
    ReadFile();
    return 0;
}
