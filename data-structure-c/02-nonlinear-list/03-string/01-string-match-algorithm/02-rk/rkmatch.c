//
// Created by asus on 2019/7/29.
//

#include "rkmatch.h"

void initialize(char *target, char *pattern) {
    systempowerdictionary(strlen(pattern));
    substringhashcodedictionary(target, strlen(pattern));
    patternhashcode(pattern);
}

void distroy() {
    if (power_dictionary != NULL) {
        free(power_dictionary);
        power_dictionary = NULL;
    }
    if (hash_dictionary != NULL) {
        free(hash_dictionary);
        hash_dictionary = NULL;
    }
}

int find(char *target, char *pattern) {
    int tglen = strlen(target);
    int ptlen = strlen(pattern);
    int j = -1;
    for (int i = 0; i < tglen - ptlen + 1; ++i) {
        if (hash_dictionary[i] == pattern_hash_code) {
            j = i;
            break;
        }
    }
    return j;
}

int patternhashcode(char *pattern) {
    pattern_hash_code = 0;
    for (int i = 0; i < strlen(pattern); ++i) {
        pattern_hash_code += (pattern[i] - 'a') * power_dictionary[i];
    }
    return pattern_hash_code;
}

// 第0个位置，存放26的len-1次幂
void systempowerdictionary(int len) {
    if (power_dictionary != NULL) {
        free(power_dictionary);
        power_dictionary = NULL;
    }
    power_dictionary = (int *) malloc(sizeof(int) * len);
    for (int i = len - 1; i >= 0; --i) {
        power_dictionary[i] = pow(26, len - 1 - i);
    }
}

void substringhashcodedictionary(char *target, int len) {
    int strsize = strlen(target);
    if (hash_dictionary != NULL) {
        free(hash_dictionary);
        hash_dictionary = NULL;
    }
    hash_dictionary = (int *) malloc(sizeof(int) * strsize);
    for (int i = 0; i < strsize - len + 1; ++i) {
        if (i == 0) {
            int hashCode = 0;
            for (int j = 0; j < len; ++j) {
                //第一个子串hash计算规则
                hashCode += (target[i + j] - 'a') * power_dictionary[j];
            }
            hash_dictionary[i] = hashCode;
        } else {
            // 从索引1位置开始的子串hash，可以利用前一个子串的hashcode进行计算
            hash_dictionary[i] = (hash_dictionary[i - 1] - (target[i - 1] - 'a') * power_dictionary[0])*26
                                 + (target[i + len - 1] - 'a') * power_dictionary[len - 1];
        }
    }
}