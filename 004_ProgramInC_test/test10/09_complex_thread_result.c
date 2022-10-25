#include "include/io_utils.h"
#include "tinycthread/include/tinycthread.h"

// 返回结果
typedef struct {
    int a;
    char *b;
} ComplexResult;

// 传入的函数参数
typedef struct {
    int arg;
    ComplexResult result;
} ComplexArg;

// 给函数参数赋值返回结果
int ComplexReturnVal(ComplexArg *arg) {
    ComplexResult *complex_result = &arg->result;
    complex_result->a = 2;
    complex_result->b = "tinycthread";
    return 0;
}

// 线程返回的简单结果，比如 int
// 线程返回的复杂结果，使用 struct 携带返回值信息
int main(void) {
    ComplexArg complex_arg = {.arg = 1};
    thrd_t thrd1;
    // 传入函数参数
    thrd_create(&thrd1, ComplexReturnVal, &complex_arg);

    int result;
    thrd_join(thrd1, &result);
    // 通过函数参数获取返回结果
    ComplexResult *complex_result = &complex_arg.result;
    PRINT_INT(complex_result->a);
    puts(complex_result->b);
}