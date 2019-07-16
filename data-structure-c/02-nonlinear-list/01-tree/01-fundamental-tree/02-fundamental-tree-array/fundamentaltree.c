//
// Created by asus on 2019/7/16.
//

#include "fundamentaltree.h"


void prePrint(int index) {
    if (array[index] == 0 || index >= MAX_SIZE) {
        return;
    }
    printf("%d\t", array[index]);
    prePrint(index * 2);
    prePrint(index * 2 + 1);
}

void inPrint(int index){
    if (array[index] == 0 || index >= MAX_SIZE) {
        return;
    }
    inPrint(index * 2);
    printf("%d\t", array[index]);
    inPrint(index * 2 + 1);
}

void postPrint(int index){
    if (array[index] == 0 || index >= MAX_SIZE) {
        return;
    }
    postPrint(index * 2);
    postPrint(index * 2 + 1);
    printf("%d\t", array[index]);
}
