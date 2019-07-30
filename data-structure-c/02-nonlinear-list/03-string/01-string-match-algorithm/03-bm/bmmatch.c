//
// Created by asus on 2019/7/30.
//

#include "bmmatch.h"

// 初始化
void initialize(char *pattern) {
    int ptlen = strlen(pattern);
    destroy();
    bad_character_dictionary = (int *) malloc(sizeof(int) * BCD_SIZE);
    memset(bad_character_dictionary, -1, sizeof(int) * BCD_SIZE);
    suffix = (int *) malloc(sizeof(int) * ptlen);
    memset(suffix, -1, sizeof(int) * ptlen);
    prefix = (bool *) malloc(sizeof(bool) * ptlen);
    memset(prefix, false, sizeof(bool) * ptlen);
    generatebcd(pattern);
    generatesuffixprefix(pattern);

}

void destroy() {
    if (bad_character_dictionary != NULL) {
        free(bad_character_dictionary);
        bad_character_dictionary == NULL;
    }
    if (suffix != NULL) {
        free(suffix);
        suffix = NULL;
    }
    if (prefix != NULL) {
        free(prefix);
        prefix = NULL;
    }
}

// 生成坏字符字段
void generatebcd(char *pattern) {
    int patlen = strlen(pattern); // 模式串的长度
    for (int i = 0; i < patlen; ++i) {
        bad_character_dictionary[pattern[i]] = i;
    }
}

void generatesuffixprefix(char *pattern) {
    int patlen = strlen(pattern); // 模式串的长度
    for (int i = 0; i < patlen-1; ++i) {
        int j = i;
        int k = 0;
        while (j >= 0 && pattern[j] == pattern[patlen - 1 - k]) {
            // ++K 长度=索引k+1， j赋值之后需要--进行后续迭代
            suffix[++k] = j--;
        }
        if (j == -1) {
            prefix[k] = true;
        }
    }
}

int goodsuffix(char *pattern, int j) {
    int patlen = strlen(pattern);
    // 好后缀是否有可匹配的模式串子串，如果有，返回子串的开始下标
    int goodsuffixlen = patlen - 1 - j;
    int index = suffix[goodsuffixlen];
    if (index != -1) return goodsuffixlen - index + 1;
    // 如果没有可匹配的模式串子串，好后缀的后缀中是否有可以匹配模式串前缀的，如果有，返回对应的右滑长度
    for (int i = j + 2; i < patlen; ++i) {
        if (prefix[patlen - i] == true) return i;
    }
    return patlen; //如果没有任何匹配，右滑patlen个位置
}

int find(char *target, char *pattern) {
    int tglen = strlen(target);
    int ptlen = strlen(pattern);
    int i = 0;
    while (i < tglen - ptlen + 1) {
        int j;
        for (j = ptlen - 1; j >= 0; --j) {
            if (target[i + j] != pattern[j]) break;
        }
        if (j < 0) return i; // 完全匹配
        // 如果坏字符在模式串中不存在，右滑j-(-1)个位置
        // 如果坏字符在模式串中存在，右滑j-bcindex个位置
        int bcstep = j - bad_character_dictionary[target[i + j]];
        int gdsfstep = 0;
        if (j < ptlen - 1) {
            gdsfstep = goodsuffix(pattern, j);
        }
        int step = bcstep < gdsfstep ? gdsfstep : bcstep;//好后缀
        i += step;
    }
    return -1;
}
