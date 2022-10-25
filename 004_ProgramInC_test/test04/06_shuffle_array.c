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

// 数组乱序
int main() {
    int array[ARRAY_COUNT];
    for (int i = 0; i < ARRAY_COUNT; ++i) {
        array[i] = i;
    }
    PRINT_INT_ARRAY(array, ARRAY_COUNT);
    ShuffleArray(array, ARRAY_COUNT);
    PRINT_INT_ARRAY(array, ARRAY_COUNT);
    return 0;
}
