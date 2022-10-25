cmake_minimum_required(VERSION 3.10.2)

project(07_call_from_java C)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INSTALL_PREFIX install)

# 引入 JNI，使C文件可以引入 <jni.h>
find_package(JNI REQUIRED)
# 引入 JNI 目录
include_directories(${JAVA_INCLUDE_PATH})
include_directories(${JAVA_INCLUDE_PATH2})

if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif (WIN32)

# fibonacci.c 编译成动态链接库
add_library(07_call_from_java SHARED fibonacci.c)

install(TARGETS 07_call_from_java
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)