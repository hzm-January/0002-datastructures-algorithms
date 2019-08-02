//
// Created by asus on 2019/7/16.
//

#include "binarytreerecursive.h"


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
