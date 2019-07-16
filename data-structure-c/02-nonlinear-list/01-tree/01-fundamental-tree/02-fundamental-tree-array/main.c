//
// Created by asus on 2019/7/16.
//
#include "fundamentaltree.h"
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    //initialize tree root;
    memset(array, 0, MAX_SIZE);
    for (int i = 1; i < MAX_SIZE; ++i) {
        array[i] = i;
        printf("%d\t", array[i]);
    }
    printf("\n");

    // previous print
    prePrint(1);
    printf("\n");
    inPrint(1);
    printf("\n");
    postPrint(1);
    printf("\n");
    return 0;
};

