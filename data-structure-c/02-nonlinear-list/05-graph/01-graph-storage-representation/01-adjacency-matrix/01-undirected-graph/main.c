//
// Created by asus on 2019/8/13.
//
#include "adjacencymatrix.h"

int main(int argc, char *argv[]) {
    graph();
    insertVertex(1);
    insertVertex(2);
    insertVertex(56);
    insertEdge(1, 2, 10);
    insertEdge(5, 6, 10);
    printf("The graph is empty? %d", isEmpty());
}