//
// Created by DS on 2019/9/27.
//
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <alloca.h>
#include "TestC.h"
#include "stdio.h"
#include <stdarg.h> // 获得可变参数的头文件


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

void test(int **b){
    int j = 100;
    *b = &j;
}

/**
 * 可变参数的示例
 */
void testVARGS(int num,...){
    // 表示 ... 的参数列表
    va_list list;
    // 开始取出，第二个参数必须要有，什么类型随便
    va_start(list,num);

    for (size_t i = 0; i < num; ++i) {
        int j = va_arg(list, int);
        LOGE()
    }

}

/**
 * 指针，函数，预处理器
 */
void testPoint(){
    int i = 10;
    // 取地址 存储地址的变量就是 为指针
    int *pInt = &i;
    LOGE("指针地址： %#x",pInt);
    //  解析地址 根据地址拿到地址具体存储的值
    int a = *pInt;
    LOGE("解引用值： %d",a);
    // 通过指针修改变量值
    *pInt = 12;
    LOGE("通过指针修改变量值： %d",i);
    // 下面只是指针pInt值偏移了 指向的值也就变了
    pInt++;
    LOGE("偏移后的指针指向值： %d",*pInt);


    int aar[] = {1,2,3,4,5,6};
    // 将数组的首位元素地址赋值给pAar指针
    int *pAar = aar;
    LOGE("指针指定获取角标元素：%d",pAar[2]);
    LOGE("指针自增获取数组元素： %d",*pAar++);


    // 指针数组，存放指针的数组
    int *p_int[3] = {&i,&i,&i};


    // 下面的二位数组等同于 int doubleAar[] = { 1,2,3,4,5,6 };
    int doubleAar[2][3]={{1,2,3},{4,5,6}};
    // 数组指针，arr_p指向的是一个 int[3] 的数组
    int(*aar_p)[3] = doubleAar;
    // 通过数组指针获得值
    LOGE("数组指针取值：%d",*(*(aar_p+1)+1));
    // 通过下标获取
    LOGE("通过下标获取：%d",doubleAar[1][1]);
    // 指针数组下标获取
    LOGE("通过下标获取：%d",aar_p[1][1]);


    // 二级指针
    int **ppInt = &pInt;
    LOGE("二级指针解引用：%d",**ppInt);

    int b = 10;
    int *p_b = &b;
    test(&p_b);
    LOGE("修改p_b的指向：%d",*p_b);
}