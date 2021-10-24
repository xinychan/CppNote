#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// 结构体；结构体嵌套

struct Study {
    char *studyContent;
};

struct Student {
    char *name;
    int age;
    char sex;

    // Study study; // VS 的写法
    struct Study study; // CLion 的写法

    struct Play {
        char *playContent;
    } play;
};

// 结构体的定义与使用3
int main() {

    // 嵌套结构体的定义
    struct Student student = {"Student1", 10, 'M',
                              {"C/C++"},
                              {"CLion"}};

    printf("name:%s - age:%d - sex:%c - study:%s - play:%s\n",
           student.name, student.age, student.sex, student.study.studyContent, student.play.playContent);
    return 0;
}
