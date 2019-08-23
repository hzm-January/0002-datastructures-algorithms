//
// Created by hzm on 2019/6/18.
//
#include "linkedqueue.h"
void freeNode(LinkNode *delNode);
void queue_init() {
    queue = (Queue *) malloc(sizeof(Queue));
    queue->size = 0;
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->value = -1;
    newNode->next = NULL;
    queue->sentinel = newNode;
}

void enQueue(int value) {
    isFull();
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
    isEmpty();
    LinkNode *delNode = queue->sentinel->next;
    queue->sentinel->next = delNode->next;
    int delVal = delNode->value;
    freeNode(delNode);
    queue->size--;
    return delVal;
}

int getFront() {
    isEmpty();
    return queue->sentinel->next->value;
}

bool isEmpty() {
    if (queue->size == 0) {
        printf(" the queue is empty ...");
        exit(0);
    }
}

bool isFull() {
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

