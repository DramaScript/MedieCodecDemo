//
// Created by DS on 2019/9/27.
//
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <alloca.h>
#include "TestC.h"
#include "stdio.h"

/**
 * 数据类型，数组，内存
 */
void testBaseType(){

    /**
     * 基本数据类型
     */
    long long l_l = 100; // 相当于java的long
    LOGE("long long的所占大小： %d", sizeof(l_l));
    /**
     *  C中数组的两种方式  不支持 赋值为NULL，C++才支持
     */
    int aar1[10];
    int aar2[] = {1,2,3,4};
    LOGE("获得数组的长度： %d", sizeof(aar2)/sizeof(aar2[0]));
    /**
     * 字符串的格式化 相当于java的 +
     */
    char str1[100];
    for (int i = 0; i < 1; ++i) {
        sprintf(str1,"我是第%d个字符",i);
        LOGE("格式化后的字符串： %s",str1);
    }
    /**
     * 内存的申请: 栈内存需要主要申请内存的大小 太大会报错Stack overflow
     */
    size_t memSize = 1*1024*1024;
    // 在堆内存申请 需要初始化内存
    void *v1 = malloc(memSize);
    memset(v1,0,memSize);
    LOGE("malloc申请的内存大小： %d", sizeof(v1));
    free(v1);
    v1 = 0;
    // 在堆内存申请 已经初始化了的 长度为 1*memSize
    void *v2 = calloc(1,memSize);
    LOGE("calloc申请的内存大小： %d", sizeof(v2));
    free(v2);
    v2 = 0;
    // 在栈内存申请 无需手动释放 注意大小
    int *pInt = alloca(sizeof(int)*10);
    LOGE("alloca申请的内存大小： %d", sizeof(pInt));
}

void testPoint(){

}