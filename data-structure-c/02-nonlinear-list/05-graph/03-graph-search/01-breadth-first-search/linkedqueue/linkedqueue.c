//
// Created by hzm on 2019/6/18.
//
#include "linkedqueue.h"

void initializeQueue();

void destroyQueue();

void initializeQueue() {
    queue = (Queue *) malloc(sizeof(Queue));
    queue->size = 0;
    queue->sentinel = (LinkNode *) malloc(sizeof(LinkNode));
    queue->sentinel->value = -1;
    queue->sentinel->next = NULL;
}

void destroyQueue() {
    if (queue != NULL) {
        free(queue);
        queue = NULL;
    }
}

void enQueue(int value) {
    isFullQueue();
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->value = value;
    newNode->next = NULL;
    LinkNode *p = queue->sentinel;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    queue->size++;
}

int deQueue() {
    isEmptyQueue();
    LinkNode *delNode = queue->sentinel->next;
    queue->sentinel->next = delNode->next;
    int delVal = delNode->value;
    freeNode(delNode);
    queue->size--;
    return delVal;
}

int getFront() {
    isEmptyQueue();
    return queue->sentinel->next->value;
}

bool isEmptyQueue() {
    if (queue->size == 0) {
        printf(" the queue is empty ...");
        exit(0);
    }
    return false;
}

bool isEmptyQueueNoExit() {
    if (queue->size == 0) {
        return true;
    }
    return false;
}

bool isFullQueue() {
    if (queue->size == MAX_SIZE) {
        printf("the queue is full");
        exit(0);
    }
}

int getSize() {
    return queue->size;
}

void freeNode(LinkNode *delNode) {
    if (delNode != NULL) {
        free(delNode);
        delNode = NULL;
    }
}

void output() {
    printf("start|\t");
    LinkNode *p = queue->sentinel->next;
    int i = 0;
    while (p != NULL) {
        printf("%d|%d\t", i++, p->value);
        p = p->next;
    }
    printf("|end\n");
}

