//
// Created by asus on 2019/7/29.
//

#include "bfmatch.h"

int find(char *target, char *pattern) {
    int tglen = strlen(target);
    int patlen = strlen(pattern);
    int i, j;
    for (i = 0; i < tglen - patlen + 1; ++i) {
        for (j = 0; j < patlen; ++j) {
            if (target[i + j] != pattern[j]) break;
        }
        if (j == patlen) return i;
    }
    return -1;
}