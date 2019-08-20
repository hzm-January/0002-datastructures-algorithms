//
// Created by hzm on 2019/6/18.
//

#ifndef DATA_STRUCTURE_C_LINKEDQUEUE_H
#define DATA_STRUCTURE_C_LINKEDQUEUE_H

#define MAX_SIZE 10

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct LINK_NODE_STRUCT {
    int value;
    struct LINK_NODE_STRUCT *next;
} LinkNode;
typedef struct QUEUE_LINKED {
    LinkNode *sentinel;
    int size;
} Queue;
Queue *queue;

void enQueue(int value);

int deQueue();

int getFront();

bool isEmptyQueue();
bool isEmptyQueueNoExit();
bool isFullQueue();

int getSize();

void output();

void freeNode(LinkNode *delNode);

void initializeQueue();

void destroyQueue();

#endif //DATA_STRUCTURE_C_LINKEDQUEUE_H
