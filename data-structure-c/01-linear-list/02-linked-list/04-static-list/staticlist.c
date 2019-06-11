//
// Created by asus on 2019/5/31.
//
#include "staticlist.h"

bool insert(int index, int value) {
    if (index > MAX_SIZE || index < 0) {
        printf("index out of bounds");
        exit(1);
    }
    // locate on the index
    int p = 0;
    int j = 1;
    while ((p = list[p]->next) != -1 && j < index) {
        j++;
    }
    if (index == 0) {
        p = 0;
    }
    if (p == -1) {
        printf("index out of bounds");
        exit(1);
    }
    list[availableIndex]->value = value;
    int temp = availableIndex;
    availableIndex = list[availableIndex]->next;
    list[temp]->next = list[p]->next;
    list[p]->next = temp;
    return true;
}

int delete(int index) {
    // locate on the index
    int p = list[0]->next;
    int j = 1;
    //找到p的前一个节点
    while (list[p]->next != -1 && j < index) {
        p = list[p]->next;
        j++;
    }
    if (list[p]->next == -1) {
        printf("index out of bounds");
        exit(1);
    }
    if (index == 1) {
        p = 0;
    }
    int delIndex = list[p]->next;
    LinkNode *delNode = list[delIndex];
    list[p]->next = delNode->next;
    int delVal = delNode->value;
    delNode->value = -1;
    delNode->next = availableIndex;
    availableIndex = delIndex;
//    freeNode(delNode);
    return delVal;
}

void initial() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        list[i] = (LinkNode *) malloc(sizeof(LinkNode));
        list[i]->next = i + 1;
    }
    list[0]->next = -1;
    list[MAX_SIZE - 1]->next = -1;
    availableIndex = 1;
}

void output() {
    printf("start|\t");
    int p = 0;
    int i = 0;
    while ((p = list[p]->next) != -1) {
        printf("%d|%d\t", i++, list[p]->value);
    }
    printf("\t|end\n");
}

