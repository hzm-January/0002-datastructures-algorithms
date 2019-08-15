//
// Created by asus on 2019/8/14.
//

#include "adjacencylist.h"

// create an empty graph
void graph() {
    memset(vertices, 0, sizeof(VERTEX) * MAX_VERTICES);
}

bool isOutOfRange(int v) {
    if (v > MAX_VERTICES || v < 0) {
        printf(" the vertex value is out-of range");
        exit(1);
    }
    return false;
}

bool isFullVertices() {
    if (num_vertices > MAX_VERTICES) {
        printf(" the vertex value is greater than maximum of vertices ");
        exit(1);
    }
    return false;
}

// insert a vertex to the graph
void insertVertex(int v) {
    isFullVertices();
    isOutOfRange(v);
    // check whether the vertex has already been in the graph
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
void insertEdge(int v1, int v2, int weight) {
    // check whether v1 and v2 have already been in graph
    int i = -1;
    int j = -1;
    for (int k = 0; k < num_vertices; ++k) {
        if (vertices[k]->value == v1) i = k;
        if (vertices[k]->value == v2) j = k;
    }
    // if v1 or v2 haven't been in graph, insert it.
    if (i == -1) {
        isFullVertices();
        VERTEX *vertex1 = (VERTEX *) malloc(sizeof(VERTEX));
        vertex1->adjacency = NULL;
        vertex1->value = v2;
        vertices[num_vertices] = vertex1;
        i = num_vertices++;
    }
    if (j == -1) {
        isFullVertices();
        VERTEX *vertex2 = (VERTEX *) malloc(sizeof(VERTEX));
        vertex2->adjacency = NULL;
        vertex2->value = v2;
        vertices[num_vertices++] = vertex2;
        j = num_vertices;
    }
    // insert the edge connected from v1 to v2 to edges
//    VERTEX *v1Head = vertices[i];
    // iterate v1 link to the end vertex;
    EDGE *p = vertices[i]->adjacency;
    while (p != NULL && p->link != NULL && p->cost != v2) {
        p = p->link;
    }
    if (p == NULL || p->link == NULL) {
        EDGE *edge = (EDGE *) malloc(sizeof(EDGE));
        edge->cost = v2;
        edge->link = NULL;
        edge->weight = weight;
        if (p == NULL) {
            vertices[i]->adjacency = edge;
        } else {
            p->link = edge;
        }
    } else {
        // modify the weight of the edge
        p->cost = weight;
    }

}

// delete a vertex in the graph and delete all the edges associated with it
void removeVertex(int v) {
    // found v in vertices
    int j = -1;
    for (int i = 0; i < num_vertices; ++i) {
        if (vertices[i]->value == v) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        printf("the vertex have not been in graph");
        exit(1);
    }
    // remove the vertex and modify its adjacent vertices,
    EDGE* p = vertices[j]->adjacency;
    if (p != NULL) {
//        while (p->link != NULL) {
//            //
//            int k = -1;
//            for (int i = 0; i < num_vertices; ++i) {
//                if (vertices[i]->value == p->cost) {
//                    k = i;
//                    break;
//                }
//            }
//            if (k != -1) {
//                EDGE * pk = vertices[k]->adjacency;
//                while (pk != NULL&&pk->) {
//
//                }
//            }
//            p = p->link;
//        }
    }
}

bool isEmpty(); // check whether or not the graph is empty
int weight(int v1, int v2); // return the weight of the edge which is created by connecting vertex v1 to vertex v2
int firstNeighbor(int v); //return the first neighbor vertex
int nextNeighbor(int v, int w); // return the neighbor vertex which is next w that is a adjacent vertex with v