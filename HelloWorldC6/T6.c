#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 文件加密与解密：解密操作
int main() {

    char *fileName = "D:\\test\\test_encode.jpg"; // 加密源文件
    char *fileNameDecode = "D:\\test\\test_decode.jpg"; // 解密后文件

    FILE *file = fopen(fileName, "rb");
    FILE *fileDecode = fopen(fileNameDecode, "wb");

    if (!file || !fileDecode) {
        printf("open fail");
        exit(0); // 退出程序
    }

    /*
     * 加密==修改文件，解密==还原文件
     * 加密思路：（全部加密）把所有字节取出来，修改每一个字节；（部分加密：取出部分字节进行修改）
     * 解密思路：把所有字节取出来，还原修改的每一个字节
     * 简易加密解密方式：使用异或运算，用相同的数字进行两次异或运算后，数值会还原
     */

    // 解密操作
    int content; // 接受读取到字节的值
    // fgetc(FILE *_File) 返回值判断： EOF = end of file
    while ((content = fgetc(file)) != EOF) {
        // 解密操作：对读取的内容做还原，并写入到 fileDecode
        fputc(content ^ 5, fileDecode);
    }

    fclose(file);
    fclose(fileDecode);

    return 0;
}
