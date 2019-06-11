//
// Created by asus on 2019/6/5.
//
#include <stdlib.h>
#include <stdio.h>
#include "doublestack.h"

bool push(int side, int value) {
    if (lowIndex + 1 == highIndex) {
        printf("the index is out of bound");
        exit(1);
    }
    StackFrame *newFrame = (StackFrame *) malloc(sizeof(StackFrame));
    newFrame->value = value;
    if (side == 1) {
        dualStack[--highIndex] = newFrame;
    } else {
        dualStack[++lowIndex] = newFrame;
    }
    return true;
}

int pop(int side) {
    if ((side == 1 && highIndex == MAX_SIZE)
        || (side == 0 && lowIndex == -1)) {
        printf(" the stack is empty");
        exit(1);
    }
    StackFrame *delFrame = NULL;
    if (side == 1) {
        delFrame = dualStack[highIndex++];
    } else {
        delFrame = dualStack[lowIndex--];
    }
    int delValue = delFrame->value;
    freeFrame(delFrame);
    return delValue;
}

void output(int side) {
    if ((side == 1 && highIndex == MAX_SIZE)
        || (side == 0 && lowIndex == -1)) {
        printf(" the stack is empty");
        exit(1);
    }
    printf("bottom|\t");
    if (side == 1) {
        for (int i = MAX_SIZE-1; i >= highIndex; --i) {
            printf("%d|%d\t", i, dualStack[i]->value);
        }
    } else {
        for (int i = 0; i <= lowIndex; ++i) {
            printf("%d|%d\t", i, dualStack[i]->value);
        }
    }
    printf("|top\n");
}

void freeFrame(StackFrame *delFrame) {
    if (delFrame != NULL) {
        free(delFrame);
        delFrame = NULL;
    }
}