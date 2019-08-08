//
// Created by asus on 2019/8/7.
//

#include "childbrotherlist.h"
int main(int argc, char * argv[]){

    createTreeByNodes(0, -1);
    createTreeByNodes(1, 0);
    createTreeByNodes(5, 0);
    createTreeByNodes(2, 1);
    createTreeByNodes(21, 2);
    createTreeByNodes(22, 2);

    createTreeByNodes(3, 1);
    createTreeByNodes(4, 1);
    createTreeByNodes(41, 4);
    createTreeByNodes(42, 4);
    preRootPrint(root);
    printf("\n");
    postRootPrint(root);
    printf("\n");
    queuePrint(root);
//    printf("\n");
//    queuePrint(root);
    printf("---\n");
    printf("%d\n", count());
    printf("%d\n", countByPreRoot());
    printf("%d\n", depthByPostRoot());
    return 0;
}