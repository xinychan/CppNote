#include <stdio.h>

// 函数每次调用，都会进栈；执行完毕，会出栈，并释放所有栈成员
void action() {
    int arr[1 * 50 * 1024];
    printf("action\n");
}

// 静态开辟内存；直接在栈区中开辟内存，出栈后，会自动释放内存空间
int main() {

    // 栈区，占用内存大小，最大值约为2M；最大值与系统平台有关；超过最大值会栈溢出报错
    // 堆区，占用内存大小，最大值约为平台分配给编译器的内存的80%；
    //int arr[1 * 507 * 1024]; // Process finished with exit code 0 直接声明数组，属于静态开辟内存，直接在栈区中开辟内存
    //int arr2[1 * 508 * 1024]; // Process finished with exit code -1073741571 (0xC00000FD) 栈溢出报错

    // 函数进栈后，执行完毕会出栈，并释放所有栈成员；因此只要单次不超过栈区内存最大值，就不会栈溢出
    int bool = 20;
    while (bool) {
        action();
        bool--;
    }

    return 0;
}
