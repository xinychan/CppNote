#include <stdio.h>

// 字符与字符串
int main() {

    // 字符串手动设定长度
    char name[6] = {'C', 'L', 'i', 'o', 'n', '\0'};
    printf("name:%s\n", name);

    // 字符串自动获取长度
    char name2[] = {'C', 'L', 'i', 'o', 'n', '\0'};
    printf("name2:%s\n", name2);

    // 字符串简易写法
    char name3[] = {"CLion"};
    printf("name3:%s\n", name3);

    // 字符串简易写法2
    char name4[] = "CLion";
    printf("name4:%s\n", name4);
    return 0;
}
