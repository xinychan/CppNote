#include <stdio.h>
#include "include/io_utils.h"

// 定义枚举；枚举本质上就是一个整数
enum Format {
    // 默认情况下，PNG=0;JPEG=1;BMP=2;UNKNOWN=3
    // PNG, JPEG, BMP, UNKNOWN
    // 可以自定义枚举的值；自定义之后，会影响后面的枚举值
    // PNG=0;JPEG=10;BMP=11;UNKNOWN=12
    PNG, JPEG = 10, BMP, UNKNOWN
};

// 在定义枚举时，同时定义类型别名，简化枚举调用
typedef enum PicFormat {
    PNG_PIC, JPEG_PIC, BMP_PIC, UNKNOWN_PIC
} PicFormat;

// 枚举
int main() {
    PicFormat picFormat1 = PNG_PIC;
    PicFormat picFormat2 = JPEG_PIC;
    PicFormat picFormat3 = BMP_PIC;
    PicFormat picFormat4 = UNKNOWN_PIC;
    PRINT_INT(sizeof(enum PicFormat));
    PRINT_INT(picFormat1);
    PRINT_INT(picFormat2);
    PRINT_INT(picFormat3);
    PRINT_INT(picFormat4);
    return 0;
}
