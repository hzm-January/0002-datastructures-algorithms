//
// Created by asus on 2019/8/16.
//

#ifndef DATA_STRUCTURE_C_ADJACENCYMULTILIST_H
#define DATA_STRUCTURE_C_ADJACENCYMULTILIST_H

#define MAX_VERTICES_NUM 10

#include "../../graph.h"

// edge
typedef struct Edge {
    int mark; // the mark of operation
    int i; // a vertex of the edge
    int j; // the other vertex of the edge
    struct ArcNode *ilink; // the next edge which i is a vertex of
    struct ArcNode *jlink; // the next edge which j is a vertex of
} Edge;

typedef struct Vertex {
    int value;
    Edge *firstedge;
} Vertex;

typedef struct Graph {
    Vertex vertices[MAX_VERTICES_NUM]; // varray filled with vertices
    int vernum; // the number of vertices
    int edgenum;// the number of edges
}Graph;

Graph * gh;
#endif //DATA_STRUCTURE_C_ADJACENCYMULTILIST_H
