//
// Created by asus on 2019/6/18.
//

#include "circularqueue.h"

void enQueue(int value) {
    isFull();
    queue[tail++] = value;
}

int deQueue() {
    isEmpty();
    return queue[head++];
}

int getFront();

bool isEmpty() {
    if (head == tail) {
        printf(" the queue is full ");
        exit(0);
    }
    return false;
}

bool isFull() {
    if ((tail + 1) % MAX_SIZE == head) {
        printf(" the queue is full ");
        exit(0);
    }
    return false;
}

int getSize() {
    return (tail - head + MAX_SIZE) % MAX_SIZE;
}

void output() {
//    printf("%d\n", getSize());
    printf("start|\t");
    for (int i = head; i != tail; i = (i + 1) % MAX_SIZE) {
        printf("%d|%d\t", i, queue[i]);
    }
    printf("|end\n");
}