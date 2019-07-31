//
// Created by asus on 2019/7/30.
//
#include "kmpstring.h"

int main(int argc, char *argv[]) {

    char *target = "abbabbabag";
    char *pattern = "abag";
    initialize(pattern);
    // 失效函数
    generateNext(pattern);
    for (int i = 0; i < strlen(pattern); ++i) {
        printf("%d\t", next[i]);
    }
    printf("\n");

    int index = find(target, pattern);
    printf("%d\n", index);
    return 0;
}
