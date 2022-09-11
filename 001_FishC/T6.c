#include <stdio.h>

// 分支结构
int main() {

    // if 分支判断
    int indexIf;
    printf("if function:");
    scanf("%d", &indexIf);
    if (indexIf > 18) {
        printf("indexIf > 18");
    } else if (indexIf > 10) {
        printf("indexIf > 10");
    } else {
        printf("indexIf <= 10");
    }
    printf("\n");

    // switch 分支判断
    int indexSwitch;
    printf("switch function:");
    scanf("%d", &indexSwitch);
    switch (indexSwitch) {
        case 1:
            printf("switch 1");
            break;
        case 2:
            printf("switch 2");
            break;
        case 3:
            printf("switch 3");
            break;
        default:
            printf("switch default");
            break;
    }
    printf("\n");

    // 三目运算符
    int num = 10;
    int result = num > 0 ? 1 : 0;
    printf("result:%d", result);
    printf("\n");

    // goto 语句：跳转到指定标签
    // 实际开发，尽量不要使用 goto，避免破坏代码逻辑
    int i;
    for (i = 0; i < 10; i++) {
        if (i >= 5) {
            // 跳转到标签，并跳出循环体
            goto label_even;
        }
    }
    // 定义标签
    label_even:
    printf("even number:%d\n", i);

    return 0;
}
