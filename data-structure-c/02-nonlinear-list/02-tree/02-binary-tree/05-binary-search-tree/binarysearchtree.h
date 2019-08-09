//
// Created by asus on 2019/7/16.
//

#ifndef DATA_STRUCTURE_C_BINARYSEARCHTREE_H
#define DATA_STRUCTURE_C_BINARYSEARCHTREE_H


#include "treenodequeue.h"


int findMax();

int findMin();

int findParent(int data);

bool insert(int data);

void delete(int data);

TreeNode *createNode(int data);

void freeNode(TreeNode *node);

void prePrint(TreeNode *node);

void inPrint(TreeNode *node);

void postPrint(TreeNode *node);

TreeNode *find(int value);

int high_depth_first(TreeNode *node);

int high_breadth_first(TreeNode *node);



#endif //DATA_STRUCTURE_C_BINARYSEARCHTREE_H
