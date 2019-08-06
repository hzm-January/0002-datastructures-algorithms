//
// Created by asus on 2019/8/5.
//

#ifndef DATA_STRUCTURE_C_THREADBINARYTREEPREORDER_H
#define DATA_STRUCTURE_C_THREADBINARYTREEPREORDER_H

#include <stdlib.h>
#include <stdio.h>
typedef struct Tree_Node{
    int value;
    struct Tree_Node* left;
    struct Tree_Node* right;
    int ltag; // 0,1 0为左子节点，1为线索前继
    int rtag; // 0,1 0为右子节点，1为线索后继
} TreeNode;
TreeNode * root;
// 线索化
void creatThread(TreeNode * node);
// 前序线索化
void creatThreadPreOrder(TreeNode * cur, TreeNode ** pre);

#endif //DATA_STRUCTURE_C_THREADBINARYTREEPREORDER_H
