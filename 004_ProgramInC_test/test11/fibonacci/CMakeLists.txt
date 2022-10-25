cmake_minimum_required(VERSION 3.10.2)
project(fibonacci C)

set(CMAKE_C_STANDARD 11)

# 如果 WIN32 需要引入SYMBOLS库
if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif (WIN32)

# 编译动态链接库
add_library(fibonacci SHARED
        fibonacci.c)

# 把所有关联的库都安装到一起
install(TARGETS fibonacci
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)