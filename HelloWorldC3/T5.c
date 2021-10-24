#include <stdio.h>
#include <stdlib.h>

// 动态开辟之 realloc
int main() {
    // 开辟的空间需要动态变化，则需要动态开辟，使用堆区
    int num;
    printf("input number:\n");
    // 用户输入的值赋值给 num
    scanf("%d", &num);
    // 动态开辟内存大小，堆区
    int *arr = malloc(sizeof(int) * num);

    for (int i = 0; i < num; ++i) {
        arr[i] = 100 + i;
        printf("aar[i]:%d\n", arr[i]);
        printf("&(arr[i]):%p\n", &(arr[i]));
    }
    printf("aar:%p\n", arr);

    // 堆区开辟新的空间，增加原数组空间大小
    int num2;
    printf("add number2:\n");
    scanf("%d", &num2);
    // 原来 arr 的大小，加上新增的大小 = arr2 的大小
    // realloc(void *_Memory,size_t _NewSize);void *_Memory == 原指针；size_t _NewSize == 新指针的总大小
    // realloc 参数为什么要传入原指针，和新指针总大小？
    // 因为开辟新空间可能碰到系统值，不能直接在原堆区后面新增空间，需要重新开辟一整块空间（包含原指针数据，以及新增数据大小）
    // 所以需要原指针，以及新指针总大小，才能计算出新开辟的一整块空间大小
    int *arr2 = realloc(arr, sizeof(int) * (num + num2));
    // 避免新开辟空间开辟失败，需要对arr2做判断
    if (arr2) {
        for (int i = num; i < (num + num2); ++i) {
            arr2[i] = 200 + i;
            printf("arr2[i]:%d\n", arr2[i]);
            printf("&(arr2[i]):%p\n", &(arr2[i]));
        }
        // arr2地址绝大多数情况下，与arr地址相同；因为arr2会直接在arr后面新增数据
        printf("aar2:%p\n", arr2);
    }

    // 打印全部数组内容
    if (arr2) {
        for (int i = 0; i < (num + num2); ++i) {
            arr2[i] = 300 + i;
            printf("arr3[i]:%d\n", arr2[i]);
            printf("&(arr3[i]):%p\n", &(arr2[i]));
        }
        printf("aar3:%p\n", arr2);
    }

    // 释放堆区内存
    if (arr2) {
        // 如果 realloc 开辟内存成功，则释放 arr2（内存+指针指向）和arr（指针指向）
        free(arr2);
        arr2 = NULL;
        arr = NULL;
    } else {
        // 如果 realloc 开辟内存失败，则释放 arr（内存+指针指向）
        free(arr);
        arr = NULL;
    }
    return 0;
}
