#include <stdio.h>
#include <stdlib.h>

// 函数每次调用，都会进栈；执行完毕，会出栈，并释放所有栈成员
// 使用 malloc 后，会在堆区开辟内存空间，虽然函数会出栈并释放栈区成员，但不会释放堆区的成员，堆区需要手动释放
void actionMalloc() {

    // int *p; // 野指针；未初始化的，没有地址的
    // 默认指向空地址，避免野指针
    int *p = NULL;

    // 栈区只开辟了 *arr 指针，数组占用空间在堆区开辟
    int *arr = malloc(1 * 510 * 1024);
    printf("&arr = %p,arr = %p\n", &arr, arr); // 若没有释放，则每次 arr 地址都不同
    // 堆区开辟的空间，必须手动释放
    free(arr);
    arr = NULL; // 重新指向空地址，避免悬空指针（有地址，但地址的内容是空的）
}

// 动态开辟内存；在堆区中开辟内存，执行完毕，需要手动释放内存空间
int main() {

    // 栈区，占用内存大小，最大值约为2M；最大值与系统平台有关；超过最大值会栈溢出报错
    // 堆区，占用内存大小，最大值约为平台分配给编译器的内存的80%；
    //int arr[1 * 507 * 1024]; // Process finished with exit code 0 直接声明数组，属于静态开辟内存，直接在栈区中开辟内存
    //int arr2[1 * 508 * 1024]; // Process finished with exit code -1073741571 (0xC00000FD) 栈溢出报错

    // 函数进栈后，执行完毕会出栈，并释放所有栈成员；因此只要单次不超过栈区内存最大值，就不会栈溢出
    int bool = 10;
    while (bool) {
        actionMalloc();
        bool--;
    }

    return 0;
}
