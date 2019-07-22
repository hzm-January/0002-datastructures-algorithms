//
// Created by asus on 2019/7/16.
//

#ifndef DATA_STRUCTURE_C_FUNDAMENTALTREE_H
#define DATA_STRUCTURE_C_FUNDAMENTALTREE_H
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

void prePrint(TreeNode * node);
void inPrint(TreeNode * node);
void postPrint(TreeNode * node);
#endif //DATA_STRUCTURE_C_FUNDAMENTALTREE_H
