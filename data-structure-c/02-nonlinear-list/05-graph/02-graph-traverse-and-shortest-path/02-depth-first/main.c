//
// Created by asus on 2019/8/20.
//
#include "depthfirsttraverse.h"
int main(){

    graph();
    insertVertex(3);
    insertVertex(2);
    insertVertex(1);
    insertEdge(1, 2, 12);
    insertEdge(2, 3, 12);
    insertEdge(4, 3, 12);
    bftall();


    return 0;
};