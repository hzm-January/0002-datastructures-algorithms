//
// Created by asus on 2019/8/20.
//

#ifndef DATA_STRUCTURE_C_DEPTHFIRSTTRAVERSE_H
#define DATA_STRUCTURE_C_DEPTHFIRSTTRAVERSE_H

#include "../../01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.h"

bool visit[MAX_VERTICES]; // 已访问过的顶点
void bft(int vIndex); // 连通顶点的变量
void bftall(); // 遍历入口方法


#endif //DATA_STRUCTURE_C_DEPTHFIRSTTRAVERSE_H
