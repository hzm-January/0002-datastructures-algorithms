//
// Created by asus on 2019/8/3.
//
#include "threadedbinarytreeinorder.h"

int main(int argc, char *argv[]) {

//    size_t i = sizeof(TreeNode);
//    printf("%d", i);

    //initialize tree root;
    root = (TreeNode *) malloc(sizeof(TreeNode));
    root->value = 0;
    root->rtag=0;
    root->ltag=0;
    TreeNode *rootLeft = (TreeNode *) malloc(sizeof(TreeNode));
    rootLeft->value = 1;
    rootLeft->rtag=0;
    rootLeft->ltag=0;
    TreeNode *rootRight = (TreeNode *) malloc(sizeof(TreeNode));
    rootRight->value = 2;
    rootRight->rtag=0;
    rootRight->ltag=0;
    TreeNode *rootLeftL = (TreeNode *) malloc(sizeof(TreeNode));
    rootLeftL->value = 3;
    rootLeftL->rtag=0;
    rootLeftL->ltag=0;
    rootLeftL->left = NULL;
    rootLeftL->right = NULL;
    TreeNode *rootRightR = (TreeNode *) malloc(sizeof(TreeNode));
    rootRightR->value = 4;
    rootRightR->rtag=0;
    rootRightR->ltag=0;
    rootRightR->left = NULL;
    rootRightR->right = NULL;
    TreeNode *rootLeftR = (TreeNode *) malloc(sizeof(TreeNode));
    rootLeftR->value = 5;
    rootLeftR->rtag=0;
    rootLeftR->ltag=0;
    rootLeftR->left = NULL;
    rootLeftR->right = NULL;
    TreeNode *rootRightL = (TreeNode *) malloc(sizeof(TreeNode));
    rootRightL->value = 6;
    rootRightL->rtag=0;
    rootRightL->ltag=0;
    rootRightL->left = NULL;
    rootRightL->right = NULL;
    rootLeft->left = rootLeftL;
    rootLeft->right = rootLeftR;
    rootRight->left = rootRightL;
    rootRight->right = rootRightR;
    root->left = rootLeft;
    root->right = rootRight;

    createInThread();
    preOrderWithThread(root);
    return 0;
}