#include "include/io_utils.h"
#include <string.h>
#include <stdlib.h>

// 常见的内存操作函数
int main() {

    // 内存查找某个值
    // memchr();
    // strchr();

    // 内存的比较
    // memcmp();
    // strcmp();

    // 内存赋值
    // memset();
    char *mem = malloc(10);
    // 给 char *mem 全部赋初始值1
    memset(mem, 1, 10);
    PRINT_INT_ARRAY(mem, 10);
    free(mem);

    // 内存的复制
    // memcpy();
    // strcpy();

    // 内存的值的移动
    // memmove();
    char src[] = "HelloWorld";
    char *dest = malloc(11);
    memset(dest, 0, 11);
    memcpy(dest, src, 11);
    puts(dest);
    // 从 _Src 位置开始，选取 _Size 大小的内存，移动到 _Dst 位置
    // 把 llo 移动到 Hello 之后的位置
    memmove(dest + 5, dest + 2, 3);
    puts(dest);
    free(dest);
    return 0;
}
