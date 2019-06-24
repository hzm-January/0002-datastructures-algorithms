//
// Created by hzm on 2019/6/18.
//
#include "linkedqueue.h"

void enQueue(int value) {
    isFull();
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->value = value;
    newNode->next = NULL;
    LinkNode *p = sentinel;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    size++;
}

int deQueue() {
    isEmpty();
    LinkNode *delNode = sentinel->next;
    sentinel->next = delNode->next;
    int delVal = delNode->value;
    freeNode(delNode);
    size--;
    return delVal;
}

int getFront(){
    isEmpty();
    return sentinel->next->value;
}

bool isEmpty(){
    if (size == 0) {
        printf(" the queue is empty ...");
        exit(0);
    }
}

bool isFull(){
    if (size == MAX_SIZE) {
        printf("the queue is full");
        exit(0);
    }
}

int getSize(){
    return size;
}

void freeNode(LinkNode *delNode) {
    if (delNode != NULL) {
        free(delNode);
        delNode = NULL;
    }
}

void output() {
    printf("start|\t");
    LinkNode *p = sentinel->next;
    int i = 0;
    while (p != NULL) {
        printf("%d|%d\t", i++, p->value);
        p = p->next;
    }
    printf("|end\n");
}

