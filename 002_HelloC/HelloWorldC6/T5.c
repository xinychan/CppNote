#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 文件加密与解密：加密操作
int main() {

    char *fileName = "D:\\test\\test.jpg"; // 源文件
    char *fileNameEncode = "D:\\test\\test_encode.jpg"; // 加密后文件

    FILE *file = fopen(fileName, "rb");
    FILE *fileEncode = fopen(fileNameEncode, "wb");

    if (!file || !fileEncode) {
        printf("open fail");
        exit(0); // 退出程序
    }

    /*
     * 加密==修改文件，解密==还原文件
     * 加密思路：（全部加密）把所有字节取出来，修改每一个字节；（部分加密：取出部分字节进行修改）
     * 解密思路：把所有字节取出来，还原修改的每一个字节
     * 简易加密解密方式：使用异或运算，用相同的数字进行两次异或运算后，数值会还原
     */

    // 加密操作
    int content; // 接受读取到字节的值
    // fgetc(FILE *_File) 返回值判断： EOF = end of file
    while ((content = fgetc(file)) != EOF) {
        // 加密操作：对读取的内容做修改，并写入到 fileEncode
        fputc(content ^ 5, fileEncode);
    }

    fclose(file);
    fclose(fileEncode);

    return 0;
}
