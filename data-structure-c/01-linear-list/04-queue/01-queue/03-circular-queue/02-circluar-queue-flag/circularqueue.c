//
// Created by asus on 2019/6/24.
//

#include "circularqueue.h"

void enQueue(int value) {
    //TODO: check the queue whether is full
    isFull();
    queue[tail] = value;
    tail = (tail + 1) % MAX_SIZE;
    flag = true;
}

int deQueue() {
    isEmpty();
    flag = false;
    int value = queue[head];
    head = (head + 1) % MAX_SIZE;
    return value;
}

int getFront() {
    return queue[head];
}

bool isEmpty() {
    if (head == tail && !flag) {
        printf(" the queue is empty ...");
        exit(0);
    }
    return false;
}

bool isFull() {
    if (tail == head && flag) {
        printf(" the queue is full ...");
        exit(0);
    }
    return false;
}

int getSize() {
    return tail - head;
}

void output() {
    printf("start|\t");
    for (int i = head; i != tail; i = (i + 1) % MAX_SIZE) {
        printf("%d|%d\t", i, queue[i]);
    }
    printf("|end\n");
}