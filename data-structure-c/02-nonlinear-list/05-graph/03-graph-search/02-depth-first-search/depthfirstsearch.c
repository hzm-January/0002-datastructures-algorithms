//
// Created by asus on 2019/8/20.
//

#include "depthfirstsearch.h"

void visPrint(int index) {
    Vertex vertex = gh->vertices[index];
    printf("%d\t", vertex.value);
}

// 连通顶点的变量
void bft(int vIndex, int t) {
    if (found) return;
    visPrint(vIndex);
    visit[vIndex] = true;
    if (vIndex == t) {
        found = true;
        return;
    }
    int w;
    for (w = firstNeighbor(vIndex); w > -1; w = nextNeighbor(vIndex, w)) {
        if (!visit[w]) {
            shortest_path[w] = vIndex;
            bft(w, t);
        }
    }
}

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

void printPath(int s, int t) {
    if (gh->vertices[s].value != -1 && t != s) {
        printPath(s, shortest_path[t]);
    }
    printf("%d\t", gh->vertices[t].value);
}

//// 遍历入口方法
void bftapi(int o, int d) {
    // 初始化访问记录数组

    memset(visit, 0, sizeof(bool) * MAX_VERTICES);
    memset(shortest_path, -1, sizeof(int) * MAX_VERTICES);
    int oindex = locate(o);
    int dindex = locate(d);
    bft(oindex, dindex);
    printf("\n");
    printPath(oindex, dindex);
}
