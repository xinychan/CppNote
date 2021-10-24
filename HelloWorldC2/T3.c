#include <stdio.h>

// 采用指针遍历数组
int mainT3() {
    // 定义数组
    int arr[] = {1, 2, 3, 4};
    // 遍历数组
    // 为了兼容不同的C标准，for循环建议先声明循环变量i，然后再在for循环中使用；避免在不同C标准中编译报错
    int i = 0;
    for (i = 0; i < 4; ++i) {
        // 取出数组中元素
        printf("arr[i] = %d\n", arr[i]);
        printf("*(arr + i) = %d\n", *(arr + i));
        // 获取数组中元素的地址；数组是连续的内存空间
        printf("(arr + i) = %p\n", (arr + i));
    }
    return 0;
}

