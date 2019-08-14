//
// Created by asus on 2019/8/14.
//

#ifndef DATA_STRUCTURE_C_ADJACENCYLIST_H
#define DATA_STRUCTURE_C_ADJACENCYLIST_H
#define MAX_VERTICES 10

#include "../../graph.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GRAPH_EDGE{
    int weight;
    struct GRAPH_EDGE * link;
    int adjacency;
} EDGE;

typedef struct GRAPH_VERTEX{
    int value;
    EDGE * adjacency;
} VERTEX;
VERTEX * vertices[10]; // the array of vertices
int num_vertices; // the size of vertices array
#endif //DATA_STRUCTURE_C_ADJACENCYLIST_H
