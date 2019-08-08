//
// Created by asus on 2019/8/8.
//

#include "linkedqueue.h"

//入队
void enqueue(TreeNode *node) {
    TreeQueueNode *newNode = (TreeQueueNode *) malloc(sizeof(TreeQueueNode));
    newNode->treenode = node;
    newNode->next = NULL;
    if (sentinal == NULL) {
        sentinal = (TreeQueueNode *) malloc(sizeof(TreeQueueNode));
        sentinal->treenode = NULL;
        sentinal->next = newNode;
        return;
    }
    TreeQueueNode *p = sentinal;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    return;
}

//出队
TreeNode *dequeue() {
    if (isEmpty()) {
        return NULL;
    }
//    TreeQueueNode *p = sentinal;
//
//    while (p->next != NULL && p->next->next != NULL) {
//        p = p->next;
//    }
    TreeQueueNode *delNode = sentinal->next;
    sentinal->next = delNode->next;
    return delNode->treenode;
}
//空队列
bool isEmpty() {
    if (sentinal->next == NULL) {
        return true;
    }
    return false;
}