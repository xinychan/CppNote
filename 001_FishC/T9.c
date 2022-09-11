#include <stdio.h>
#include <string.h>

// 字符数组函数
int main() {

    // 字符串长度：strlen
    char str1[] = "HelloCLion";
    int len = strlen(str1);
    printf("strlen:%d\n", len); // 10
    printf("sizeof:%d\n", sizeof(str1)); // 11;计算了结尾的“\0”

    // 复制字符串：strcpy / strncpy
    char str2[100];
    strncpy(str2, str1, strlen(str1));
    str2[strlen(str1) + 1] = "\0";
    printf("str2:%s\n", str2);

    // 拼接字符串：strcat / strncat
    char str3[] = "HelloJava";
    strcat(str3, str1);
    printf("str3:%s\n", str3);

    // 比较字符串：strcmp / strncmp
    char str4[] = "HelloJava";
    // result == 0 则字符串相同
    int result = strcmp(str3, str4);
    printf("result:%d\n", result);

    return 0;
}
