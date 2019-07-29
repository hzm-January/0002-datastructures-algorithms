//
// Created by asus on 2019/7/29.
//
#include "rkmatch.h"

int main(int argc, char *argv[]) {

//
//    systempowerdictionary(5);
//    printf("%d\n", power_dictionary[0]);
//    printf("%d\n", power_dictionary[1]);
//    printf("%d\n", power_dictionary[2]);


    char *target = "zhangsan";
    char *pattern = "g";
    initialize(target, pattern);
    int index = find(target, pattern);
    printf("%d\n", index);
    return 0;
}
