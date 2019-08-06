//
// Created by asus on 2019/8/2.
//

#ifndef DATA_STRUCTURE_C_BINARYTREENONRECURSIVE_H
#define DATA_STRUCTURE_C_BINARYTREENONRECURSIVE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

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
} StackTreeNode;
// tree root
TreeNode *root;
//stack
StackTreeNode *stackHead;

void destroyStack();

void initializeStack();


bool push(TreeNode *node);

bool stackIsEmpty();

TreeNode *pop();

/**
 * 二叉树非递归遍历
 * @param node
 */
//前序遍历
void prePrintNr(TreeNode *node);

//中序遍历
void inPrintNr(TreeNode *node);

//后序遍历
void postPrintNr(TreeNode *node);


#endif //DATA_STRUCTURE_C_BINARYTREENONRECURSIVE_H
