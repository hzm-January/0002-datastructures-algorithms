//
// Created by asus on 2019/8/8.
//

#ifndef DATA_STRUCTURE_C_TREENODE_H
#define DATA_STRUCTURE_C_TREENODE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TREE_NODE {
    struct TREE_NODE *child;
    struct TREE_NODE *link;
    int value;
} TreeNode;
TreeNode * root; //根节点

typedef struct TREE_QUEUE_NODE{
    TreeNode * treenode;
    struct TREE_QUEUE_NODE * next;
} TreeQueueNode;
TreeQueueNode * sentinal; // 队列哨兵结点
#endif //DATA_STRUCTURE_C_TREENODE_H
