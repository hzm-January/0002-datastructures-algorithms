//
// Created by hzm on 2019/6/24.
//
#include "priorityqueue.h"
int main(int argc, char *argv[]){
    // initialize
//    printf("%p\n", queue);
    for (int i = 0; i < MAX_SIZE; ++i) {
//        printf("%p\n", queue[i]);
        queue[i] = (LinkNode *) malloc(sizeof(LinkNode));
//        printf("%p\n", queue[i]);
    }
    enQueue(1, 1);
    output();
    enQueue(2, 2);
    output();
    enQueue(3, 3);
    output();
    enQueue(4, 2);
    output();
    enQueue(5, 1);
    output();
    deQueue();
    deQueue();
    output();
    return 0;
}
