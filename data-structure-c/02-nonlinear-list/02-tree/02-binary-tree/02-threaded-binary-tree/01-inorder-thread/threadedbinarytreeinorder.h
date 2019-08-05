//
// Created by asus on 2019/8/3.
//

#ifndef DATA_STRUCTURE_C_THREADEDBINARYTREEINORDER_H
#define DATA_STRUCTURE_C_THREADEDBINARYTREEINORDER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TREE_NODE {
    int value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
    int ltag; // 0存放子节点，1存放前驱节点
    int rtag; // 0存放子节点，0存放前驱节点
} TreeNode;

TreeNode *root; //根节点
// 线索化
void createInThread();

// 使用中序遍历线索化
void createInThreadInOrder(TreeNode *cur, TreeNode **pre);

// 中序线索化后，使用线索进行前序遍历
void preOrderWithThread(TreeNode *node);

// 中序线索化后，使用线索进行中序遍历
void inOrderWithThread(TreeNode *node);

#endif //DATA_STRUCTURE_C_THREADEDBINARYTREEINORDER_H
