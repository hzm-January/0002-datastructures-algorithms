//
// Created by asus on 2019/8/19.
//

#include "breadthfirsttraverse.h"

void visPrint(int index);

void bftall() {
    // 初始化访问记录数组
    memset(visit, 0, sizeof(bool) * MAX_VERTICES);
    memset(shortest_path_counter, -1, sizeof(int) * MAX_VERTICES);
    memset(shortest_path, -1, sizeof(int) * MAX_VERTICES);
    // 未连通顶点遍历
    for (int i = 0; i < gh->num_vertices; ++i) {
        if (!visit[i]) {
            //TODO: traverse
            bft(i);
        }
    }
}

void visPrint(int index) {
    Vertex vertex = gh->vertices[index];
    printf("%d\t", vertex.value);
}

void bft(int vIndex) {
    enQueue(vIndex);
    visPrint(vIndex);
    visit[vIndex] = true;
    shortest_path_counter[vIndex] = 0;
    while (!isEmptyQueueNoExit()) {
        int p = deQueue();
        int index;
        for (index = firstNeighbor(p); index > -1; index = nextNeighbor(p, index)) {
            if (!visit[index]) {
                visPrint(index);
                visit[index] = true;
                enQueue(index);
                shortest_path_counter[index] = shortest_path_counter[p] + 1;
                shortest_path[index] = p;
            }
        }
    }
}

void bfs(int s, int t) {
    if (shortest_path[t] != -1 && t != s) {
        bfs(s, shortest_path[t]);
    }
    printf("%d\t", gh->vertices[t].value);
}