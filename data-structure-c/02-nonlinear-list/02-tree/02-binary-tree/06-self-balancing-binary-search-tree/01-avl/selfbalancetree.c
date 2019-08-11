//
// Created by asus on 2019/8/10.
//

#include "selfbalancetree.h"
// 添加
bool insert(int value) {

    TreeNode *p = root;
    TreeNode *pr = NULL;
    while (p != NULL) {
        pr = p;
        push(pr);
        if (p->value > value) {
            p = p->left;
        } else if (p->value < value) {
            p = p->right;
        } else {
            return false; // 树中存在同值结点，不添加
        }
    }
    p = (TreeNode *) malloc(sizeof(TreeNode));
    p->value = value;
    p->bf = 0;
    p->left = NULL;
    p->right = NULL;
    if (pr == NULL) {
        root = p;
        return true;
    }
    if (pr->value > value) {
        pr->left = p;
    } else {
        pr->right = p;
    }
    int d = 0;
    while (!isEmpty()) {
        pr = pop();
        if (p == pr->left) pr->bf--;
        else pr->bf++;
        if (pr->bf == 0) break;
        if (pr->bf == 1 || pr->bf == -1) {
            p = pr; //向上考察父结点
        } else {
            d = pr->bf < 0 ? -1 : 1;
            if (p->bf == d) { // 父节点与子节点同号
                if (d == -1) pr = rotater(pr);
                else pr = rotatel(pr);
            } else { // 父节点和子节点不同号
                if (d == -1) pr = rotatelr(pr); //父结点和子结点平衡因子不同号，并且父结点平衡因子为负数
                else pr = rotaterl(pr); //父结点和子结点平衡因子不同号，并且父结点平衡因子为正数，子结点先右旋，然后父结点左旋
            }
            break;
        }
    }
    if (isEmpty()) root = pr;
    else {
        TreeNode *q = pop();
        if (q->value > pr->value) {
            q->left = pr;
        } else {
            q->right = pr;
        }
    }
    // 调整树，保持平衡
    return true;
}
// 删除
bool delete(int value) {

    // 知道要删除的结点
    TreeNode *p = root;
    TreeNode *pp = NULL;
    while (p != NULL && p->value != value) {
        pp = p;
        if (p->value > value) p = p->left;
        if (p->value < value) p = p->right;
    }
    if (p == NULL) {
        printf("the node doesn't exist in the tree");
        return false;
    }
    if (p->left != NULL && p->right != NULL) {
        TreeNode *minrp = p->right;
        TreeNode *minrpp = p;
        while (minrp != NULL) {
            minrpp = minrp;
            minrp = minrp->left;
        }
        pp = minrpp;
        p->value = minrp->value;
        p = minrp;
    }
    if (pp == NULL) {
        free(root);
        root = NULL;
        return true;
    }
    TreeNode *child;
    if (p->left != NULL) child = p->left;
    else if (p->right != NULL) child = p->right;
    else child = NULL;
    if (pp->left == p) pp->left = child;
    else pp->right = child;

    free(p);
    p = NULL;
    return true;
}

// 单左旋
TreeNode* rotatel(TreeNode *ptr) {
    TreeNode *subL = ptr;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;
    ptr->bf = subL->bf = 0;
    return ptr;
}

// 单右旋
TreeNode* rotater(TreeNode *ptr) {
    TreeNode *subR = ptr;
    ptr = subR->left;
    subR->left = ptr->right;
    ptr->right = subR;
    subR->bf = ptr->bf = 0;
    return ptr;
}

// 先左后右双旋
TreeNode* rotaterl(TreeNode *ptr) {
    TreeNode *subL = ptr->left; //旋转结束后的左子树
    TreeNode *subR = ptr; // 旋转结束后的右子树
    ptr = subL->right; // 新根
    subL->right = ptr->left; // 成为新根前，卸掉左子树
    ptr->left = subL; // 新根左子树
    if (ptr->bf <= 0) {
        subL->bf = 0; //如果是因为在原来不平衡的结点的左子树结点添加了结点导致不平衡的情况
    } else {
        subL->bf = -1;
    }

    subR->left = ptr->right; // 成为新根前，卸掉右子树
    ptr->right = subR;
    if (ptr->bf == -1) {
        subR->bf = 1; //如果是因为在原来不平衡的结点的右子树结点添加了结点导致不平衡的情况
    } else {
        subR->bf = 0;
    }
    ptr->bf = 0;
    return ptr;
}

// 先右后左双旋
TreeNode* rotatelr(TreeNode *ptr) {
    TreeNode *subL = ptr; // 旋转完成后的左子树
    TreeNode *subR = ptr->right; // 旋转完成后的右子树
    ptr = subR->left; // 新根
    subL->right = ptr->left; // 成为新根前，卸掉左子树
    ptr->left = subL; // 指向新左子树
    if (ptr->bf == 1) {
        subL->bf = -1; //如果是因为在原来不平衡的结点的右子树结点添加了结点导致不平衡的情况
    } else {
        subL->bf = 0;
    }
    subR->left = ptr->right; // 成为新根前，卸掉右子树
    ptr->right = subR;
    if (ptr->bf >= 0) {
        subR = 0; //如果是因为在原来不平衡的结点的右子树结点添加了结点导致不平衡的情况
    } else {
        subR->bf = 1;
    }
    ptr->bf = 0;
    return ptr;
}