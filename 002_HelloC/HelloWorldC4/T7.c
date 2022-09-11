#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 字符串截取方式1-通用版本
void substrFunc1(char *result, char *str, int start, int end) {
    char *temp = str; // 临时指针，不破坏指针 str
    int count = 0;
    while (*temp) {
        if (count >= start && count < end) {
            // 将 *temp 中的字符串赋值给 *result
            *result = *temp;
            result++;
        }
        temp++;
        count++;
    }
    // 结尾补0
    *result = '\0';
}

// 字符串截取方式2-理解堆区栈区
void substrFunc2(char **result, char *str, int start, int end) {
    char *temp = str; // 临时指针，不破坏指针 str
    // 截取多少，取多少内存
    char resultArr[end - start];
    int count = 0;
    int index;
    for (index = start; index < end; index++) {
        resultArr[count] = *(temp + index);
        count++;
    }
    // *result = resultArr; 不能让指针指向 resultArr，因为 resultArr 在栈区中，会被回收
    strcpy(*result, resultArr); // 复制字符串内容到 *result
    printf("substrFunc2 :%s\n", resultArr);
    // TODO 结尾需要补0
}

// 字符串截取方式3-巧用指针
void substrFunc3(char *result, char *str, int start, int end) {
    char *temp = str; // 临时指针，不破坏指针 str
    int i;
    for (i = start; i < end; i++) {
        *(result++) = *(temp + i);
    }
    // 结尾补0
    *result = '\0';
}

// 字符串截取方式4-使用strncpy
void substrFunc4(char *result, char *str, int start, int end) {
    // result：接受字符串的容器
    // str + start：原字符串起点
    // end - start：字符串拷贝长度
    strncpy(result, str + start, end - start);
    // TODO 结尾需要补0
}

// 字符串的截取操作
int main() {

    char *content = "clion-java-python";
    char *result;
    substrFunc1(result, content, 6, 10);
    printf("result1 :%s\n", result);
    substrFunc2(&result, content, 6, 10);
    printf("result2 :%s\n", result);
    substrFunc3(result, content, 6, 10);
    printf("result3 :%s\n", result);
    substrFunc4(result, content, 6, 10);
    printf("result4 :%s\n", result);

    return 0;
}
