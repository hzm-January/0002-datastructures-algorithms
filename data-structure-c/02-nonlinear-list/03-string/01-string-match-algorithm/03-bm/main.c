//
// Created by asus on 2019/7/30.
//

#include "bmmatch.h"

int main(int argc, char *argv[]) {

    char *target = "abcacabcbcbacabc";
    char *pattern = "cbacabc";
    initialize(pattern);
    int index = find(target, pattern);
    printf("%d\n", index);
    return 0;
}