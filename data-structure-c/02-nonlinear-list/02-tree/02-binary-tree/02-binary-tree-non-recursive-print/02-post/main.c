//
// Created by asus on 2019/8/3.
//

#include "binarytreenonrescursivepost.h"
int main(int argc, char* argv[]){

    initializeStack();

//initialize tree root;
    root = (TreeNode *) malloc(sizeof(TreeNode));
    root->value = 0;
    TreeNode *rootLeft = (TreeNode *) malloc(sizeof(TreeNode));
    rootLeft->value = 1;
    TreeNode *rootRight = (TreeNode *) malloc(sizeof(TreeNode));
    rootRight->value = 2;
    TreeNode *rootLeftL = (TreeNode *) malloc(sizeof(TreeNode));
    rootLeftL->value = 3;
    rootLeftL->left = NULL;
    rootLeftL->right = NULL;
    TreeNode *rootRightR = (TreeNode *) malloc(sizeof(TreeNode));
    rootRightR->value = 4;
    rootRightR->left = NULL;
    rootRightR->right = NULL;
    TreeNode *rootLeftR = (TreeNode *) malloc(sizeof(TreeNode));
    rootLeftR->value = 5;
    rootLeftR->left = NULL;
    rootLeftR->right = NULL;
    TreeNode *rootRightL = (TreeNode *) malloc(sizeof(TreeNode));
    rootRightL->value = 6;
    rootRightL->left = NULL;
    rootRightL->right = NULL;
    rootLeft->left = rootLeftL;
    rootLeft->right = rootLeftR;
    rootRight->left = rootRightL;
    rootRight->right = rootRightR;
    root->left = rootLeft;
    root->right = rootRight;
//    prePrintNr(root);
    postPrint(root);



    destroyStack();

    return 0;
}
