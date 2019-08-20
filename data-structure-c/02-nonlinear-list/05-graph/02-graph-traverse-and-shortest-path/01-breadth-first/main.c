//
// Created by asus on 2019/8/19.
//
#include "breadthfirsttraverse.h"

int main(int argc, char *argv[]) {

    initializeQueue();
    graph();
    insertVertex(3);
    insertVertex(2);
    insertVertex(1);
    insertEdge(1, 2, 12);
    insertEdge(2, 3, 12);
    insertEdge(4, 3, 12);
    bftall();
    printf("\n");
    bfs(0, 2);
    printf("\n");
    bfs(0, 3);
    destroyQueue();
    return 0;
}
