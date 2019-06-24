//
// Created by hzm on 2019/6/17.
//

#include "sequentialqueue.h"

void enQueue(int value) {
    if (tail == MAX_SIZE) {
        if (head == 0) {
            printf(" the queue is full ");
            exit(0);
        }
        // move
        for (int i = head; i < tail; ++i) {
            queue[i - head] = queue[i];
        }
        tail -= head;
        head = 0;
    }
    queue[tail++] = value;
}

int deQueue() {
    if (head == tail) {
        printf(" the queue is empty ");
        exit(0);
    }
    return queue[head++];
}

int getFront() {
    if (head == tail) {
        printf(" the queue is empty ");
        exit(0);
    }
    return queue[head];
}

bool isEmpty() {
    if (head == tail) {
        return true;
    }
    return false;
}

bool isFull() {
    if (tail == MAX_SIZE && head == 0) {
        return true;
    }
    return false;
}

int getSize() {
    return tail - head;
}

void output(){
    printf("start|\t");
    for (int i = head; i < tail; ++i) {
        printf("%d|%d\t", i, queue[i]);
    }
    printf("|end\n");
}
