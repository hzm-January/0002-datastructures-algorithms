//
// Created by asus on 2019/8/13.
//

#ifndef DATA_STRUCTURE_C_ADJACENCYMATRIX_H
#define DATA_STRUCTURE_C_ADJACENCYMATRIX_H
// 允许最大顶点数
#define MAX_VERTICES 10
#define DEFAULT_WEIGHT -1
/**
 * 无向图--邻接矩阵存储
 */
#include "../../graph.h"
#include <string.h>
// 当前矩阵顶点个数
int num_vertices;
// 当前边个数
int num_edges;
// 顺序表，存放顶点
int vertices[MAX_VERTICES];
// 二维数组，存放边
int edges[MAX_VERTICES][MAX_VERTICES];
#endif //DATA_STRUCTURE_C_ADJACENCYMATRIX_H
