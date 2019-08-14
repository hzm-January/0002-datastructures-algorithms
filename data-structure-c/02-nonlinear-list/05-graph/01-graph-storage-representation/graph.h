//
// Created by asus on 2019/8/13.
//

#ifndef DATA_STRUCTURE_C_GRAPH_H
#define DATA_STRUCTURE_C_GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void graph(); // create an empty graph
void insertVertex(int vertex); // insert a vertex to the graph
void insertEdge(int v1, int v2, int weight); // insert a edge to the graph
void removeVertex(int v); // delete a vertex in the graph and delete all the edges associated with it
bool isEmpty(); // check whether or not the graph is empty
int weight(int v1, int v2); // return the weight of the edge which is created by connecting vertex v1 to vertex v2
int firstNeighbor(int v); //return the first neighbor vertex
int nextNeighbor(int v, int w); // return the neighbor vertex which is next w that is a adjacent vertex with v
#endif //DATA_STRUCTURE_C_GRAPH_H
