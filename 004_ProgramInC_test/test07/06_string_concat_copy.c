#include "include/io_utils.h"
#include <string.h>

// 字符串的连接和复制
int main() {
    // 字符串内容修改，需要内存可修改
    // 因此这里不用 char*，需要用 char[]
    char src[] = "HelloWorld";
    char dest[20] = "C said: ";
    // 把 src 内容拼接到 dest 之后
    // strcat(dest, src);

    // 把 src 内容拷贝到 dest 的指定位置，达到拼接的效果
    // strcpy(dest + strlen(dest), src);

    // 把 src 内容拷贝到 dest
    strcpy(dest, src);
    puts(dest);

    return 0;
}
