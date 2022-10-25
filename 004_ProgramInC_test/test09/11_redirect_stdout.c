#include <stdio.h>
#include "include/io_utils.h"
#include "include/time_utils.h"
#include <locale.h>

#if defined(__APPLE__) || defined(__linux__)
#    include <unistd.h>
#elif defined(_WIN32)
#    include <io.h>
#endif

// 重定向输出流到文件
void RedirectStdout(char const *filename) {
    static int saved_stdout_no = -1;
    if (filename) {
        // 输出流重定向到文件
        if (saved_stdout_no == -1) {
            // 获取文件描述符，指向文件或者文件流
            saved_stdout_no = dup(fileno(stdout));
        }
        fflush(stdout);
        freopen(filename, "a", stdout);
    } else {
        // 恢复到输出流
        if (saved_stdout_no != -1) {
            fflush(stdout);
            dup2(saved_stdout_no, fileno(stdout));
            close(saved_stdout_no);
            saved_stdout_no = -1;
        }
    }
}

// 重定向标准输入输出流
int main() {
//    freopen("output.log", "a", stdout);
//    puts("add log");
//    fclose(stdout);

    puts("001");
    RedirectStdout("stdout.log");
    puts("002"); // 输出到 stdout.log
    RedirectStdout(NULL);
    puts("003"); // 输出到 stdout
    RedirectStdout("stdout.log");
    puts("004");
    RedirectStdout(NULL);
    puts("005");
    return 0;
}
