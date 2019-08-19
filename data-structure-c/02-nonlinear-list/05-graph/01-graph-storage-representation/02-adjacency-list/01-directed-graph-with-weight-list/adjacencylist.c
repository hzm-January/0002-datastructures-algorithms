//
// Created by asus on 2019/8/14.
//

#include "adjacencylist.h"

// 删除邻接表和逆邻接表中，v和v对应的边链表
void deleteVertexAndAssociateEdges(int v, VERTEX **vs, int *size);
// 删除邻接表和逆邻接表中，其他不等于v的顶点与v有关系的边
void deleteOtherAssociateEdges(int v, VERTEX **vs, int size);

// insert edge into adjacent list
void insertEdgeToLnk(int v1, int v2, int weight, VERTEX **vs, int *size);

// insert edge into inverse adjacent list
//void insertEdgeToInverse(int v1, int v2, int weight);
// create an empty graph
void graph() {
    memset(vertices, 0, sizeof(VERTEX) * MAX_VERTICES);
    memset(inverse_vertices, 0, sizeof(VERTEX) * MAX_VERTICES);
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
    VERTEX *vertexForInverse = (VERTEX *) malloc(sizeof(VERTEX));
    vertexForInverse->value = v;
    vertexForInverse->adjacency = NULL;
    // insert the vertex into inverse vertices array
    inverse_vertices[num_inverse_vertices++] = vertexForInverse;
}


// insert a edge to the adjacent list
void insertEdge(int v1, int v2, int weight) {
    insertEdgeToLnk(v1, v2, weight, vertices, &num_vertices);
    insertEdgeToLnk(v2, v1, weight, inverse_vertices, &num_inverse_vertices);
}

// insert a edge to the adjacent list
void insertEdgeToLnk(int v1, int v2, int weight, VERTEX **vs, int *size) {
    // check whether v1 and v2 have already been in graph
    int i = -1;
    int j = -1;
    for (int k = 0; k < *size; ++k) {
        if (vs[k]->value == v1) i = k;
        if (vs[k]->value == v2) j = k;
    }
    // if v1 or v2 haven't been in graph, insert it.
    if (i == -1) {
        isFullVertices();
        VERTEX *vertex1 = (VERTEX *) malloc(sizeof(VERTEX));
        vertex1->adjacency = NULL;
        vertex1->value = v1;
        vs[*size] = vertex1;
        i = (*size)++;
    }
    if (j == -1) {
        isFullVertices();
        VERTEX *vertex2 = (VERTEX *) malloc(sizeof(VERTEX));
        vertex2->adjacency = NULL;
        vertex2->value = v2;
        vs[*size] = vertex2;
        j = (*size)++;
    }
    // insert the edge connected from v1 to v2 to edges
//    VERTEX *v1Head = vertices[i];
    // iterate v1 link to the end vertex;
    EDGE *p = vs[i]->adjacency;
    while (p != NULL && p->link != NULL && p->dest != v2) {
        p = p->link;
    }
    if (p == NULL || p->link == NULL) {
        EDGE *edge = (EDGE *) malloc(sizeof(EDGE));
        edge->dest = v2;
        edge->link = NULL;
        edge->weight = weight;
        if (p == NULL) {
            vs[i]->adjacency = edge;
        } else {
            p->link = edge;
        }
    } else {
        // modify the weight of the edge
        p->dest = weight;
    }

}

void deleteVertexAndAssociateEdges(int v, VERTEX **vs, int *size) {
    int j = -1;
    for (int i = 0; i < *size; ++i) {
        if (vs[i]->value == v) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        printf("the vertex have not been in graph");
        exit(1);
    }
    // remove the vertex and modify its adjacent vertices,
    EDGE *p = vs[j]->adjacency;
    EDGE *pp = NULL;
    EDGE *temp = NULL;
    while (p != NULL) {
        temp = p;
        if (p == vs[j]->adjacency) {
            vs[j]->adjacency = NULL;
        } else {
            pp->link = NULL;
        }
        p = temp->link;
        pp = temp;
        // delete the adjacent vertex
        free(temp);
        temp = NULL;
    }

    VERTEX *delTemp = vs[j];
    for (int k = j; k < *size - 1; ++k) {
        vs[k] = vs[k + 1];
    }
    // delete vertex from vertices
    vs[*size - 1] = NULL;
    free(delTemp);
    delTemp = NULL;
    (*size)--;
}




// delete a vertex in the graph and delete all the edges associated with it
void removeVertex(int v) {
    // delete v from vertices
    deleteVertexAndAssociateEdges(v, vertices, &num_vertices);
    // delete v from inverse vertices
    deleteVertexAndAssociateEdges(v, inverse_vertices, &num_inverse_vertices);

    deleteOtherAssociateEdges(v, vertices, num_vertices);
    deleteOtherAssociateEdges(v, inverse_vertices, num_inverse_vertices);
}

void deleteOtherAssociateEdges(int v, VERTEX **vs, int size) {
    for (int i = 0; i < size; ++i) {
        EDGE *p = vs[i]->adjacency;
        EDGE *pp = NULL;
        while (p != NULL) {
            EDGE *delTemp = p;
            if (delTemp->dest == v) {
                if (delTemp == vs[i]->adjacency) {
                    vs[i]->adjacency = NULL;
                } else {
                    pp->link = NULL;
                }
            }
            pp = delTemp;
            p = delTemp->link;
            if (delTemp->dest == v) {
                free(delTemp);
                delTemp = NULL;
            }
        }
    }
}


bool isEmpty(); // check whether or not the graph is empty
int weight(int v1, int v2); // return the weight of the edge which is created by connecting vertex v1 to vertex v2
int firstNeighbor(int v); //return the first neighbor vertex
int nextNeighbor(int v, int w); // return the neighbor vertex which is next w that is a adjacent vertex with v