//
// Created by hzm on 2019/5/27.
//
#include <stdlib.h>
#include <stdio.h>
//#include "../linknode.h"
//#include "../../linearlist.h"
#include "circularlistwithtail.h"

bool insert(int index, int value) {
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->value = value;
    newNode->next = NULL;
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
        return true;
    }
    if (index == 0) {
        newNode->next = tail->next;
        tail->next = newNode;
        return true;
    }
    LinkNode *p = tail->next;
    for (int i = 0; i < index - 1; ++i) {
        if (p == tail) {
            printf("index out of bounds");
            exit(1);
        }
        p = p->next;
    }

    newNode->next = p->next;
    p->next = newNode;
    if (p == tail) {
        tail = newNode;
    }
    return true;
}

int delete(int index) {
    checkTail();
    checkIndex(index);
    if (index == 0) {
        LinkNode *temp = tail->next;
        tail->next = temp->next;
        int delVal = temp->value;
        return delVal;
    }
    LinkNode *p = tail->next;
    for (int i = 0; i < index - 1; ++i) {
        if (p == tail) {
            printf("index out of bounds");
            exit(1);
        }
        p = p->next;
    }
    LinkNode *temp = p->next;
    p->next = temp->next;
    int delVal = temp->value;
    if (temp == tail) {
        tail = p;
    }
    freeNode(temp);
    return delVal;
}

int deleteByVal(int value) {
    return delete(search(value));
}

int search(int value) {
    checkTail();
    LinkNode *p = tail->next;
    int index = 0;

    while (p != tail && p->value != value) {
        p=p->next;
        index++;
    }
    if (p == tail) {
        if (p->value == value) {
            return index;
        } else {
            return -1;
        }
    }
    return index;
}

void freeNode(LinkNode *delNode) {
    if (delNode != NULL) {
        free(delNode);
        delNode == NULL;
    }
}

void output() {
    checkTail();
    printf("start|\t");
    LinkNode *p = tail->next;
    int index = 0;
    while (p != tail) {
        printf("%d|%d\t", index++, p->value);
        p = p->next;
    }
    printf("%d|%d\t|end\n", index, p->value);
}

void checkTail() {
    if (tail == NULL) {
        printf("linked list is empty");
        exit(1);
    }
}

void checkIndex(int index) {
    if (index < 0) {
        printf("index is illegal");
        exit(1);
    }
};

int length() {
    if (tail == NULL) {
        return 0;
    }
    LinkNode *p = tail->next;
    int i = 0;
    while (p != tail) {
        p = p->next;
        i++;
    }
    return ++i;
};

