package com.test.jni;

// 使用 Java 调用 C 函数
// 先编译 Java 源文件
// javac .\com\test\jni\JniMain.java
// 编译 .h 头文件
// javah com.test.jni.JniMain
// 完成头文件JNI函数的具体实现，在C文件中实现具体逻辑
// 通过 build-install，编译生成lib库文件，目录在cmake-build-debug_install_bin；Windows平台为 dll，Linux平台为 so
// 生成lib库文件后，将lib库文件拷贝到"java.library.path"命令所在目录，执行java命令
// -D"java.library.path"="." 表明在当前命令所在目录找lib库文件
// java -D"java.library.path"="." com.test.jni.JniMain
public class JniMain {

    // native 方法所在的 lib，需要 Java 主动加载 lib
    static {
        System.loadLibrary("lib07_call_from_java");
    }

    // 通过 native 方法调用 C 函数
    public static native int fibonacci(int num);

    public static void main(String[] args) {
        // 调用 native 方法
        System.out.println(fibonacci(5));
    }
}