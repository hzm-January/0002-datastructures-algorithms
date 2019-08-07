//
// Created by asus on 2019/8/6.
//

#ifndef DATA_STRUCTURE_C_PARENTPOINTER_H
#define DATA_STRUCTURE_C_PARENTPOINTER_H
#define MAX_SIZE 10
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct TREE_NODE {
    int value;
    int parent;
} TreeNode;
TreeNode *tree[MAX_SIZE];
int size;

void createTreeByNodes(int value, int pvalue); // 保存节点
void print(); // 打印所有节点
#endif //DATA_STRUCTURE_C_PARENTPOINTER_H
