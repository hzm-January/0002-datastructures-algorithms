//
// Created by asus on 2019/7/30.
//

#include "kmpstring.h"

void initialize(char *pattern) {
    // 初始化next
    destroy();
    //
    next = (int *) malloc(sizeof(int) * strlen(pattern));
    memset(next, 0, sizeof(int) * strlen(pattern));
}

int find(char *target, char *pattern) {

    int tglen = strlen(target);
    int ptlen = strlen(pattern);
    int j = 0;
    for (int i = 0; i < tglen; ++i) {
        while (j > 0 && pattern[j] != target[i]) {
            j = next[j - 1] + 1;
        }
        if (pattern[j] == target[i]) {
            j++;
        }
        if (j == ptlen) {
            //此时i与pattern模式串的末尾对齐，找到pattern模式串的开始位置对应的target索引位置
            return i - ptlen + 1;
        }
    }
    return -1;
}

// 失效函数
void generateNext(char *pattern) {
    int ptlen = strlen(pattern);
    next[0] = -1;
    int k = -1;
    for (int i = 1; i < ptlen; ++i) {
        while (k > -1 && pattern[k + 1] != pattern[i]) {
            // 寻找次长可匹配最长后缀子串
            k = next[k];
        }
        if (pattern[k + 1] == pattern[i]) {
            ++k;
        }
        next[i] = k;
    }
}

void destroy() {
    if (next != NULL) {
        free(next);
        next = NULL;
    }
}