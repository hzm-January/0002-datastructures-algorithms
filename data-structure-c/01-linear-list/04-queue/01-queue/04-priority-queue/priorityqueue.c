//
// Created by hzm on 2019/6/24.
//

#include "priorityqueue.h"

bool enQueue(int value, int priority) {
    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->value = value;
    newNode->priority = priority;
    newNode->next = NULL;
    queue[tail++] = newNode;
    adjust();
}

int deQueue(){
    LinkNode *delNode = queue[head++];
    int delValue = delNode->value;
    freeNode(delNode);
    return delValue;
}

int getFront();
void freeNode(LinkNode * delNode){
    if (delNode != NULL) {
        free(delNode);
        delNode = NULL;
    }
}
bool isEmpty() {
    if (tail == head) {
        printf("the queue is empty...");
        return true;
    }
    return false;
}

bool isFull() {
    if ((tail + 1) % MAX_SIZE == head) {
        printf("the queue is full...");
        return true;
    }
    return false;
}

int getSize();

void output() {
    printf("START|");
    for (int i = head; i != tail; i = (i + 1) % MAX_SIZE) {
        printf("%d|%d|%d\t", i, queue[i]->priority, queue[i]->value);
    }
    printf("|END\n");
}

void adjust() {
    //冒泡排序
    for (int i = head; i != tail; i = (i + 1) % MAX_SIZE) {
        bool flag = false;
        for (int j = head; j != (tail - i - 1 + MAX_SIZE) % MAX_SIZE; j = (j + 1) % MAX_SIZE) {
            if (queue[j]->priority > queue[j + 1]->priority) {
                LinkNode *temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}