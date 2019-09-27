//
// Created by DS on 2019/9/27.
//

#ifndef MEDIECODECDEMO_ANDROID_LOG_H
#define MEDIECODECDEMO_ANDROID_LOG_H

#include <android/log.h>

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"ANDROID_LOG",__VA_ARGS__)

#endif //MEDIECODECDEMO_ANDROID_LOG_H
