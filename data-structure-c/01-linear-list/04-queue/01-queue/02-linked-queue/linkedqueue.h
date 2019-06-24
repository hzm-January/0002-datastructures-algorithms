//
// Created by hzm on 2019/6/18.
//

#ifndef DATA_STRUCTURE_C_LINKEDQUEUE_H
#define DATA_STRUCTURE_C_LINKEDQUEUE_H

#define MAX_SIZE 10
#include <stdbool.h>
#include "../../queue.h"


typedef struct LINK_NODE_STRUCT {
    int value;
    struct LINK_NODE_STRUCT *next;
} LinkNode;
LinkNode *sentinel;
int size;
void freeNode(LinkNode * delNode);
#endif //DATA_STRUCTURE_C_LINKEDQUEUE_H
