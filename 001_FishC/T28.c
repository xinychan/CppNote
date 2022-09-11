#include <stdio.h>

// typedef 是对类型的封装
typedef int integer; // 给 int 起别名

// 宏定义是直接替换
#define INTEGER int

// 给结构体起别名；可同时起类型别名和指针别名
typedef struct Date {
    int year;
    int month;
    int day;
} DATE, *PDATE;

// typedef
int main() {
    integer x;
    int y;
    INTEGER z;
    x = 100;
    y = x;
    z = y;
    printf("x:%d - y:%d  - z:%d", x, y, z);
    return 0;
}
