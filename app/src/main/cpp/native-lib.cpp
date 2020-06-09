#include <jni.h>
#include <string>
#include <iostream>
#include <thread>

#include "igris/igris/dprint.h"
#include "crow/crow/tower.h"
#include "crow/crow/gates/udpgate.h"
#include "crow/crow/gateway.h"

void println(JNIEnv* env, std::string cppstr)
{
    // Get system class
    jclass syscls = env->FindClass("java/lang/System");
    // Lookup the "out" field
    jfieldID fid = env->GetStaticFieldID(syscls, "out", "Ljava/io/PrintStream;");
    jobject out = env->GetStaticObjectField(syscls, fid);
// Get PrintStream class
    jclass pscls = env->FindClass("java/io/PrintStream");
// Lookup printLn(String)
    jmethodID mid = env->GetMethodID(pscls, "println", "(Ljava/lang/String;)V");
// Invoke the method
    jstring str = env->NewStringUTF(cppstr.data());
    env->CallVoidMethod(out, mid, str);
}

JNIEnv* environment;

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    std::cout << hello << std::endl;
    dprln("helloWorld");
    return env->NewStringUTF(hello.c_str());
}

crow::udpgate udpgate;

void crow_incoming_handler(crow::packet * pack)
{
    println(environment, "Hello");
}

extern "C" JNIEXPORT jint JNICALL
Java_com_example_myapplication_MainActivity_CrowStart(
        JNIEnv* env,
        jobject /* this */
) {
    environment = env;

    int ret = udpgate.open(10012);
    udpgate.bind(12);

    crow::user_incoming_handler = crow_incoming_handler;
    //crow::start_spin();

    return 0;
}

extern "C" JNIEXPORT jint JNICALL
Java_com_example_myapplication_MainActivity_OneStep(
        JNIEnv* env,
        jobject /* this */
) {
    environment=env;
    crow::onestep();
    return 0;
}