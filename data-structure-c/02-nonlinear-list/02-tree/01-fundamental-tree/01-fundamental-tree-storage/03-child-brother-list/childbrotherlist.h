//
// Created by asus on 2019/8/7.
//

#ifndef DATA_STRUCTURE_C_CHILDBROTHERLIST_H
#define DATA_STRUCTURE_C_CHILDBROTHERLIST_H

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

void createTreeByNodes(int value, int parentValue);
#endif //DATA_STRUCTURE_C_CHILDBROTHERLIST_H
