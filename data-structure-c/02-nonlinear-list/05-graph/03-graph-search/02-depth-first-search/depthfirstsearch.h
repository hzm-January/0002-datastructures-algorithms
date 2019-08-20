//
// Created by asus on 2019/8/20.
//

#ifndef DATA_STRUCTURE_C_DEPTHFIRSTTRAVERSE_H
#define DATA_STRUCTURE_C_DEAPTHFIRSTTRAVERSE_H

#include "../../01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.h"

bool visit[MAX_VERTICES]; // 已访问过的顶点
/**
 * o,d为顶点
 */
void bftapi(int o, int d);
/**
 * int oIndex, int dIndex 为顶点坐标
 * @param oIndex
 * @param dIndex
 */
void bft(int oIndex, int dIndex); // 连通顶点的变量
void bftall(); // 遍历入口方法
bool found; // 是否已经找到
int shortest_path[MAX_VERTICES]; //最短路径轨迹
#endif //DATA_STRUCTURE_C_DEPTHFIRSTTRAVERSE_H
