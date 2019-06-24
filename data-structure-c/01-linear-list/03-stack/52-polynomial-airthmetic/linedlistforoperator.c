//
// Created by hzm on 2019/6/10.
//
#include "linedlistforoperator.h"

bool addLast(char operator) {
    LinkNodeOperator *p = sentinelOperator;
    while (p->next != NULL) {
        p = p->next;
    }
    LinkNodeOperator *newNode = (LinkNodeOperator *) malloc(sizeof(LinkNodeOperator));
    newNode->operator = operator;
    newNode->next = NULL;
    p->next = newNode;
    return true;
}

char getLast() {
    LinkNodeOperator *p = sentinelOperator;
    while (p->next != NULL) {
        p = p->next;
    }
    return p->operator;
}

char delLast() {
    LinkNodeOperator *p = sentinelOperator;
    if (p->next == NULL) {
        printf("the stack is null");
        exit(1);
    }
    while (p->next->next != NULL) {
        p = p->next;
    }
    LinkNodeOperator *last = p->next;
    char operator = p->next->operator;
    p->next = NULL;
    freeNodeForOperator(last);
    return operator;
}

void outputForOperator(){
    LinkNodeOperator *p = sentinelOperator;
    int i = 0;
    while ((p = p->next) != NULL) {
        printf("%d|%lf\t", i++, p->operator);
    }
}

bool isEmptyOperator(){
    if (sentinelOperator->next == NULL) {
        return true;
    }
    return false;
}

bool isFullOperator();

void freeNodeForOperator(LinkNodeOperator *delNode){
    if (delNode != NULL) {
        free(delNode);
        delNode==NULL;
    }
}