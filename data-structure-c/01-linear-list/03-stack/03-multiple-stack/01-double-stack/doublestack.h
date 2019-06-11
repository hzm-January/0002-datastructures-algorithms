//
// Created by asus on 2019/6/5.
//

#ifndef DATA_STRUCTURE_C_DOUBLESTACK_H
#define DATA_STRUCTURE_C_DOUBLESTACK_H
#define MAX_SIZE 10
/**
 * side : 0 is the low stack; 1 is the high stack
 */
#include <stdbool.h>

bool push(int value, int side);

int pop(int side);

int getPop(int side);

int length(int side);

bool isEmpty(int side);

bool isFull(int side);

typedef struct STACK_FRAME {
    int value;
} StackFrame;
StackFrame *dualStack[MAX_SIZE];
int highIndex; // the index of the high stack
int lowIndex; // the index of the low stack

void freeFrame(StackFrame * delFrame);
void output(int side);
#endif //DATA_STRUCTURE_C_DOUBLESTACK_H
