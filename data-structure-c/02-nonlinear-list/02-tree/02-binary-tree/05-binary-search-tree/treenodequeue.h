//
// Created by asus on 2019/8/9.
//

#ifndef DATA_STRUCTURE_C_TREENODEQUEUE_H
#define DATA_STRUCTURE_C_TREENODEQUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// tree node
typedef struct TREE_NODE {
    int value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} TreeNode;
// tree root
TreeNode *root;

// queue
typedef struct QUEUE_TREE_NODE {
    TreeNode *value;
    struct QUEUE_TREE_NODE *next;
} QueueTreeNode;
// queue sentinel
QueueTreeNode * queueSentinel;
void enqueue(TreeNode * value);
TreeNode * dequeue();
bool isEmpty();
// queue size
int size();
#endif //DATA_STRUCTURE_C_TREENODEQUEUE_H
