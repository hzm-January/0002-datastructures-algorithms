//
// Created by asus on 2019/8/16.
//

#include "adjacencymultilist.h"

// create an empty graph
void graph() {
    gh = (Graph *) malloc(sizeof(Graph));
    memset(gh->vertices, 0, sizeof(Vertex) * MAX_VERTICES_NUM);
    gh->vernum = 0;
    gh->edgenum = 0;
}

// insert a vertex to the graph
void insertVertex(int value) {
    if (gh->vernum >= MAX_VERTICES_NUM) {
        printf(" the quantity of vertices exceeds the maximum allowed ");
        exit(1);
    }
    Vertex v;
    v.value = value;
    v.firstedge = NULL;
    gh->vertices[gh->vernum++] = v;
}

int checkAndInsert(int v1);

// insert a edge to the graph
void insertEdge(int v1, int v2, int weight) {
    // check whether the vertex has been already in the array of vetices of the graph or not
    int v1Index = checkAndInsert(v1);
    int v2Index = checkAndInsert(v2);

    // make v1<v2 to ensure that we does not insert same edge(i.e., a-b, b-a)
    int temp;
    if (v1 > v2) {
        temp = v1;
        v1 = v2;
        v2 = temp;
    }
    // insert Edge to the list which contains v1 or v2
    Edge *pEdge = gh->vertices[v1Index].firstedge;
    while (pEdge != NULL) {
        if (pEdge->i == v1 && pEdge->j != v2) { //pEdge->i == v1 && pEdge->j != v2
            pEdge = pEdge->ilink;
        } else if (pEdge->j == v1) { //pEdge->i != v2 && pEdge->j == v1
            pEdge = pEdge->jlink;
        } else {
            //pEdge->i == v1 && pEdge->j == v2
            printf(" the edge has has been already in the array of vetices of the graph ");
            exit(1);
        }
    }
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->i = v1;
    edge->j = v2;
    edge->ilink = gh->vertices[v1Index].firstedge;
    edge->jlink = gh->vertices[v2Index].firstedge;
    gh->vertices[v1Index].firstedge = edge;
    gh->vertices[v2Index].firstedge = edge;

}

int checkAndInsert(int v) {
    int i = -1;
    for (int k = 0; k < gh->vernum; ++k) {
        if (gh->vertices[k].value == v) i = k;
    }

    if (i == -1) {
        Vertex vertex;
        vertex.value = v;
        vertex.firstedge = NULL;
        gh->vertices[gh->vernum] = vertex;
        i = gh->vernum++;
    }
    return i;
}

void removeVertex(int v); // delete a vertex in the graph and delete all the edges associated with it
bool isEmpty(); // check whether or not the graph is empty
int weight(int v1, int v2); // return the weight of the edge which is created by connecting vertex v1 to vertex v2
int firstNeighbor(int v); //return the first neighbor vertex
int nextNeighbor(int v, int w); // return the neighbor vertex which is next w that is a adjacent vertex with v