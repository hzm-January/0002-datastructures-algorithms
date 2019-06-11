//
// Created by asus on 2019/5/29.
//

#ifndef DATA_STRUCTURE_C_STACK_H
#define DATA_STRUCTURE_C_STACK_H

#include <stdbool.h>
bool push(int value);
int pop();
int getPop();
int length();
bool isEmpty();
bool isFull();
typedef struct STACK_FRAME{
    int value;
} StackFrame;

#endif //DATA_STRUCTURE_C_STACK_H
