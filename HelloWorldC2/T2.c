#include <stdio.h>

// 数组与数组指针
int mainT2() {

    // 定义数组
    int arr[] = {1, 2, 3, 4};
    // 遍历数组
    // 为了兼容不同的C标准，for循环建议先声明循环变量i，然后再在for循环中使用；避免在不同C标准中编译报错
    int i = 0;
    for (i = 0; i < 4; ++i) {
        // 取出数组中元素；写法不同，含义相同
        printf("arr[i] = %d\n", arr[i]);
        printf("*(arr + i) = %d\n", *(arr + i));
    }

    // 数组与指针的关系：数组本质上就是指针
    // arr == &arr == &arr[0]
    printf("aar = %p\n", arr);
    // 数组与指针的关系：数组的取址结果 == 自身(arr == &arr)
    printf("&aar = %p\n", &arr);
    // 数组与指针的关系：数组的内存地址 == 第一个元素的内存地址(&arr == &arr[0])
    printf("&arr[0] = %p\n", &arr[0]);

    // 既然【数组 == 指针 == 内存地址】
    // 那么，就可以通过指针来获取数组中的值
    int *arr_p = arr;
    // 移动指针，获取数组中的值
    printf("*aar_p = %d\n", *arr_p);
    printf("*(arr_p + 1) = %d\n", *(arr_p + 1));
    printf("*(arr_p + 2) = %d\n", *(arr_p + 2));
    printf("*(arr_p + 3) = %d\n", *(arr_p + 3));
    // 移动指针，获取数组中的值
    printf("*aar_p = %d\n", *arr_p);
    arr_p++;
    printf("*aar_p = %d\n", *arr_p);
    arr_p++;
    printf("*aar_p = %d\n", *arr_p);
    arr_p++;
    printf("*aar_p = %d\n", *arr_p);
    arr_p--;
    printf("*aar_p = %d\n", *arr_p);
    arr_p--;
    printf("*aar_p = %d\n", *arr_p);
    arr_p--;
    printf("*aar_p = %d\n", *arr_p);
    // 如果指针移动超过了数组范围，则获取到野值
    printf("*aar_p + N = %d\n", *(arr_p + 10));
    printf("*aar_p + N = %d\n", *(arr_p - 10));

    return 0;
}

