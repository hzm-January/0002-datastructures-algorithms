//
// Created by asus on 2019/8/18.
//

#ifndef DATA_STRUCTURE_C_UDADJACENTLIST_H
#define DATA_STRUCTURE_C_UDADJACENTLIST_H
#define MAX_VERTICES 10

#include "../../../graph.h"

typedef struct GRAPH_EDGE {
    int dest; // 邻接顶点
    int weight; // 权重
    struct GRAPH_EDGE *link; // 下一条边
} Edge;

typedef struct GRAPH_VERTEX {
    int value; // 顶点值
    Edge * firstEdge; // 顶点的第一条边
} Vertex;

typedef struct GRAPH {
    int num_vertices;
    int num_edges;
    Vertex vertices[MAX_VERTICES];
}Graph;
Graph * gh;
#endif //DATA_STRUCTURE_C_UDADJACENTLIST_H
