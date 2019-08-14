//
// Created by asus on 2019/8/14.
//

#include "adjacencylist.h"

// create an empty graph
void graph() {
    memset(vertices, 0, sizeof(VERTEX) * MAX_VERTICES);
}

void isOutOfRange(int v) {
    if (v > MAX_VERTICES || v < 0) {
        printf(" the vertex value is out-of range");
        exit(1);
    }
}

// insert a vertex to the graph
void insertVertex(int v) {
    if (num_vertices > MAX_VERTICES) {
        printf(" the vertex value is greater than maximum of vertices ");
        exit(1);
    }
    isOutOfRange(v);
    // check whether the vertex exist in the graph
    for (int i = 0; i < num_vertices; ++i) {
        if (vertices[i]->value == v) {
            printf(" the vertex exist in the graph ");
            exit(1);
        }
    }
    VERTEX *vertex = (VERTEX *) malloc(sizeof(VERTEX));
    vertex->value = v;
    vertex->adjacency = NULL;
    // insert the vertex into vertices array
    vertices[num_vertices++] = vertex;
}
// insert a edge to the graph
void insertEdge(int v1, int v2, int weight);
void removeVertex(int v); // delete a vertex in the graph and delete all the edges associated with it
bool isEmpty(); // check whether or not the graph is empty
int weight(int v1, int v2); // return the weight of the edge which is created by connecting vertex v1 to vertex v2
int firstNeighbor(int v); //return the first neighbor vertex
int nextNeighbor(int v, int w); // return the neighbor vertex which is next w that is a adjacent vertex with v