#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/io_utils.h"

#define PLAYER_COUNT 10

// 交换元素
void SwapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 数组乱序
void Shuffle(int *array, int length) {
    srand(time(NULL));
    for (int i = length - 1; i > 0; --i) {
        int random_num = rand() % i;
        SwapInt(array + i, array + random_num);
    }
}

// 隔离数组；左侧小于中间值，右侧大于中间值
int *Partition(int *low, int *high) {
    int pivot = *(low + (high - low) / 2);
    int *left = low;
    int *right = high;
    while (1) {
        while (*left < pivot) left++;
        while (*right > pivot) right--;
        if (left >= right) {
            break;
        }
        SwapInt(left, right);
        left++;
        right--;
    }
    return right;
}

// 快速排序
void QuickSort(int *low, int *high) {
    if (low >= high) {
        return;
    }
    int *partition = Partition(low, high);
    QuickSort(low, partition);
    QuickSort(partition + 1, high);
}

// 指针版本的快速排序
int main() {
    int *players = malloc(sizeof(int) * PLAYER_COUNT);
    if (!players) {
        return 1;
    }
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        players[i] = i;
    }
    Shuffle(players, PLAYER_COUNT);
    PRINT_INT_ARRAY(players, PLAYER_COUNT);
    QuickSort(players, players + PLAYER_COUNT - 1);
    PRINT_INT_ARRAY(players, PLAYER_COUNT);
    free(players);
    return 0;
}
