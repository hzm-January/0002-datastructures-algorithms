//
// Created by hzm on 2019/6/18.
//
#include "linkedqueue.h"
int main(int argc, char *argv[]) {

    sentinel = (LinkNode*)malloc(sizeof(LinkNode));
    sentinel->next = NULL;
    sentinel->value = -1;
    enQueue(0);
    enQueue(1);
    enQueue(2);
    output();
    printf("%d\n", getFront());
    printf("%d\n", getFront());
    output();
//    deQueue();
//    output();
//    deQueue();
//    output();
//    deQueue();
//    output();
//    deQueue();
    return 0;
};
