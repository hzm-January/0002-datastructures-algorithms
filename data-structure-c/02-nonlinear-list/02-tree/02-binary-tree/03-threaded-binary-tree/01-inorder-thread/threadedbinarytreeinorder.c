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
    if (node == NULL) {
        return;
    }
    TreeNode *p = node;
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

void inOrderWithThread(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    TreeNode *p = node;
    while (p != NULL) {
        while (p->ltag == 0) {
            p = p->left;
        }
        printf("%d\t", p->value);
        while (p->right != NULL && p->rtag == 1) {
            p = p->right;
            printf("%d\t", p->value);
        }
        p = p->right;
    }

}
/**
 * 先是从根结点开始按照左子树深入，直到遇见第一个左孩子是线索的结点，紧接着就打印它，
 * 这次打印的其实是链表头。接下来看它的右孩子是不是后继，如果是就继续打印；直到右孩子不是线索，
 * 此时转到右子树，开始和根结点一样的循环...最后一个while中需要判断node.rchild不为空，
 * 如果为空，我们打印出来就是null，这不是我们想要看得结果。
 * @param node
 */
void postOrderWithThread(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    TreeNode *p = node;
    while (p != NULL) {
        while (p->ltag == 0) {
            p = p->left;
        }
        printf("%d\t", p->value);
        while (p != NULL && p->rtag == 1) {
            p = p->right;
        }
        p = p->right;

    }

}