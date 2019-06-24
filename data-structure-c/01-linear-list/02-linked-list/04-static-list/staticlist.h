//
// Created by hzm on 2019/5/31.
//

#ifndef DATA_STRUCTURE_C_STATICLIST_H
#define DATA_STRUCTURE_C_STATICLIST_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../linearlist.h"
#define MAX_SIZE 10
typedef struct STATIC_LINK_NODE{
    int value;
    int next;
} LinkNode;
LinkNode * list[MAX_SIZE];
int availableIndex; //当前可用索引
void initial();

#endif //DATA_STRUCTURE_C_STATICLIST_H
