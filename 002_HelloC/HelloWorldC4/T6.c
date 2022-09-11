#include <stdio.h>
#include <ctype.h.>

// 大写转小写
void lower(char *newContent, char *oldContent) {
    // 使用临时变量，避免印象原指针移动
    char *temp = oldContent;
    while (*temp) {
        *newContent = tolower(*temp);
        temp++;
        newContent++;
    }
    // 字符串尾部添加 '\0' 避免 printf 函数打印系统值
    *newContent = '\0';
}

// 字符串大小写转换
int main() {

    char *strJava = "JAVA";
    char newContent[100]; // 字符串容器
    lower(newContent, strJava);
    printf("newContent = %s\n", newContent);

    return 0;
}
