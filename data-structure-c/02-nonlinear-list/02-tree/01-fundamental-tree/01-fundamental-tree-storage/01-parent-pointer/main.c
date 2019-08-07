//
// Created by asus on 2019/8/6.
//
#include "parentpointer.h"

int main(int argc, char *argv[]) {

    //初始化数组
    memset(tree, 0, sizeof(TreeNode *) * MAX_SIZE);
//    for (int i = 0; i < MAX_SIZE; ++i) {
//        printf("%p\t", tree[i]);
//    }
//    printf("\n");
//    printf("%p\t", tree[0]);
//    printf("%d\t", tree[0]==NULL);
    createTreeByNodes(0, -1);
    createTreeByNodes(1, 0);
    createTreeByNodes(2, 0);
    createTreeByNodes(3, 0);
    createTreeByNodes(11, 1);
    createTreeByNodes(12, 1);
    createTreeByNodes(13, 1);
    createTreeByNodes(21, 2);
    createTreeByNodes(22, 2);
    createTreeByNodes(23, 2);
    print();
    return 0;
}