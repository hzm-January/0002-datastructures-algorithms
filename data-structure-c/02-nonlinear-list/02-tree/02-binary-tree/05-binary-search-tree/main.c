//
// Created by asus on 2019/7/16.
//
#include "binarysearchtree.h"

int main(int argv, char *argc[]) {
    insert(5);
    insert(6);
    insert(4);
    insert(3);
    insert(2);
    insert(8);
    insert(7);
    prePrint(root);
    printf("\n");
//    delete(2);
//    prePrint(root);
//    printf("\n");
//    delete(5);
//    prePrint(root);
//    printf("\n");
    inPrint(root);
    printf("\n");
    printf("max: %d\n", findMax());
    printf("min: %d\n", findMin());
    printf("%d : %d\n", findMax(), findParent(findMax()));
    printf("%d : %d\n", 5, findParent(5));
    printf("%d : %d\n", 5, findParent(12));
//    TreeNode *pNode = find(10);
//    printf("%d\n", pNode->value);
    printf("the height of the tree is : %d\n", high_depth_first(root));
    printf("the height of the tree is : %d\n", high_breadth_first(root));
    print_breadth_first(root);
}
