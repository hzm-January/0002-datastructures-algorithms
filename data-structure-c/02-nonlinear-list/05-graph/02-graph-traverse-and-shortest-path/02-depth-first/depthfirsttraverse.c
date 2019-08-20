//
// Created by asus on 2019/8/20.
//

#include "depthfirsttraverse.h"
void visPrint(int index) {
    Vertex vertex = gh->vertices[index];
    printf("%d\t", vertex.value);
}
// 连通顶点的变量
void bft(int vIndex) {
    Edge *edge = gh->vertices[vIndex].firstEdge;
    visPrint(vIndex);
    visit[vIndex] = true;
    int w;
    for (w = firstNeighbor(vIndex); w > -1; w = nextNeighbor(vIndex, w)) {
        if (!visit[vIndex]) {
            bft(w);
        }
    }
}
// 遍历入口方法
void bftall(){
    // 初始化访问记录数组
    memset(visit, 0, sizeof(bool) * MAX_VERTICES);
    // 未连通顶点遍历
    for (int i = 0; i < gh->num_vertices; ++i) {
        if (!visit[i]) {
            //TODO: traverse
            bft(i);
        }
    }
}