//
// Created by asus on 2019/8/19.
//
#include "breadthfirsttraverse.h"

int main(int argc, char * argv[]){

    initializeQueue();

//    enQueue(0);
//    enQueue(1);
//    enQueue(2);
//    output();
//    output();
//    deQueue();
//    output();
//    deQueue();
//    output();
//    deQueue();
//    printf("%d\n", getFront());
//    printf("%d\n", getFront());
//    output();
    graph();
    insertVertex(3);
    insertVertex(2);
    insertVertex(1);
    insertEdge(1, 2, 12);
    insertEdge(2, 3, 12);
    insertEdge(4, 3, 12);
    bftall();
    destroyQueue();
    return 0;
}
