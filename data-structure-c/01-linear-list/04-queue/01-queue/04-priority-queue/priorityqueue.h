//
// Created by hzm on 2019/6/24.
//

#ifndef DATA_STRUCTURE_C_PRIORITYQUEUE_H
#define DATA_STRUCTURE_C_PRIORITYQUEUE_H
#define MAX_SIZE 10
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct PRIORITY_QUEUE_LINK_NODE{
    int priority;
    int value;
    struct  PRIORITY_QUEUE_LINK_NODE * next;
}LinkNode;
LinkNode * queue[MAX_SIZE];
int head;
int tail;
void freeNode(LinkNode * delNode);

void enQueue(int value, int priority);
int deQueue();
int getFront();
bool isEmpty();
bool isFull();
int getSize();
void output();
void adjust();

#endif //DATA_STRUCTURE_C_PRIORITYQUEUE_H
