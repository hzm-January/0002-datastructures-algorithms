//
// Created by hzm on 2019/8/22.
//

#ifndef DATA_STRUCTURE_C_UFSET_H
#define DATA_STRUCTURE_C_UFSET_H
#define SIZE 10

#include <string.h>
#include <stdio.h>

int parent[SIZE]; // 双亲指针数组
/**
 * 初始化
 */
void ufset_init(int s[]);

/**
 * union
 * 求两个不相交子集的并集
 * @param root1
 * @param root2
 */
void ufset_union(int s[], int root1, int root2);

/**
 * Find
 * find and return the index of root for the element
 * 查找并返回包含元素element的根
 * @param s
 * @param element
 * @return
 */
int ufset_find(int s[], int element);

/**
 * 使用加权规则改进后的union操作
 * 加权规则：判断两棵树中的结点个数，如果i中结点数大于j中结点数，j作为i的父结点
 * 加权改进目的：避免产生退化的树
 * @param root1
 * @param root2
 */
void ufset_weight_union(int s[], int root1, int root2);

#endif //DATA_STRUCTURE_C_UFSET_H
