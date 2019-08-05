//
// Created by asus on 2019/8/5.
//

#include "threadbinarytreepreorder.h"

void creatThread(TreeNode *node) {

    if (node == NULL) {
        printf("the tree is empty...");
        exit(1);
    }
    TreeNode **p = (TreeNode **) malloc(sizeof(TreeNode *));
    *p = NULL;
    creatThreadPreOrder(node, p);
}

void creatThreadPreOrder(TreeNode *cur, TreeNode **pre) {
    if (cur == NULL) {
        return;
    }
    if (cur->left == NULL && cur->ltag == 0) {
        cur->ltag = 1;
        cur->left = *pre;
    }
    if ((*pre) != NULL && (*pre)->right == NULL) {
        (*pre)->rtag = 1;
        (*pre)->right = cur;
    }

    *pre = cur; //父指针指向当前指针
//    printf("%d\n", cur->value);
    if (cur->ltag == 0) {
        creatThreadPreOrder(cur->left, pre);
    }
    if (cur->rtag == 0) {
        creatThreadPreOrder(cur->right, pre);
    }


}