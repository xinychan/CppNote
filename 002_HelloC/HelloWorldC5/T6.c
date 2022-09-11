#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct Cat3 {
    char *name;
    int age;
};

// 结构体的数组
int main() {

    struct Cat3 catArray[5] = {
            {"cat1", 1},
            {"cat2", 2},
            {"cat3", 3},
            {"cat4", 4},
            {"cat5", 5},
    };

    // VS 的写法
    // catArray[2] = {"cat666", 666};

    // CLion的写法
    struct Cat3 cat = {"cat666", 666};
    printf("name:%s - age:%d \n", cat.name, cat.age);
    //catArray[2] = cat;
    //printf("name:%s - age:%d \n", catArray[2].name, catArray[2].age);
    *(catArray + 2) = cat;
    printf("name:%s - age:%d \n", catArray[2].name, catArray[2].age);

    // 堆区开辟
    struct Cat3 *catArray2 = malloc(sizeof(struct Cat3) * 5);
    catArray2->name = "catName1";
    catArray2->age = 5;
    printf("name:%s - age:%d \n", catArray2->name, catArray2->age);
    // 移动指针，赋值
    catArray2 += 1;
    catArray2->name = "catName2";
    catArray2->age = 6;
    printf("name:%s - age:%d \n", catArray2->name, catArray2->age);

    // 释放堆区资源
    free(catArray2);
    catArray2 = NULL;
    return 0;
}
