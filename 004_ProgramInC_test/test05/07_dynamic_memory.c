#include <stdio.h>
#include <stdlib.h>
#include "include/io_utils.h"

#define COUNT 10

// 外部传入实参 int *player2 与接受参数的 int *ptr 不是同一个内存地址
// int *player2 地址为 0x001;指针变量传入后，在函数栈中经历1次复制；
// 复制后的指针 int *ptr 地址为 0x002;因此两者内存地址并不相同
// int *player2 无法接收 int *ptr 的变化
void InitPointer(int *ptr, int length, int default_value) {
    ptr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        ptr[i] = default_value;
    }
}

// 函数内要修改指针变量，外部要传入2级指针
// 直接指向传入的指针变量所在的内存地址
// 此时能正确修改指针变量的值
void InitPointer2(int **ptr, int length, int default_value) {
    *ptr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        (*ptr)[i] = default_value;
    }
}

// 动态内存分配
int main() {
    // array 内存在栈区（函数调用栈），函数调用结束，自动释放
    int array[] = {0, 1, 2, 3, 4};

    // player 内存在堆区，函数调用结束，不会自动释放，需要主动释放
    // malloc 创建堆区内存
    int *player = malloc(sizeof(int) * COUNT);
    for (int i = 0; i < COUNT; ++i) {
        player[i] = i;
    }
    PRINT_INT_ARRAY(player, COUNT);
    // 主动释放内存
    if (player) {
        free(player);
    }

    int *player2;
    // InitPointer2 ==> 数组元素初始化
    // InitPointer2(&player2, COUNT, 0);
    // calloc 会给开辟的内存初始化；malloc 开辟的内存不会初始化
    player2 = calloc(COUNT, sizeof(int));
    for (int i = 0; i < COUNT; ++i) {
        PRINT_INT(player2[i]);
        player2[i] = i;
    }
    PRINT_INT_ARRAY(player2, COUNT);
    // realloc 重新分配内存；realloc 开辟的内存不会初始化
    player2 = realloc(player2, sizeof(int) * COUNT * 2);
    PRINT_INT_ARRAY(player2, COUNT * 2);
    // 释放内存
    if (player2) {
        // player2 不为 NULL 释放内存
        free(player2);
    } else {
        // player2 已经为 Null
    }

    return 0;
}
