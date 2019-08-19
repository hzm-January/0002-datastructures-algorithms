//
// Created by asus on 2019/8/18.
//

#include "udadjacentlist.h"

bool isFull();

int locateVertex(int v);

int indexAndInsert(int v1);

void insertEdgeToVertexList(int v1, int v2, int weight);

// insert a vertex to the graph
void insertVertex(int vertex) {
    isFull();
    Vertex vt;
    vt.value = vertex;
    vt.firstEdge = NULL;
    gh->vertices[gh->num_vertices++] = vt;
}

// insert a edge to the graph
void insertEdge(int v1, int v2, int weight) {
    insertEdgeToVertexList(v1, v2, weight);
    insertEdgeToVertexList(v2, v1, weight);
}

void insertEdgeToVertexList(int v1, int v2, int weight) {
    int index1 = indexAndInsert(v1);
    int index2 = indexAndInsert(v2);
    Edge *v1First = gh->vertices[index1].firstEdge;
    Edge *p = v1First;
    while (p != NULL && p->dest != index2) {
        p = p->link;
    }
    if (p != NULL) {
        p->weight = weight; //update the weight of the edge
        return;
    }
    Edge *newEdge = (Edge *) malloc(sizeof(Edge));
    newEdge->dest = index2;
    newEdge->link = v1First;
    newEdge->weight = weight;
    gh->vertices[index1].firstEdge = newEdge;
    gh->num_edges++;
}


int indexAndInsert(int v) {
    int i = locateVertex(v);
    if (i == -1) {
        isFull();
        Vertex vertex;
        vertex.value = v;
        vertex.firstEdge = NULL;
        gh->vertices[gh->num_vertices] = vertex;
        i = gh->num_vertices++;
    }
    return i;
}

int locateVertex(int v) {
    int i = -1;
    for (int j = 0; j < gh->num_vertices; ++j) {
        if (gh->vertices[j].value == v) {
            i = j;
            break;
        }
    }
    return i;
}

// create an empty graph
void graph() {
    gh = (Graph *) malloc(sizeof(Graph));
    gh->num_vertices = 0;
    gh->num_edges = 0;
    memset(gh->vertices, 0, sizeof(Vertex) * MAX_VERTICES);
    for (int i = 0; i < MAX_VERTICES; ++i) {
        gh->vertices[i].value = -1;
    }
}

void destroy() {
    if (gh != NULL) {
        free(gh);
        gh = NULL;
    }
}

bool isFull() {
    if (gh->num_vertices >= MAX_VERTICES) {
        printf(" the graph is full ");
        exit(1);
    }
    return false;
}

void deleteSymmetricalEdge(int v, int adjacentVertexIndex);

// delete a vertex in the graph and delete all the edges associated with it
void removeVertex(int v) {
    // locate the vertex
    int vIndex = locateVertex(v);
    if (vIndex == -1) {
        printf(" the vertex does not exist in the graph ");
        exit(1);
    }
    // delete the vertex and the edges associated with the vertex
    Edge *firstEdge = gh->vertices[vIndex].firstEdge;
    Edge *p = firstEdge;
    while (p != NULL) {
        Edge *temp = p;
        int adjacentVertexIndex = p->dest;
        deleteSymmetricalEdge(vIndex, adjacentVertexIndex);
        p = p->link;
        gh->vertices[vIndex].firstEdge = temp->link;
        free(temp);
        temp = NULL;
        gh->num_edges--;
    }
    // 使用最后一个顶点搬移到刚删除的坐标，弥补删除造成的数组不连续
    gh->vertices[vIndex].value = gh->vertices[gh->num_vertices - 1].value;
    p = gh->vertices[vIndex].firstEdge = gh->vertices[gh->num_vertices - 1].firstEdge;
    Edge *s;
    while (p != NULL) {
        s = gh->vertices[p->dest].firstEdge;
        while (s != NULL && s->dest != gh->num_vertices - 1) {
            s = s->link;
        }
        if (s != NULL) s->dest = vIndex;
        p = p->link;
    }
    // 将最后一个元素进行初始化重置
    gh->vertices[gh->num_vertices - 1].value = 0;
    gh->vertices[gh->num_vertices - 1].firstEdge = NULL;
    gh->num_vertices--;
}

// 删除v的邻接点list中跟v组成的边， 总边数-1
void deleteSymmetricalEdge(int vIndex, int adjacentVertexIndex) {
    Edge *firstEdgeAd = gh->vertices[adjacentVertexIndex].firstEdge;
    Edge *q = firstEdgeAd;
    Edge *qp = NULL;
    while (q != NULL && q->dest != vIndex) {
        qp = q;
        q = q->link;
    }
    if (qp == NULL) {
        // if the first edge of the vertex associated with v, delete it.
        gh->vertices[adjacentVertexIndex].firstEdge = q->link;
    } else {
        qp->link = q->link;
    }
    free(q);
    q = NULL;
    gh->num_edges--;
}
// check whether or not the graph is empty
bool isEmpty() {
    if (gh->num_vertices == 0) {
        return true;
    }
    return false;
}

int weight(int v1, int v2); // return the weight of the edge which is created by connecting vertex v1 to vertex v2
/**
 *  return the index of the first neighbor vertex
 */
int firstNeighbor(int v) {
    Edge *fv = gh->vertices[v].firstEdge;
    if (fv == NULL) {
        return -1;
    }
    return fv->dest;
}

/**
 * return the neighbor vertex which is next w that is a adjacent vertex with v
 */
int nextNeighbor(int v, int w) {
    Edge *fv = gh->vertices[v].firstEdge;
    while (fv != NULL && fv->dest != w) {
        fv = fv->link;
    }
    if (fv == NULL || fv->link == NULL) {
        return -1;
    } else {
        return fv->link->dest;
    }
}