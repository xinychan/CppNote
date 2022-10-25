cmake_minimum_required(VERSION 3.17)

# 获取当前 cmake 文件目录的名称，即test01，赋值给ProjectId
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# ProjectId名称如果包含空格则替换成下划线
string(REPLACE " " "_" ProjectId ${ProjectId})
# 当前项目名称
project(${ProjectId} C)
# 使用的C语言的标准
set(CMAKE_C_STANDARD 11)

# 设置链接库安装的路径:install 目录
set(CMAKE_INSTALL_PREFIX install)

# 设置编译时要查找的动态链接库的位置
if (APPLE)
    set(CMAKE_INSTALL_RPATH @loader_path/../lib)
elseif (UNIX)
    set(CMAKE_INSTALL_RPATH \$ORIGIN/../lib)
endif ()

# 添加子目录，会寻找子目录中的 CMakeLists.txt 进行编译
add_subdirectory(fibonacci)
add_subdirectory(factorial)

# 获取当前 cmake 文件目录所有C文件，赋值给files
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
# 遍历 files；每个file都添加成可执行程序
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})

    # 添加要关联的链接库
    target_link_libraries(${name}
            factorial
            fibonacci)

    # 安装的可执行程序
    install(TARGETS ${name} RUNTIME DESTINATION bin)
endforeach ()