//
// Created by asus on 2019/5/29.
//

#ifndef DATA_STRUCTURE_C_SEQUENTIALSTACK_H
#define DATA_STRUCTURE_C_SEQUENTIALSTACK_H

#include "../stack.h"

StackFrame *stack[10];
int lastIndex;
void freeFrame(StackFrame *sf);
#endif //DATA_STRUCTURE_C_SEQUENTIALSTACK_H
