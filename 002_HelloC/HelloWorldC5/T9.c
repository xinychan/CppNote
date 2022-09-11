#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// 枚举类型；枚举中的标识符 = int类型的常量；常量值默认从0开始，依次递增
enum MyType {
    TYPE_A,
    TYPE_B,
    TYPE_C
};

// 枚举
int main() {
    enum MyType type1 = TYPE_A;
    enum MyType type2 = TYPE_B;
    enum MyType type3 = TYPE_C;
    printf("%d - %d - %d\n", type1, type2, type3);
    return 0;
}
