#include <stdio.h>

// 指针
int mainT5() {

    int num_int = 100;
    double num_double = 200;
    printf("num_int == %d\n", num_int);
    printf("num_double == %lf\n", num_double);

    // 通过指针获取值
    // * == 取出变量所在地址的值
    printf("num_int == %d\n", *(&num_int));
    printf("num_double == %lf\n", *(&num_double));


    // 指针变量
    // intP 类型为[int指针]:(int *)
    // intP 的值为地址
    // *intP == 取出指针变量intP所在地址的值
    // doubleP 类型为[double指针]:(double *)
    // doubleP 的值为地址
    // *doubleP == 取出指针变量doubleP所在地址的值
    int *intP = &num_int;
    double *doubleP = &num_double;

    // 取出 intP 的值为地址
    printf("num_int address == %p\n", intP);
    printf("num_double address == %p\n", doubleP);
    // *intP == 取出指针变量intP所在地址的值
    printf("num_int == %d\n", *intP);
    printf("num_double == %lf\n", *doubleP);

    /*
     * 内存地址 == 指针
     * 指针 == 内存地址
     * (int *) == 定义int类型的指针
     * (double *) == 定义double类型的指针
     * 指针别名，指针变量 == 变量，不过是指针的变量
     * intP/doubleP == 指针别名/指针变量
     */
    return 0;
}