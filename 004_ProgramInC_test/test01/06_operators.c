#include <stdio.h>

// 运算符
int main() {
    // 算数运算
    int a = 10;
    int b = 2;
    int n1 = a + b;
    int n2 = a - b;
    int n3 = a * b;
    int n4 = a / b;
    a += 2;
    a -= 2;
    a *= 2;
    a /= 2;

    // true:1;false:0
    int res = a > b;
    printf("a > b:%d\n", res);
    res = a < b;
    printf("a < b:%d\n", res);
    res = a >= b;
    printf("a >= b:%d\n", res);
    res = a <= b;
    printf("a <= b:%d\n", res);
    res = a != b;
    printf("a != b:%d\n", res);
    res = a == b;
    printf("a == b:%d\n", res);

    // 逻辑运算 && ||
    printf("a && b:%d\n", a && b);
    printf("a || b:%d\n", a || b);

    // 自增自减 ++ --
    int i = 100;
    int j = i++;
    int k = i--;
    int j2 = ++i;
    int k3 = --i;

    // 位操作 & | ^ ~
    int flag_x = 0x1; // 0001
    int flag_y = 0x2; // 0010
    int flag_z = 0x4; // 0100
    int flag_new = flag_y | flag_z; // 0110
    int flag_is_x = flag_new & flag_x; // 0000
    printf("flag_new:%d\n", flag_new);
    printf("flag_is_x:%d\n", flag_is_x);

    // 移位运算 << >>
    int action = 0x1; // 0001
    int action1 = action << 1; // 0010
    int action2 = action << 2; // 0100
    int action3 = action2 >> 2; // 0001
    printf("action1:%d\n", action1);
    printf("action2:%d\n", action2);
    printf("action3:%d\n", action3);
    return 0;
}
