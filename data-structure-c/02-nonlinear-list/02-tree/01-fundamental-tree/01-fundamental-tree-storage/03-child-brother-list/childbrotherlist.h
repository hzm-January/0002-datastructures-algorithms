//
// Created by asus on 2019/8/7.
//

#ifndef DATA_STRUCTURE_C_CHILDBROTHERLIST_H
#define DATA_STRUCTURE_C_CHILDBROTHERLIST_H


#include "treenode.h"
#include "linkedqueue.h"

/**
 * 创建树，并添加节点
 */
void createTreeByNodes(int value, int parentValue);

/**
 * 树的深度优先遍历----先根遍历
 */
void preRootPrint(TreeNode *proot);

/**
 * 树的深度优先遍历----后根遍历
 */
void postRootPrint(TreeNode *proot);

/**
 * 树的广度优先遍历----借助队列
 */
void queuePrint(TreeNode *proot);

/**
 * 树的深度优先遍历----先根遍历----应用----求树的结点数
 */
int count();
int countByPreRoot();
/**
 * 树的深度优先遍历----后根遍历----应用----求树的深度
 */
int depthByPostRoot();
#endif //DATA_STRUCTURE_C_CHILDBROTHERLIST_H
