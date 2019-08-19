//
// Created by asus on 2019/8/19.
//

#ifndef DATA_STRUCTURE_C_BREADTH_FIRST_TRAVERSE_H
#define DATA_STRUCTURE_C_BREADTH_FIRST_TRAVERSE_H

#include "../../01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.h"
//#include "../../../../01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.h"
#include "linkedqueue/linkedqueue.h"
bool visit[MAX_VERTICES]; // 已访问过的顶点
// queue 队列保存 已经访问但是还没有进行遍历的顶点
void bft(int vIndex); // 连通顶点的变量
void bftall(); // 遍历入口方法
#endif //DATA_STRUCTURE_C_BREADTH_FIRST_TRAVERSE_H
