//
// Created by asus on 2019/8/19.
//
#include "breadthfirstsearch.h"

int main(int argc, char *argv[]) {

    graph();
    initialize();
    insertVertex(3);
    insertVertex(2);
    insertVertex(1);
    insertEdge(1, 2, 12);
    insertEdge(2, 3, 12);
    insertEdge(4, 3, 12);
//    bftall();
//    printf("\n");
//    bfs(0, 2);
//    printf("\n");
//    bfs(0, 3);
    bfs(1, 3);
    printf("\n");
    bfs(4, 1);
    destroyQueue();
    return 0;
}
