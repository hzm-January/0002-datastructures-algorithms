//
// Created by asus on 2019/8/14.
//

#include "adjacencylist.h"
int main(int argc, char *argv[]) {

    graph();
    insertVertex(1);
    insertVertex(2);
    insertVertex(3);
//    insertVertex(3);
//    insertVertex(20);
    insertEdge(2, 3, 11);
    insertEdge(2, 4, 11);
    insertEdge(4, 2, 33);
    removeVertex(1);
    removeVertex(4);
    return 0;
}