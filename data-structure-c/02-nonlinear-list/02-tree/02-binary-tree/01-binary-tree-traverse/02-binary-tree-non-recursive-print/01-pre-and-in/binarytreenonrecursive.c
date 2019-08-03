//
// Created by asus on 2019/8/2.
//

#include "binarytreenonrecursive.h"

void initializeStack() {
    if (stackHead == NULL) {
        stackHead = (StackTreeNode *) malloc(sizeof(StackTreeNode));
        stackHead->value = NULL;
        stackHead->next = NULL;
    }
}

void destroyStack() {
    if (stackHead != NULL) {
        StackTreeNode *p = stackHead;
        StackTreeNode *pre = NULL;
        while (p->next != NULL) {
            pre = p;
            p = p->next;
            free(pre);
            pre = NULL; //释放上一个节点
        }
    }
}

bool push(TreeNode *node) {
    StackTreeNode *p = stackHead;
    StackTreeNode *newNode = (StackTreeNode *) malloc(sizeof(StackTreeNode));
    newNode->value = node;
    newNode->next = NULL;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    return true;
}

TreeNode *pop() {
    StackTreeNode *p = stackHead;
    if (p->next == NULL) {
//        printf("the stack is empty\n");
        return NULL;
    }
    StackTreeNode *pre = NULL;
    while (p->next != NULL) {
        pre = p;
        p = p->next;
    }
    TreeNode *delNodeValue = p->value;
    pre->next = NULL;
    free(p);
    p = NULL;
    return delNodeValue;
}

/**
 * 二叉树递归遍历
 * @param node
 */
//前序遍历
void prePrintNr(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    TreeNode *p = node;
    while (p != NULL) {
        printf("%d\t", p->value);

        if (p->right != NULL) {
            push(p->right);
        }
        if (p->left != NULL) {
            p = p->left;
        } else {
            p = pop();
        }

    }
}

////中序遍历
void inPrintNr(TreeNode *node) {
    TreeNode *p = node;
    do {
        while (p != NULL) {
            push(p);
            p = p->left;
        }
        if (!stackIsEmpty()) {
            p = pop();
            printf("%d\t", p->value);
            p = p->right;
        }
    } while (p != NULL || !stackIsEmpty());
}

bool stackIsEmpty() {
    if (stackHead->next == NULL) {
        return true;
    }
    return false;
}