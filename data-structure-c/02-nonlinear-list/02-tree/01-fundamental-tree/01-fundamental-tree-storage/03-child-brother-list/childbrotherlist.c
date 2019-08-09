//
// Created by asus on 2019/8/7.
//

#include "childbrotherlist.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 创建树，并添加节点
 */
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
        TreeNode *plinkhead = p->link;
        TreeNode *findResult = NULL;
        while (plinkhead != NULL) {
            if (plinkhead->value == parentValue) {
                findResult = plinkhead;
                break;
            }
            plinkhead = plinkhead->link;
        }
        if (findResult == NULL) {
            p = p->child;
        } else {
            p = plinkhead;
        }
    }
    if (p == NULL) {
        printf(" the parent node is not found");
        exit(1);
    }
    TreeNode *pp = p->child;
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

/**
 * 深度优先遍历--先根遍历
 */
void preRootPrint(TreeNode *proot) {
    if (proot == NULL) {
        return;
    }
    printf("%d\t", proot->value);
    preRootPrint(proot->child);
    preRootPrint(proot->link);
}

/**
 * 深度优先遍历--后根遍历
 */
void postRootPrint(TreeNode *proot) {
    if (proot == NULL) {
        return;
    }
    postRootPrint(proot->child);
    printf("%d\t", proot->value);
    postRootPrint(proot->link);
}

/**
 * 树的广度优先遍历----借助队列
 */
void queuePrint(TreeNode *proot) {
    // 初始化队列
    TreeNode *p = proot;
    enqueue(p);
    while (!isEmpty()) {
        TreeNode *pp = dequeue();
        printf("%d\t", pp->value);
        if (pp->child != NULL) {
            TreeNode *plink = pp->child;
            while (plink != NULL) {
                enqueue(plink);
                plink = plink->link;
            }
        }
    }

}

/**
 * 树的深度优先遍历----先根遍历----应用----求树的结点数
 */
int number;

void preRootPrintCount(TreeNode *proot) {
    if (proot == NULL) {
        return;
    }
    number++;
    preRootPrintCount(proot->child);
    preRootPrintCount(proot->link);
}

int count() {
    preRootPrintCount(root);
    return number;
}

/**
 * 树的深度优先遍历----先根遍历----应用----求树的结点数--教材代码
 */
int preRootCount(TreeNode *proot) {
    if (proot == NULL) {
        return 0;
    }
    int count = 1;
    count += preRootCount(proot->child);
    count += preRootCount(proot->link);
    return count;
}

int countByPreRoot() {
    return preRootCount(root);
}

/**
 * 树的深度优先遍历----后根遍历----应用----求树的深度
 */
int postRootDepth(TreeNode *proot) {
    if (proot == NULL) {
        return 0;
    }
    int child_tree_depth = postRootDepth(proot->child) + 1;
    int link_child_tree_depth = postRootDepth(proot->link);
    return (child_tree_depth > link_child_tree_depth) ? child_tree_depth : link_child_tree_depth;
}

int depthByPostRoot() {
    return postRootDepth(root);
}

