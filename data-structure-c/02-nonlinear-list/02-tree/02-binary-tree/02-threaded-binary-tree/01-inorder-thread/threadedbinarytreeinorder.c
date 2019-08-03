//
// Created by asus on 2019/8/3.
//

#include "threadedbinarytreeinorder.h"

// 中序遍历线索化
void createInThread() {
    TreeNode **pre = (TreeNode **) malloc(sizeof(TreeNode *));
    *pre = NULL;
    TreeNode *p = root;
    createInThreadInOrder(p, pre);
    (*pre)->right = NULL;
    (*pre)->rtag = 1;
    free(pre);
}

void createInThreadInOrder(TreeNode *cur, TreeNode **pre) {
    if (cur == NULL) {
        return;
    }
    createInThreadInOrder(cur->left, pre);
    if (cur->left == NULL) {
        cur->left = *pre;
        cur->ltag = 1; //left存放的是线索的上个节点
    }
//    printf("%d\t", cur->value);
    if (*pre != NULL && (*pre)->right == NULL) {
        (*pre)->right = cur;
        (*pre)->rtag = 1; //right存放的是线索下个节点
    }
    *pre = cur;
    createInThreadInOrder(cur->right, pre);
}

void preOrderWithThread(TreeNode *node) {
    if (root == NULL) {
        return;
    }
    TreeNode *p = root;
    while (p != NULL) {
        printf("%d\t", p->value);
        if (p->ltag == 0) {
            p = p->left;
        } else if (p->rtag == 0) {
            p = p->right;
        } else {
            while (p != NULL && p->rtag == 1) {
                p = p->right;
            }
            if (p != NULL) {
                p = p->right;
            }
        }

    }
}