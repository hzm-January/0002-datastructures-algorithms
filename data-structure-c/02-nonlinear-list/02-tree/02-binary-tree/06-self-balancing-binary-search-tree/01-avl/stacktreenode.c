//
// Created by asus on 2019/8/10.
//

#include "stacktreenode.h"


bool push(TreeNode *node) {
    StackTreeNode *newnode = (StackTreeNode *) malloc(sizeof(StackTreeNode));
    newnode->value = node;
    newnode->next = NULL;
    if (sentinal == NULL) {
        sentinal = (StackTreeNode *) malloc(sizeof(StackTreeNode));
        sentinal->value = NULL;
        sentinal->next = NULL;
    }
    StackTreeNode *p = sentinal;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newnode;
    return true;
}

TreeNode *pop() {
    if (isEmpty()) {
        return NULL;
    }
    StackTreeNode *p = sentinal;
    while (p->next->next != NULL) {
        p = p->next;
    }
    TreeNode *popvalue = p->next->value;
    free(p->next);
    p->next = NULL;
    return popvalue;
}

bool isEmpty() {
    if (sentinal->next == NULL) {
        return true;
    }
    return false;
}