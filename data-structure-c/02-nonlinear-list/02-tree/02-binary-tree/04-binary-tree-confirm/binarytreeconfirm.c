//
// Created by asus on 2019/8/8.
//

#include "binarytreeconfirm.h"

BinaryTreeNode *creattree(char *VLR, char *LVR, int n) {
    if (n == 0) {
        return NULL;
    }
    BinaryTreeNode *node = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
    node->value = VLR[0];
    node->left = NULL;
    node->right = NULL;
    //前序的元素 在 中序中查找
    int k = 0;
    while (VLR[0] != LVR[k]) {
        k++;
    }
    node->left = creattree(VLR + 1, LVR, k);
    node->right = creattree(VLR + k + 1, LVR + k + 1, n - k - 1);
    return node;
}