#include <stdio.h>

int main() {
    // 指针练习题
    int arrInt[] = {1, 2, 3, 2, 2, 3, 3, 2, 3};
    int result = arrInt[*arrInt + *(arrInt + 4)];
    int result2 = arrInt[*(arrInt + *(arrInt + 4))];
    printf("result = %d\n", result);
    printf("result2 = %d\n", result2);

    return 0;
}
