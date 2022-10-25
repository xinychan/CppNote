#include <stdio.h>
#include "include/io_utils.h"
#include <locale.h>
#include <sys/stat.h>

// 获取文件大小
long GetFileSize(char const *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

// 文件是否是目录
int IsDirectory(char const *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_mode & S_IFDIR;
}

// 其他常见文件操作
int main() {
    // 删除文件
    int result = remove("data_copy/io_utils.h");
    PRINT_INT(result);
    result = remove("data_copy/io_utils2.h");
    PRINT_INT(result);

    // 文件重命名；移动文件
    rename("data_copy/io_utils.h", "data_copy/io_utils2.h");

    PRINT_LONG(GetFileSize("data_copy/io_utils2.h"));
    PRINT_INT(IsDirectory("data_copy/io_utils2.h")); // 返回0
    PRINT_INT(IsDirectory("data_copy")); // 返回非0
    return 0;
}
