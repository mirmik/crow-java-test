#include <jni.h>
#include <string>
#include <iostream>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    std::cout << hello << std::endl;
    return env->NewStringUTF(hello.c_str());
}
