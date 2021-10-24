#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // 随机数功能
    srand((unsigned) time(NULL));
    int j;
    for (int j = 0; j < 10; ++j) {
        printf("random value: %d\n", rand());
    }
    // 字符串拷贝
    char string[4];
    char *str1 = "abcd";
    strcpy(string, str1); // 把 str1 复制到 string
    printf("string copy:%s\n", string);

    return 0;
}
