//
// Created by hzm on 2019/6/6.
//

#ifndef DATA_STRUCTURE_C_LINKEDLIST_H
#define DATA_STRUCTURE_C_LINKEDLIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LINK_NODE {
    double operand;
    struct LINK_NODE *next;
} LinkNode;

LinkNode *sentinel;

bool append(double operand);

double removeLast();

void output();

bool isEmpty();

bool isFull();

void freeNode(LinkNode *delNode);

#endif //DATA_STRUCTURE_C_LINKEDLIST_H
