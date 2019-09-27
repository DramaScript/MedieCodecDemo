#include <jni.h>
#include <string>
extern "C"{
#include "TestC.h"
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_dramascript_mediecodecdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dramascript_mediecodecdemo_JniTestActivity_testJni(JNIEnv *env, jobject thiz) {


}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dramascript_mediecodecdemo_CPlusPlusTestActivity_testC(JNIEnv *env, jobject thiz) {
    testBaseType();
    return 0;
}