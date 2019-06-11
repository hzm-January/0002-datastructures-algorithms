//
// Created by asus on 2019/6/6.
//

#include "linkedlist.h"

#define MAX_SIZE 100

bool append(double operand) {
//    printf("insert %lf \n", operand);
    LinkNode *p = sentinel;
    while (p->next != NULL) {
        p = p->next;
    }
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->operand = operand;
    newNode->next = NULL;
    p->next = newNode;
    return true;
}

double removeLast() {
    LinkNode *p = sentinel;
    if (p->next == NULL) {
        printf("the stack is null");
        exit(1);
    }
    while (p->next->next != NULL) {
        p = p->next;
    }
    LinkNode *last = p->next;
    double operand = p->next->operand;
    p->next = NULL;
    freeNode(last);
    return operand;
}

void freeNode(LinkNode *delNode) {
    if (delNode != NULL) {
        free(delNode);
        delNode==NULL;
    }
}

void output() {
    LinkNode *p = sentinel;
    int i = 0;
    while ((p = p->next) != NULL) {
        printf("%d|%lf\t", i++, p->operand);
    }
}

bool isEmpty() {
    if (sentinel->next == NULL) {
        return true;
    }
    return false;
}

bool isFull();