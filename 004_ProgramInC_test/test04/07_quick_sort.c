#include <stdio.h>
#include "include/io_utils.h"
#include <stdlib.h>
#include <time.h>

#define ARRAY_COUNT 50

// 交换元素
void SwapElements(int array[], int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

// 数组乱序
void ShuffleArray(int array[], int length) {
    srand(time(NULL));
    for (int i = length - 1; i > 0; --i) {
        int random_num = rand() % i;
        SwapElements(array, i, random_num);
    }
}

// 隔离数组；左侧小于中间值，右侧大于中间值
int Partition(int array[], int low, int high) {
    int pivot = array[high];
    int partition = low;
    for (int i = low; i < high; ++i) {
        if (array[i] < pivot) {
            SwapElements(array, i, partition);
            partition++;
        }
    }
    SwapElements(array, partition, high);
    return partition;
}

// 快速排序
void QuickSort(int array[], int low, int high) {
    if (low >= high) {
        return;
    }
    int partition = Partition(array, low, high);
    QuickSort(array, low, partition - 1);
    QuickSort(array, partition + 1, high);
}

// 快速排序
int main() {
    int array[ARRAY_COUNT];
    for (int i = 0; i < ARRAY_COUNT; ++i) {
        array[i] = i;
    }
    PRINT_INT_ARRAY(array, ARRAY_COUNT);
    ShuffleArray(array, ARRAY_COUNT);
    PRINT_INT_ARRAY(array, ARRAY_COUNT);
    QuickSort(array, 0, ARRAY_COUNT - 1);
    PRINT_INT_ARRAY(array, ARRAY_COUNT);
    return 0;
}
