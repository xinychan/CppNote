#include <stdio.h>

// 多级指针
int mainT1() {

    int num = 100;

    // 一级指针 *p
    int *num_p = &num;
    // 二级指针 **p
    // 一般开发中最多三级指针
    int **num_p_p = &num_p;

    printf("num == %d\n", num);
    printf("&num == %p\n", &num);
    printf("num_p == %p\n", num_p);
    printf("num_p_p == %p\n", num_p_p);
    // 通过多级指针获取值
    printf("num == %d\n", **num_p_p);

    return 0;
}
