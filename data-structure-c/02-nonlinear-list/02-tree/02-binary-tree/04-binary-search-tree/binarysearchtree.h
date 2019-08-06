//
// Created by asus on 2019/7/16.
//

#ifndef DATA_STRUCTURE_C_BINARYSEARCHTREE_H
#define DATA_STRUCTURE_C_BINARYSEARCHTREE_H
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
//
int findMax();
int findMin();
int findParent(int data);
bool insert(int data);
void delete(int data);
TreeNode *createNode(int data);
void freeNode(TreeNode * node);
void prePrint(TreeNode * node);
void inPrint(TreeNode * node);
void postPrint(TreeNode * node);
#endif //DATA_STRUCTURE_C_BINARYSEARCHTREE_H
