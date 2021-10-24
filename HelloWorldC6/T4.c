#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 文件大小获取
// 思路：读取头指针，指针挪动位置，判断文件大小
int main() {

    char *fileName = "D:\\test\\test.txt";
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        printf("open fail");
        exit(0); // 退出程序
    }

    // 将传入的指针，从0位置，挪动到结尾，并保存指针信息
    fseek(file, 0, SEEK_END);
    // 读取 file 指针信息
    long file_size = ftell(file);
    printf("file_size: %ld\n", file_size);

    fclose(file);

    return 0;
}
