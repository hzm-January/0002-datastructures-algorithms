//
// Created by asus on 2019/5/29.
//

#include "../stack.h"
#include "sequentialstack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool push(int value) {
    StackFrame *sf = (StackFrame *) malloc(sizeof(StackFrame));
    sf->value = value;
    stack[lastIndex++] = sf;
    return true;
};

int getPop() {
    return stack[lastIndex]->value;
}

int pop() {
    StackFrame *top = stack[--lastIndex];
    int popVal = top->value;
    freeFrame(top);
    return popVal;
}

void freeFrame(StackFrame *sf) {
    if (sf != NULL) {
        free(sf);
        sf = NULL;
    }
}

bool checkIndex(int index) {
    if (index < 0 || index > lastIndex) {
        printf("index out of bounds");
        exit(1);
    }
    return false;
}