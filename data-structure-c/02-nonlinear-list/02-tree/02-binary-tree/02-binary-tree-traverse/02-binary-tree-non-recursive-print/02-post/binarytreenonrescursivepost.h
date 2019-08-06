//
// Created by asus on 2019/8/3.
//

#ifndef DATA_STRUCTURE_C_BINARYTREENONRESCURSIVEPOST_H
#define DATA_STRUCTURE_C_BINARYTREENONRESCURSIVEPOST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// tree node
typedef struct TREE_NODE {
    int value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} TreeNode;
// tree node stack
typedef struct TREE_NODE_STACK {
    struct TREE_NODE *value;
    struct TREE_NODE_STACK *next;
    int tag; //0 左，1 右
} StackTreeNode;
// tree root
TreeNode *root;
//stack
StackTreeNode *stackHead;

void initializeStack();
void destroyStack();
void postPrint(TreeNode *node);
bool push(StackTreeNode *newNode);

bool stackIsEmpty();

TreeNode *pop();
StackTreeNode *getPop();

#endif //DATA_STRUCTURE_C_BINARYTREENONRESCURSIVEPOST_H
