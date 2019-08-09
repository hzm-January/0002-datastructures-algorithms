//
// Created by asus on 2019/7/16.
//

#include "binarysearchtree.h"

bool insert(int data) {
    if (root == NULL) {
        root = createNode(data);
        return true;
    }
    TreeNode *p = root;
    while (p != NULL) {
        if (p->value > data) {
            if (p->left == NULL) {
                p->left = createNode(data);
                return true;
            }
            p = p->left;
        } else if (p->value < data) {
            if (p->right == NULL) {
                p->right = createNode(data);
                return true;
            }
            p = p->right;
        } else {
            printf("the tree has a node whose value equals the value of insert node");
            return false;
        }
    }
    return true;
}

void delete(int data) {
    TreeNode *p = root;
    TreeNode *pre = NULL;
    while (p != NULL && p->value != data) {
        pre = p;
        if (p->value > data) {
            p = p->left;
        } else if (p->value < data) {
            p = p->right;
        }
    }
    if (p == NULL) {
        printf("the node is not in the tree");
        return;
    }
    //1. the node for deleting has a left node and a right node
    if (p->left != NULL && p->right != NULL) {
        // find the min value node of right child tree
        TreeNode *minNode = p->right;
        TreeNode *minNodeP = p;
        while (minNode->left != NULL) {
            minNodeP = minNode;
            minNode = minNode->left;
        }
        p->value = minNode->value;
        pre = minNodeP;
        p = minNode;
    }
    if (pre == NULL) {
        printf("delete the root node");
        freeNode(root);
        return;
    }
    TreeNode *child = NULL;
    if (p->right != NULL) child = p->right;
    else if (p->left != NULL) child = p->left;
    else child = NULL;
    if (pre->left == p) pre->left = child;
    else pre->right = child;
    freeNode(p);
}

void freeNode(TreeNode *node) {
    if (node != NULL) {
        free(node);
        node = NULL;
    }
}

TreeNode *createNode(int data) {
    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void prePrint(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    printf("%d\t", node->value);
    prePrint(node->left);
    prePrint(node->right);
}

void inPrint(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    inPrint(node->left);
    printf("%d\t", node->value);
    inPrint(node->right);
}

void postPrint(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    postPrint(node->left);
    postPrint(node->right);
    printf("%d\t", node->value);
}

int findMax() {
    TreeNode *p = root;
    while (p != NULL && p->right != NULL) {
        p = p->right;
    }
    if (p == NULL) {
        printf("this tree is empty");
        return 0;
    }
    return p->value;
}

int findMin() {
    TreeNode *p = root;
    while (p != NULL && p->left != NULL) {
        p = p->left;
    }
    if (p == NULL) {
        printf("this tree is empty");
        return 0;
    }
    return p->value;
}

int findParent(int data) {
    TreeNode *p = root;
    TreeNode *pp = NULL;
    while (p != NULL && p->value != data) {
        pp = p;
        if (data > p->value) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    if (pp == NULL) {
        // 树为空
        // 树只有根节点
        return -1;
    }
    if (p == NULL) {
        printf(" this node is not in the tree \n");
        return -1;
    }
    return pp->value;
}

/**
 * 查找
 * @param value
 * @return
 */
TreeNode *find(int value) {
    TreeNode *p = root;
    while (p != NULL && p->value != value) {
        if (p->value > value) p = p->left;
        else p = p->right;
    }
    return p;
}

/**
 * 深度优先计算树的高度
 * @param node
 * @return
 */
int high_depth_first(TreeNode *node) {
    if (node == NULL) {
        return 0;
    }
    int depleft = high_depth_first(node->left);
    int depright = high_depth_first(node->right);
    return depleft > depright ? depleft + 1 : depright + 1;
}

int high_breadth_first(TreeNode *node) {
    if (root == NULL) {
        return 0;
    }
    enqueue(node);
    int height = 0;
    while (!isEmpty()) {
        height++;
        int queueSize = size();
        for (int i = 0; i < queueSize; ++i) {
            TreeNode *pNode = dequeue();
            if (pNode->left != NULL) enqueue(pNode->left);
            if (pNode->right != NULL) enqueue(pNode->right);
        }
    }
    return height;
}
