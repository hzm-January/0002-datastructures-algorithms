//
// Created by asus on 2019/8/8.
//

#ifndef DATA_STRUCTURE_C_BINARYTREECONFIRM_H
#define DATA_STRUCTURE_C_BINARYTREECONFIRM_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct BINARY_TREE_NODE {
    char value;
    struct BINARY_TREE_NODE *left;
    struct BINARY_TREE_NODE *right;
} BinaryTreeNode;

BinaryTreeNode *root; // 根结点
char * pre_order_str;
char * in_order_str;
BinaryTreeNode *creattree(char *VLR, char *LVR, int n);
#endif //DATA_STRUCTURE_C_BINARYTREECONFIRM_H
