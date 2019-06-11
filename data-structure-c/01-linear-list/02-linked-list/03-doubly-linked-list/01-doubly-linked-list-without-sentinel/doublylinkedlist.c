//
// Created by asus on 2019/5/28.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../../linearlist.h"
#include "doublylinkedlist.h"

bool insert(int index, int value) {
    checkIndex(index);
    LinkedNode *newNode = (LinkedNode *) malloc(sizeof(LinkedNode *));
    newNode->previous = NULL;
    newNode->next = NULL;
    newNode->value = value;
    if (head == NULL) {
        if (index != 0) {
            printf("index out of bounds");
            exit(1);
        } else {
            head = newNode;
            return true;
        }
    }
    if (index == 0) {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
        return true;
    }
    LinkedNode *p = head;
    for (int j = 0; j < index - 1; j++) {
        if (p == NULL) {
            printf("index out of bounds");
            exit(1);
        }
        p = p->next;
    }
    if (p->next != NULL) {
        p->next->previous = newNode; //后继节点更新前驱指针
    }
    newNode->next = p->next; //新节点更新后继指针
    newNode->previous = p; //新节点更新前驱指针
    p->next = newNode; //前驱节点更新后继指针
    return true;
}
int delete(int index) {
    checkIndex(index);
    checkHead();
    if (index == 0) {
        LinkedNode * temp = head;
        if (temp->next!=NULL) {
            temp->next->previous = NULL;
        }
        head = temp->next;
        int delVal = temp->value;
        freeNode(temp);
        return delVal;
    }
    LinkedNode *p = head;
    for (int i = 0; i < index - 1; ++i) {
        p = p->next;
        if (p->next == NULL) {
            printf("index out of bounds");
            exit(1);
        }
    }
    LinkedNode *temp = p->next;
    p->next = temp->next;
    if (temp->next != NULL) {
        temp->next->previous = p;
    }
    int delVal = temp->value;
    freeNode(temp);
    return delVal;
}
void freeNode(LinkedNode * delNode){
    if (delNode != NULL) {
        free(delNode);
        delNode = NULL;
    }
}
void output() {
    checkHead();
    LinkedNode *p = head;
    int i = 0;
    printf("start|\t");
    while (p != NULL) {
        printf("%d|%d\t", i, p->value);
        p = p->next;
        i++;
    }
    printf("|end\n");
}

bool checkIndex(int index) {
    if (index < 0) {
        printf("index is illegal");
        exit(1);
    }
}

bool checkHead() {
    if (head == NULL) {
        printf("head is null");
        exit(1);
    }
}

