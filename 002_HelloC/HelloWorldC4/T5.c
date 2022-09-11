#include <stdio.h>
#include <string.h>

// 字符串的查找，包含，拼接
int main() {

    char *content = "my name is CLion";
    char *subContent = "C";
    char *findStr = strstr(content, subContent);

    // 查找字符串
    if (findStr) {
        // strstr 函数返回值 = 从首次找到的字符串一直到最后的字符串
        // findStr is = CLion
        printf("findStr is = %s\n", findStr);
        printf("findStr PASS \n");
    } else {
        printf("findStr FAIL = %s\n", subContent);
    }

    // 查找字符串位置；通过指针的挪动计算
    int index = findStr - content;
    printf("findStr index = %d\n", index);

    // 字符串拼接
    char strList[100]; // 字符串容器
    char *tag = "-**-";
    char *cpp = "CPP";
    char *java = "java";
    strcpy(strList, cpp); // 先拷贝到数组
    strcat(strList, tag); // 然后拼接
    strcat(strList, java); // 然后拼接
    printf("strList = %s\n", strList);

    return 0;
}
