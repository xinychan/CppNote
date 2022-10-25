package com.test.jni;

public class JniMain {

    static {
        System.loadLibrary("lib07_call_from_java");
    }

    public static native int fibonacci(int num);

    public static void main(String[] args) {
        System.out.println(fibonacci(6));
    }
}