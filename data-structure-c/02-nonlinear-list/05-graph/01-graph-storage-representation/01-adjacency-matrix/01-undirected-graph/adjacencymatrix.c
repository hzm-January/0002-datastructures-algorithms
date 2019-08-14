//
// Created by asus on 2019/8/13.
//

#include "adjacencymatrix.h"

// create an empty graph
void graph() {
    // initialize the array which is used to store vertices of the graph
    memset(vertices, -1, sizeof(int) * MAX_VERTICES);
    // initialize the two-dimension array which is used to store edges of the graph
    for (int i = 0; i < MAX_VERTICES; ++i) {
        for (int j = 0; j < MAX_VERTICES; ++j) {
            if (i == j) {
                edges[i][j] = 0;
            } else {
                edges[i][j] = DEFAULT_WEIGHT;
            }
        }
    }
}

// insert a vertex to the graph
void insertVertex(int vertex) {
    if (vertex >= MAX_VERTICES) {
        printf(" the vertices is full ");
        exit(-1);
    }
    vertices[num_vertices++] = vertex;
}

// insert a edge to the graph
void insertEdge(int v1, int v2, int weight) {
    if (v1 > MAX_VERTICES || v1 < 0 || v2 < 0 || v2 > MAX_VERTICES) {
        printf("the vertex is illegal");
        exit(1);
    }
    // check whether v1 and v2 existed int the graph
    int j = -1, k = -1;
    for (int i = 0; i < num_vertices; ++i) {
        if (vertices[i] == v1) j = i;
        if (vertices[i] == v2) k = i;
    }
    if (j == -1) vertices[num_vertices++] = v1;
    if (k == -1) vertices[num_vertices++] = v2;

    // add the edge which is connected from v1 to v2 to the vertices array
    edges[v1][v2] = edges[v2][v1] = weight;
    num_edges++;
}

// delete a vertex in the graph and delete all the edges associated with it
void removeVertex(int v) {
    // delete the vertex from the vertices array
    int j = -1;
    for (int i = 0; i < num_vertices; ++i) {
        if (vertices[i] == v) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        printf(" the vertex does not exist in the vertices array... ");
        exit(1);
    }
    num_vertices--;
    for (int i = j; i < num_vertices; ++i) {
        vertices[i] = vertices[i + 1];
    }
    // remove all the edges associated with this vertex from the matrix
    for (int k = 0; k < MAX_VERTICES; ++k) {
        // reset the edge weight whose x coordinate value is v
        if (v == k) {
            edges[v][k] = 0;
            continue;
        }
        edges[v][k] = -1;
    }
    for (int k = 0; k < MAX_VERTICES; ++k) {
        // reset the edge weight whose y coordinate value is v
        if (v == k) {
            edges[v][k] = 0;
            continue;
        }
        edges[k][v] = -1;
    }

}
// check whether or not the graph is empty
bool isEmpty() {
    if (num_vertices <= 0) return true;
    return false;
}