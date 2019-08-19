//
// Created by asus on 2019/8/18.
//
#include "udadjacentlist.h"
int main(int argc, char * argv[]){

    graph();
    insertVertex(3);
    insertVertex(2);
    insertVertex(1);
    insertEdge(1, 2, 12);
    insertEdge(2, 3, 12);
    insertEdge(4, 3, 12);
//    removeVertex(1);
    printf("the first edge: %d\n",firstNeighbor(1));
    printf("the next edge: %d\n",nextNeighbor(1, 0));
    return 0;

}
