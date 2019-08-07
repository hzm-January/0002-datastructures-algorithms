//
// Created by asus on 2019/8/6.
//

#ifndef DATA_STRUCTURE_C_CHILDLINK_H
#define DATA_STRUCTURE_C_CHILDLINK_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 20
typedef struct TREE_NODE {
    int datum;
    struct TREE_NODE *link;
} TreeNode;

TreeNode *treeHeads[MAX_SIZE]; // 左右子树的头节点向量存储
int size; //数组现有元素个数
/**
 * 初始化
 */
void initialize();
void destroy();
/**
 *
 * @param value 插入元素值
 * @param parentValue 插入元素的父元素值
 */
void save(int value, int parentValue); // 添加节点
/**
 *
 */
#endif //DATA_STRUCTURE_C_CHILDLINK_H
