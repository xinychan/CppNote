#include <stdio.h>

// 数据类型 char
int main() {
    // 字符集 ASCII；128个字符，占1个byte；窄字符
    char a = 'a';
    char char_1 = '1';
    char char_1_num = 49;
    char char_1_oct = '\61'; // 8进制；\后加数字，表示8进制
    char char_1_hex = '\x31'; // 16进制；\x后加数字，表示16进制
    printf("char:%d\n", sizeof(char)); // char:1
    // 特殊字符表示
    // \n : newline
    // \b : backspace
    // \r : return
    // \t : table
    // \' : ' 字符字面量
    // \" : " 字符串字面量
    printf("char a:%d\n", a); // char a:97
    printf("char_1:%d\n", char_1); // char_1:49
    printf("char_1_num:%d\n", char_1_num); // char_1_num:49
    printf("char_1_oct:%d\n", char_1_oct); // char_1_oct:49
    printf("char_1_hex:%d\n", char_1_hex); // char_1_hex:49
    // 在字符集中找到映射的字符
    printf("char_1_num text:%c\n", char_1_num);// char_1_num text:1
    printf("char_1_oct:%c\n", char_1_oct); // char_1_oct:1
    printf("char_1_hex:%c\n", char_1_hex); // char_1_hex:1

    // 字符集 Unicode；宽字符
    // 宽字符可使用\u后加数字
    wchar_t zhong = L'中';
    wchar_t zhong_hex = L'\u4E2D';
    printf("zhong:%d\n", zhong); // zhong:20013
    printf("zhong_hex:%d\n", zhong_hex); // zhong_hex:20013

    return 0;
}