//
// Created by asus on 2019/8/3.
//

#include "binarytreenonrescursivepost.h"

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

////后序遍历
void postPrint(TreeNode *node) {
    TreeNode *p = node;
    do {
        while (p != NULL) {
            StackTreeNode *newNode = (StackTreeNode *) malloc(sizeof(StackTreeNode));
            newNode->value = p;
            newNode->next = NULL;
            newNode->tag = 0;
            push(newNode);
            p = p->left;
        }
        int flag = 1;
        while (flag && !stackIsEmpty()) {
            StackTreeNode *pStack = getPop();
            switch (pStack->tag) {
                case 0:
                    pStack->tag = 1;
                    flag = 0;
                    p = pStack->value->right;
                    break;
                case 1:
                    p = pop();
                    printf("%d\t", p->value);
                    break;
            }
        }
    } while (!stackIsEmpty());
}

bool push(StackTreeNode *newNode) {
    StackTreeNode *p = stackHead;

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

StackTreeNode *getPop() {
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
    return p;
}

bool stackIsEmpty() {
    if (stackHead->next == NULL) {
        return true;
    }
    return false;
}