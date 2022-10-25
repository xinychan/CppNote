cmake_minimum_required(VERSION 3.10.2)
# 当前项目名称
project(06_call_from_cpp)
# 使用的 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 添加可执行程序文件
# 这里同时添加了C和C++文件
add_executable(06_call_from_cpp
        06_call_from_cpp.cpp
        mathutils/factorial.cpp
        mathutils/fibonacci.c)