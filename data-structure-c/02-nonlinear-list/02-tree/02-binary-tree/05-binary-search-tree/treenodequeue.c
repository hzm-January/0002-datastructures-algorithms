//
// Created by asus on 2019/8/9.
//

#include "treenodequeue.h"

void enqueue(TreeNode *value) {
    QueueTreeNode *newNode = (QueueTreeNode *) malloc(sizeof(QueueTreeNode));
    newNode->value = value;
    newNode->next = NULL;
    if (queueSentinel == NULL) {
        queueSentinel = (QueueTreeNode *) malloc(sizeof(QueueTreeNode));
        queueSentinel->value = NULL;
        queueSentinel->next = newNode;
        return;
    }
    QueueTreeNode *p = queueSentinel;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

TreeNode *dequeue() {
    if (isEmpty()) {
        return NULL;
    }
    QueueTreeNode *delNode = queueSentinel->next;
    queueSentinel->next = delNode->next;
    return delNode->value;
}

bool isEmpty() {
    if (queueSentinel->next == NULL) {
        return true;
    }
    return false;
}

int size() {
    if (isEmpty()) {
        return 0;
    }
    int count = 0;
    QueueTreeNode *p = queueSentinel;
    while (p->next != NULL) {
        p = p->next;
        count++;
    }
    return count;
}