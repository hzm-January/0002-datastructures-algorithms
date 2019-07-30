//
// Created by asus on 2019/7/30.
//

#include "kmpstring.h"

void initialize(char *pattern) {
    // 初始化next
    destroy();
    //
    next = (int *) malloc(sizeof(int) * strlen(pattern));
}

void destroy() {
    if (next != NULL) {
        free(next);
        next = NULL;
    }
}