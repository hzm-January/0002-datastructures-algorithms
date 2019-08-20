//
// Created by asus on 2019/8/19.
//

#include "breadthfirstsearch.h"

//void visPrint(int index);
//
//void printPath(int s, int t);
void initialize() {
    // 初始化访问记录数组
    memset(visit, 0, sizeof(bool) * MAX_VERTICES);
    memset(shortest_path, -1, sizeof(int) * MAX_VERTICES);
}
//void bftall() {
//    // 初始化访问记录数组
//    memset(visit, 0, sizeof(bool) * MAX_VERTICES);
//    memset(shortest_path_counter, -1, sizeof(int) * MAX_VERTICES);
//    memset(shortest_path, -1, sizeof(int) * MAX_VERTICES);
//    // 未连通顶点遍历
//    for (int i = 0; i < gh->num_vertices; ++i) {
//        if (!visit[i]) {
//            //TODO: traverse
//            bft(i);
//        }
//    }
//}

//void visPrint(int index) {
//    Vertex vertex = gh->vertices[index];
//    printf("%d\t", vertex.value);
//}
//
//void bft(int vIndex) {
//    enQueue(vIndex);
//    visPrint(vIndex);
//    visit[vIndex] = true;
//    shortest_path_counter[vIndex] = 0;
//    while (!isEmptyQueueNoExit()) {
//        int p = deQueue();
//        int index;
//        for (index = firstNeighbor(p); index > -1; index = nextNeighbor(p, index)) {
//            if (!visit[index]) {
//                visPrint(index);
//                visit[index] = true;
//                enQueue(index);
//                shortest_path_counter[index] = shortest_path_counter[p] + 1;
//                shortest_path[index] = p;
//            }
//        }
//    }
//}
void printPath(int sindex, int tindex);

//获取坐标
int locate(int vertex) {
    int j = -1;
    for (int i = 0; i < gh->num_vertices; ++i) {
        if (vertex == gh->vertices[i].value) {
            j = i;
            break;
        }
    }
    return j;
}

void bfs(int s, int t) {
    // 初始化访问记录数组
    memset(visit, 0, sizeof(bool) * MAX_VERTICES);
    memset(shortest_path, -1, sizeof(int) * MAX_VERTICES);
    destroyQueue();
    initializeQueue();
    int sindex = locate(s);
    int tindex = locate(t);
    enQueue(sindex);
    visit[sindex] = true;
    while (!isEmptyQueue()) {
        int q = deQueue();
        Edge *p = gh->vertices[q].firstEdge;
        while (p != NULL) {
            int pdestindex = p->dest;
            if (!visit[pdestindex]) {
                enQueue(pdestindex);
                visit[pdestindex] = true;
                shortest_path[pdestindex] = q;
            }
            if (p->dest == tindex) {
                printPath(sindex, tindex);
                return;
            }
            p = p->link;
        }
    }


}

void printPath(int sindex, int tindex) {
    if (shortest_path[tindex] != -1 && tindex != sindex) {
        printPath(sindex, shortest_path[tindex]);
    }
    printf("%d\t", gh->vertices[tindex].value);
}