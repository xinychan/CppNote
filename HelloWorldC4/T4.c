#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 字符串的转换和比较
int main() {

    // 字符串转换
    char *num = "1";
    int result = atoi(num);
    if (result) { // 非0即true，非0则转换成功
        printf("atoi result = %d\n", result);
    } else {
        // 转换失败，或者数字本身为0
        printf("atoi fail OR char is 0 \n");
    }

    char *num2 = "12.5";
    double resultDou = atof(num2);
    printf("atof result = %lf\n", resultDou);

    // 字符串的比较
    char *str1 = "strcmp";
    char *str2 = "Strcmp";
//     int isEqual = strcmp(str1, str2); // 返回值 0 为相等，非0为不相等；区分大小写
    int isEqual = strcmpi(str1, str2); // 返回值 0 为相等，非0为不相等；不区分大小写
    if (isEqual == 0) {
        printf("strcmp TRUE");
    } else {
        printf("strcmp FALSE");
    }

    return 0;
}
