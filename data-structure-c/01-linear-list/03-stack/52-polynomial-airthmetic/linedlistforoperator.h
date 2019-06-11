//
// Created by asus on 2019/6/10.
//

#ifndef DATA_STRUCTURE_C_LINEDLISTFOROPERATOR_H
#define DATA_STRUCTURE_C_LINEDLISTFOROPERATOR_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct LINK_NODE_OPERATOR {
    char operator;
    struct LINK_NODE_OPERATOR *next;
} LinkNodeOperator;

LinkNodeOperator *sentinelOperator;

bool addLast(char operand);

char getLast();

char delLast();

void outputForOperator();

bool isEmptyOperator();

bool isFullOperator();

void freeNodeForOperator(LinkNodeOperator *delNode);

#endif //DATA_STRUCTURE_C_LINEDLISTFOROPERATOR_H
