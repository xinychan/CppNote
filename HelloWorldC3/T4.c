#include <stdio.h>
#include <stdlib.h>

// 动态开辟空间的场景
int main() {

    // 静态开辟的内存空间大小，无法修改；如果不需要动态修改空间大小，优先使用栈区
    // int arr[10];

    // 开辟的空间需要动态变化，则需要动态开辟，使用堆区
    int num;
    printf("input number:\n");
    // 用户输入的值赋值给 num
    scanf("%d", &num);
    // 动态开辟内存大小，堆区
    int *arr = malloc(sizeof(int) * num);

    int printNum;
    for (int i = 0; i < num; ++i) {
        scanf("%d", &printNum);
        arr[i] = printNum;
        printf("arr[i]:%d\n", arr[i]);
        printf("&(arr[i]):%p\n", &(arr[i]));
        printf("*(arr+i):%d\n", *(arr + i));
        printf("arr+i:%p\n", arr + i);
    }


    return 0;
}
