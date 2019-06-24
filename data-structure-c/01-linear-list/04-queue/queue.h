//
// Created by hzm on 2019/6/17.
//

#ifndef DATA_STRUCTURE_C_01_QUEUE_H
#define DATA_STRUCTURE_C_01_QUEUE_H


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void enQueue(int value);
int deQueue();
int getFront();
bool isEmpty();
bool isFull();
int getSize();
void output();

#endif //DATA_STRUCTURE_C_01_QUEUE_H
