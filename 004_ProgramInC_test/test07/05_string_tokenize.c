#include "include/io_utils.h"
#include <string.h>
#include <stdlib.h>

// 字符串的拆分
int main() {
    // char *string 内容不可变，这里需要能修改变化，使用 char string[]
    char string[] = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";

    // 存储语言信息
    typedef struct Language {
        char *name;
        int year;
    } Language;

    // 定义语言和年份分隔符
    const char *language_break = ";";
    const char *field_break = ",";

    // 语言种类的初始容量
    int language_capacity = 3;
    // 统计的语言种类个数
    int language_size = 0;

    Language *languages = malloc(sizeof(Language) * language_capacity);
    // 内存分配失败，直接结束
    if (!languages) {
        abort();
    }

    // char *strtok(char *_Str, const char *_Delim)
    // char *_Str:待处理的字符串;const char *_Delim:分隔符号
    char *next = strtok(string, field_break);
    // 拆分后，next == C
    while (next) {
        Language language;
        // 解析获取当前语言
        language.name = next;
        // 传入 NULL，以继续解析当前字符串
        next = strtok(NULL, language_break);
        // 拆分后，next == 1972
        if (next) {
            // 解析获取当前语言的年份
            language.year = atoi(next);
            // 将当前 language 内存赋值到 languages 中
            // 先判断 languages 的内存是否足够，不够则扩充
            if (language_size + 1 >= language_capacity) {
                language_capacity *= 2;
                languages = realloc(languages, sizeof(Language) * language_capacity);
                // 内存分配失败，直接结束
                if (!languages) {
                    abort();
                }
            }
            // 把 language 添加到 languages 数组中
            languages[language_size] = language;
            language_size++;
            next = strtok(NULL, field_break);
        }
    }
    // 打印信息
    PRINTLNF("languages: %d", language_size);
    PRINTLNF("languages capacity: %d", language_capacity);
    for (int i = 0; i < language_size; ++i) {
        PRINTLNF("Language[name=%s, year=%d]", languages[i].name, languages[i].year);
    }
    // 释放内存
    free(languages);
    return 0;
}
