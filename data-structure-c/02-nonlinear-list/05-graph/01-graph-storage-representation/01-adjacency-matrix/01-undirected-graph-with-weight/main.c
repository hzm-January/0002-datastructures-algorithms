//
// Created by asus on 2019/8/13.
//
#include "adjacencymatrix.h"

int main(int argc, char *argv[]) {
    graph();
    insertVertex(1);
    insertVertex(2);
//    insertVertex(56);
    insertEdge(1, 2, 10);
    insertEdge(5, 6, 3);
    insertEdge(5, 7, 10);
    insertEdge(5, 8, 11);
    removeVertex(1);
    printf("The graph is empty? %d\n", isEmpty());
    // test the method which return the edges weight
    printf("The edges(from a to b) weight is :  %d\n", weight(5, 6));
    printf("fist neighbor vertex :  %d\n", firstNeighbor(5));
    printf("next neighbor vertex :  %d\n", nextNeighbor(5, 6));
}