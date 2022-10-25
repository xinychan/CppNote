#include "include/io_utils.h"
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

// 宽字符串与窄字符串的转换
int main() {

    // 是否是宽字符的判断
    // 是否是宽字符英文，是否是宽字符数字
    PRINT_BOOL(iswalpha(L'A'));
    PRINT_BOOL(iswdigit(L'9'));

    // 宽字符长度
    wchar_t *wcs = L"你好 Hello";
    size_t length = wcslen(wcs);
    PRINT_INT(length);

    // 宽字符拷贝
    wchar_t src[] = L"HelloWorld";
    wchar_t *dest = malloc(sizeof(wchar_t) * 11);
    wmemset(dest, 0, 11);
    wmemcpy(dest, src, 11);
    _putws(dest);
    free(dest);

    // 宽字符窄字符转换
    char *new_locale = setlocale(LC_ALL, "zh_CN.utf8");
    if (new_locale) {
        puts(new_locale);
    }
    char mbs[] = "你好";
    wchar_t wcs2[10];
    // 窄字符转宽字符
    mbstowcs(wcs2, mbs, 10);
    wprintf(L"%s\n", wcs2);

    return 0;
}
