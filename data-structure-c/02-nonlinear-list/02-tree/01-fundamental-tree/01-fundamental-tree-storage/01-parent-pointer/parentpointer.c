//
// Created by asus on 2019/8/6.
//

#include "parentpointer.h"


// 保存节点
void save(int value, int pvalue) {
    if (size == MAX_SIZE) {
        printf("size greater max size");
        exit(1);
    }
    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->value = value;
    if (size == 0) {
        newNode->parent = -1;
        tree[size++] = newNode;
        //tree[0]->parent = -1;
        return;
    }
    //查找父节点索引
    int h = -1;
    for (int i = 0; i < size; ++i) {
        if (tree[i]->value == pvalue) {
            h = i;
            break;
        }
    }
    if (h == -1) {
        printf("%d\n", "the parent is not exist");
        exit(1);
    }
    int j = 0;
    for (; j < size && tree[j]->parent < h && tree[j] != NULL; ++j);
    for (int k = size - 1; k >= j; --k) {
        tree[k + 1] = tree[k];
    }
    newNode->parent = h;
    tree[j] = newNode;
    size++;
}

// 打印所有节点
void print() {
    for (int i = 0; i < size; ++i) {
        if (tree[i] == NULL) {
            break;
        }
        printf("%d|%d\t", tree[i]->value, tree[i]->parent);
    }
}