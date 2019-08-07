//
// Created by asus on 2019/8/6.
//

#include "childlink.h"

// 初始化
void initialize() {
    // 1. 初始化保存每个节点头指针的数组
    memset(treeHeads, 0, sizeof(TreeNode *) * MAX_SIZE);

}

// 销毁
void destroy() {
    for (int i = 0; i < size; ++i) {
        if (treeHeads[i] != NULL) {
            free(treeHeads[i]);
            treeHeads == NULL;
        }
    }
}

void createTreeByNodes(int value, int parentValue) {
    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->datum = value;
    newNode->link = NULL;
    // 因为树种的每个节点都有一个左右子树的链表，都是自己左右子树链表的头指针
    // 1. 所以先将当前节点，插入到数组中，并记录其索引位置
    treeHeads[size++] = newNode;
    if (parentValue == -1) {
        return; //如果是根节点，结束执行
    }
    // 2. 根据入参父节点的值，找到父节点的头指针所在数组的索引位置
    int i = -1;
    for (; i < size && treeHeads[i + 1] != NULL && treeHeads[i + 1]->datum != parentValue; ++i);
    i++;
    if (treeHeads[i] == NULL) {
        printf(" the parent node is not found ");
        exit(1);
    }
    // 3. 遍历链表，直到找到链表的尾节点，构建当前插入节点的链表节点，插入到尾部
    TreeNode *p = treeHeads[i];
    while (p->link != NULL) {
        p = p->link;
    }
    TreeNode *newNodeLink = (TreeNode *) malloc(sizeof(TreeNode));
    newNodeLink->link = NULL;
    newNodeLink->datum = size - 1; //当前节点在头节点向量数组中的索引位置

    p->link = newNodeLink;

}