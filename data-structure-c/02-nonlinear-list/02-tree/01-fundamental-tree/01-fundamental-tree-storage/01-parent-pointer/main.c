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
    save(0, -1);
    save(1, 0);
    save(2, 0);
    save(3, 0);
    save(11, 1);
    save(12, 1);
    save(13, 1);
    save(21, 2);
    save(22, 2);
    save(23, 2);
    print();
    return 0;
}