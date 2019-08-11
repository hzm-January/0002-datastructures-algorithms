//
// Created by asus on 2019/8/10.
//

#ifndef DATA_STRUCTURE_C_STACKTREENODE_H
#define DATA_STRUCTURE_C_STACKTREENODE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// 树结点
typedef struct TREE_NODE {
    int value;
    int bf;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
}TreeNode;

TreeNode * root;
typedef struct STACK_TREE_NODE {
    TreeNode *value;
    struct STACK_TREE_NODE *next;
} StackTreeNode;
StackTreeNode * sentinal;
bool isEmpty();
TreeNode * pop();
bool push(TreeNode * node);
#endif //DATA_STRUCTURE_C_STACKTREENODE_H
