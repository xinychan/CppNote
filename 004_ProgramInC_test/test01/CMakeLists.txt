cmake_minimum_required(VERSION 3.17)

# 获取当前 cmake 文件目录的名称，即test01，赋值给ProjectId
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# ProjectId名称如果包含空格则替换成下划线
string(REPLACE " " "_" ProjectId ${ProjectId})
# 当前项目名称
project(${ProjectId} C)
# 使用的C语言的标准
set(CMAKE_C_STANDARD 11)
# 获取当前 cmake 文件目录所有C文件，赋值给files
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
# 遍历 files；每个file都添加成可执行程序
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
endforeach ()

# 默认 cmake 生成文件
# cmake_minimum_required(VERSION 3.17)
# project(test01 C)
# set(CMAKE_C_STANDARD 11)
# add_executable(test01 main.c)