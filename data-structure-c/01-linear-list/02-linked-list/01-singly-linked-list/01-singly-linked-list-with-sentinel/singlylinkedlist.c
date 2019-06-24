//
// Created by hzm on 2019/5/29.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../../linearlist.h"
#include "singlylinkedlist.h"

bool insert(int index, int value) {
    checkIndex(index);
    LinkedNode *newNode = (LinkedNode *) malloc(sizeof(LinkedNode));
    newNode->value = value;
    newNode->next = NULL;
    LinkedNode *p = sentinel;
    for (int i = 0; i < index; ++i) {
        if (p->next == NULL) {
            printf("index out of bounds");
            exit(1);
        }
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

int delete(int index) {
    checkIndex(index);
    if (isEmpty()) {
        printf("the list is empty");
        exit(1);
    }
    LinkedNode *p = sentinel;
    for (int i = 0; i < index; ++i) {
        p = p->next;
        if (p->next == NULL) {
            printf("index out of bounds");
            exit(1);
        }
    }
    LinkedNode *delNode = p->next;
    p->next = delNode->next;
    int delVal = delNode->value;
    freeNode(delNode);
    return delVal;
}

void freeNode(LinkedNode *delNode) {
    if (delNode != NULL) {
        free(delNode);
        delNode == NULL;
    }
}

void output() {
    printf("start|\t");
    LinkedNode *p = sentinel;
    int i = 0;
    while (p = p->next) {
        printf("%d|%d\t", i++, p->value);
    }
    printf("|end\n");
}

bool checkIndex(int index) {
    if (index < 0) {
        printf("index is illegal");
        exit(1);
    }
    return true;
}

int length() {
    int count = 0;
    LinkedNode *p = sentinel;
    while (p = p->next) {
        count++;
    }
    return count;
}

void sort() {
    LinkedNode *p = NULL;
    LinkedNode *previous = NULL;
    int len = length();
    for (int i = 0; i < len - 1; ++i) {
        p = sentinel->next;
        previous = sentinel;
        for (int j = 0; j < len - 1 - i; ++j) {
            if (p->value > p->next->value) {
                previous->next = p->next;
                p->next = p->next->next;
                previous->next->next = p;
            } else {
                p = p->next;
            }
            previous = previous->next;
        }
    }
}

void reverse() {
    LinkedNode *p = sentinel->next;
    LinkedNode *previous = NULL;
    LinkedNode *temporary = NULL;
    while (p != NULL) {
        temporary = p->next;
        p->next = previous;
        previous = p;
        p = temporary;
    }
    sentinel->next = previous;
}

bool isEmpty(){
    if (sentinel->next == NULL) {
        return true;
    }
    return false;
}

