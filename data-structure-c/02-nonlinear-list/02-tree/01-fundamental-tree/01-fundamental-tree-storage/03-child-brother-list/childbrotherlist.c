//
// Created by asus on 2019/8/7.
//

#include "childbrotherlist.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void createTreeByNodes(int value, int parentValue) {
    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->child = NULL;
    newNode->value = value;
    newNode->link = NULL;
    if (root == NULL) {
        root = newNode;
        return;
    }
    TreeNode *p = root; //遍历找到父节点
    while (p != NULL && p->value != parentValue) {
        p = p->child;
    }
    if (p == NULL) {
        printf(" the parent node is not found");
        exit(1);
    }
    TreeNode * pp = p->child;
    if (pp == NULL) { //如果父结点还没有孩子结点，将当前结点作为父结点的第一个子结点
        p->child = newNode;
        return;
    }
    // 如果父结点有孩子结点，找到兄弟结点链表的末尾结点
    while (pp->link != NULL) {
        pp = pp->link;
    }
    pp->link = newNode;
}